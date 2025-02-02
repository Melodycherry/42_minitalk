/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:14:54 by mlaffita          #+#    #+#             */
/*   Updated: 2025/02/02 20:06:54 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
	static unsigned char	octet = '\0';// sert a construire le char a partir des bits
	static int				cnt_bit = 0;// compteur de bits ( combien ont ete recu pour cet octet)

	octet = octet | (signal == SIGUSR1);// bit recu ajoute a l'octet en construction
	// Si le signal est SIGUSR1, le bit le plus faible de octet devient 1
	// Si le signal est SIGUSR2, le bit le plus faible de octet reste 0
	cnt_bit++;
	if (cnt_bit == 8)
	{
		ft_printf("%c", octet);
		cnt_bit = 0;
		octet = '\0';
	}
	else
		octet = octet << 1;// on decale a gauche pour faire de la place pour le prochain 
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
