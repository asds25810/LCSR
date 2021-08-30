import torch
from torch import nn

# can be more elegant
class Model(nn.Module):
    def __init__(self, input_size, n_input_fields, output_size, lstm_size, embedding_dim, n_layers):
        super(Model, self).__init__()
        self.lstm_size = lstm_size
        self.n_layers = n_layers

        self.embedding = nn.Embedding(
            num_embeddings=input_size,
            embedding_dim=embedding_dim,
        )

        if self.n_layers > 0:
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

            self.fc = nn.Linear(lstm_size, output_size)
        else:
            self.fc = nn.Linear(n_input_fields * embedding_dim, output_size)
        torch.nn.init.xavier_normal_(self.fc.weight.data)
        torch.nn.init.normal_(self.fc.bias.data)

    def forward(self, x, state):
        embed = self.embedding(x.long())
        if self.n_layers > 0:
            output, (state_h, state_c) = self.lstm(torch.reshape(embed, (embed.shape[0], embed.shape[1], -1)), state)
            logits = self.fc(output)
            return logits, (state_h.detach(), state_c.detach())
        else:
            logits = self.fc(torch.reshape(embed, (embed.shape[0], embed.shape[1], -1)))
            return logits, state

    def init_state(self, batch_size, device):
        return (torch.zeros(self.n_layers, batch_size, self.lstm_size).to(device),
                torch.zeros(self.n_layers, batch_size, self.lstm_size).to(device))
