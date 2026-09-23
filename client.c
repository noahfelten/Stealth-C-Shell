/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nofelten <nofelten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 09:35:42 by nofelten          #+#    #+#             */
/*   Updated: 2026/09/23 10:19:07 by nofelten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main()
{
	int	clientSocket;
	struct	sockaddr_in serverAddress;
	char	buffer[1024];

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket < 0)
		return (1);

	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(8080);

	if (inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr) <= 0)
	{
		printf("Adresse invalide ou non supportée\n");
		close(clientSocket);
		return (1);
	}
	if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
	{
		printf("Échec de la connexion au serveur (est-il bien lancé ?)\n");
		close(clientSocket);
		return (1);
	}

	while (1)
	{
		printf("Ton message : ");
		memset(buffer, 0, sizeof(buffer));

		if (fgets(buffer, sizeof(buffer), stdin) == NULL)
			break;

		send(clientSocket, buffer, strlen(buffer), 0);

		if (strncmp(buffer, "exit", 4) == 0)
		{
			printf("Déconnexion...\n");
			break;
		}
	}

	close(clientSocket);

	return (0);

}
