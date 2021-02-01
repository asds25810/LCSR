import torch
from torch import nn


class Model(nn.Module):
    def __init__(self, n_feature_fields, n_features, n_numeric, type=torch.float):
        super(Model, self).__init__()
        self.lstm_size = 32
        self.embedding_dim = 8
        self.num_layers = 2
        self.type = type
        self.n_numeric = n_numeric

        self.embedding = nn.Embedding(
            num_embeddings=n_features-self.n_numeric,
            embedding_dim=self.embedding_dim,
        )

        self.lstm = nn.LSTM(
            input_size=(n_feature_fields - self.n_numeric) * self.embedding_dim + self.n_numeric,
            hidden_size=self.lstm_size,
            num_layers=self.num_layers,
            batch_first=True,
            # dropout=0.2
        )
        for param in self.lstm.parameters():
            if len(param.shape) >= 2:
                torch.nn.init.orthogonal_(param.data)
            else:
                torch.nn.init.normal_(param.data)
        self.fc = nn.Linear(self.lstm_size, n_features)
        torch.nn.init.xavier_normal_(self.fc.weight.data)
        torch.nn.init.normal_(self.fc.bias.data)

        # self.fc2 = nn.Linear(100, n_features)
        # torch.nn.init.xavier_normal_(self.fc2.weight.data)
        # torch.nn.init.normal_(self.fc2.bias.data)

    def forward(self, x, prev_state):
        categorical_x = x[:, :, 0:-self.n_numeric].long()
        numeric_x = x[:, :, -self.n_numeric:]
        embed = self.embedding(categorical_x)
        output = torch.cat([torch.reshape(embed, (embed.shape[0], embed.shape[1], -1)), numeric_x], dim=2)

        output, state = self.lstm(output, prev_state)
        logits = self.fc(output)
        # logits = self.fc2(torch.relu(self.fc(output)))

        return logits, state

    def init_state(self, batch_size):
        return (torch.zeros(self.num_layers, batch_size, self.lstm_size, dtype=self.type),
                torch.zeros(self.num_layers, batch_size, self.lstm_size, dtype=self.type))