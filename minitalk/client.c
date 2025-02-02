/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 13:09:08 by mlaffita          #+#    #+#             */
/*   Updated: 2025/02/02 16:26:07 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = character;
	while (i > 0)
	{
		i--;
		temp_char = character >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill (pid, SIGUSR1);
		usleep(500);
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
