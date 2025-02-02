/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:09:08 by mlaffita          #+#    #+#             */
/*   Updated: 2025/02/02 17:00:05 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = character;// copie le char dans une variable temporaire
	while (i > 0)
	{
		i--;
		temp_char = character >> i;// decale a droite pour obtenir le bit a la pos i 
		if (temp_char % 2 == 0)// verif si le bit a pos i est 0 ou 1
			kill(pid, SIGUSR2);
		else
			kill (pid, SIGUSR1);
		usleep(500);// doit attendre avant prochain signal 
	}
}

int	main(int argc, char *argv[])
{
	int		pid_client;
	char	*str;
	int		i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Error : usage = ./client <pid> <str>");
		exit(EXIT_FAILURE);
	}
	pid_client = ft_atoi(argv[1]);
	str = argv[2];
	while (str[i])
		send_signal(pid_client, (unsigned char) str[i++]);
	exit (EXIT_SUCCESS);
}
