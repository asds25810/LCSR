import torch
from torch import nn

# can be more elegant
class Model(nn.Module):
    def __init__(self, input_size, n_input_fields, output_event_size, output_time_size, lstm_size, embedding_dim, n_layers):
        super(Model, self).__init__()
        self.lstm_size = lstm_size
        self.n_layers = n_layers

        self.embedding = nn.Embedding(
            num_embeddings=input_size,
            embedding_dim=embedding_dim,
        )

        self.lstm = nn.LSTM(
            input_size=n_input_fields * embedding_dim,
            hidden_size=lstm_size,
            num_layers=n_layers,
            batch_first=True
        )
        for param in self.lstm.parameters():
            if len(param.shape) >= 2:
                torch.nn.init.orthogonal_(param.data)
            else:
                torch.nn.init.normal_(param.data)

        self.fc = nn.Linear(lstm_size, output_event_size)
        torch.nn.init.xavier_normal_(self.fc.weight.data)
        torch.nn.init.normal_(self.fc.bias.data)

        self.fc2 = nn.Linear(n_input_fields * embedding_dim, output_time_size)
        torch.nn.init.xavier_normal_(self.fc2.weight.data)
        torch.nn.init.normal_(self.fc2.bias.data)

    def forward(self, x, state):
        embed = self.embedding(x.long())
        embed = torch.reshape(embed, (embed.shape[0], embed.shape[1], -1))
        output, (state_h, state_c) = self.lstm(embed, state)
        logits_event = self.fc(output)
        logits_time = self.fc2(embed.detach())
        return logits_event, logits_time, (state_h.detach(), state_c.detach())

    def init_state(self, batch_size, device):
        return (torch.zeros(self.n_layers, batch_size, self.lstm_size).to(device),
                torch.zeros(self.n_layers, batch_size, self.lstm_size).to(device))
