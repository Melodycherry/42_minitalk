/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:14:54 by mlaffita          #+#    #+#             */
/*   Updated: 2025/01/26 19:24:46 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal)
{
	int cnt = 0;
	cnt++;
	
}

int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ft_printf("Server PID : %d", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
		pause();
	}
	return(0); 
}