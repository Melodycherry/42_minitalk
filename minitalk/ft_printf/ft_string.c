/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:09:10 by mlaffita          #+#    #+#             */
/*   Updated: 2024/11/06 15:48:56 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_string(char *str, int *len)
{
	size_t	i;

	i = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		(*len) = (*len) + 6;
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar_len(str[i], len);
		i++;
	}
}
