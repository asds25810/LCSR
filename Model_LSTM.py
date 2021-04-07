import torch
from torch import nn


class Model(nn.Module):
    def __init__(self, n_feature_fields, n_features, type=torch.float):
        super(Model, self).__init__()
        self.lstm_size = 32
        self.embedding_dim = 8
        self.num_layers = 2
        self.type = type

        self.embedding = nn.Embedding(
            num_embeddings=n_features,
            embedding_dim=self.embedding_dim,
        )

        self.lstm = nn.LSTM(
            input_size=n_feature_fields * self.embedding_dim,
            hidden_size=self.lstm_size,
            num_layers=self.num_layers,
            batch_first=True
        )
        for param in self.lstm.parameters():
            if len(param.shape) >= 2:
                torch.nn.init.orthogonal_(param.data)
            else:
                torch.nn.init.normal_(param.data)
        self.fc = nn.Linear(self.lstm_size, n_features)
        torch.nn.init.xavier_normal_(self.fc.weight.data)
        torch.nn.init.normal_(self.fc.bias.data)

    def forward(self, x, prev_state):
        embed = self.embedding(x.long())
        output, state = self.lstm(torch.reshape(embed, (embed.shape[0], embed.shape[1], -1)), prev_state)
        logits = self.fc(output)
        return logits, state

    def init_state(self, batch_size):
        return (torch.zeros(self.num_layers, batch_size, self.lstm_size, dtype=self.type),
                torch.zeros(self.num_layers, batch_size, self.lstm_size, dtype=self.type))
