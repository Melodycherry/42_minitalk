/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:14:54 by mlaffita          #+#    #+#             */
/*   Updated: 2025/02/02 16:30:41 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
	static unsigned char	octet;
	static int				cnt_bit;

	octet |= (signal == SIGUSR1);
	cnt_bit++;
	if (cnt_bit == 8)
	{
		ft_printf("%c", octet);
		cnt_bit = 0;
		octet = 0;
	}
	else
		octet <<= 1;
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	ft_printf("Server PID : %d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
		pause();
	}
	return (0);
}
