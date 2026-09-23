/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofelten <nofelten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 20:39:02 by nofelten          #+#    #+#             */
/*   Updated: 2026/09/23 10:18:40 by nofelten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main()
{
	int	serverSocket;
	int	clientSocket;
	char	buffer[1024];
	struct	sockaddr_in serverAddress;

	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket < 0)
		return (1);

	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(8080);
	serverAddress.sin_addr.s_addr = INADDR_ANY;

	if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
	{
		close(serverSocket);
		return (1);
	}
	if (listen(serverSocket, 5) < 0)
	{
		close(serverSocket);
		return (1);
	}

	clientSocket = accept(serverSocket, NULL, NULL);

	while (1)
	{
		memset(buffer, 0, sizeof(buffer));

		int bytes_received = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);

		if (bytes_received <= 0)
		{
			printf("Client déconnecté.\n");
			break; 
		}

		printf("Client : %s", buffer);

		if (strncmp(buffer, "exit", 4) == 0)
		{
			printf("Fermeture demandée.\n");
			break;
		}
	}

	close(serverSocket);
	close(clientSocket);

	return (0);
}
