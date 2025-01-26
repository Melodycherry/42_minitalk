/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:08:58 by mlaffita          #+#    #+#             */
/*   Updated: 2024/11/06 15:23:46 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_number(int nbr, int *len)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) = (*len) + 11;
		return ;
	}
	if (nbr > 9)
	{
		ft_number(nbr / 10, len);
		ft_number(nbr % 10, len);
	}
	else if (nbr >= 0 && nbr <= 9)
	{
		ft_putchar_len(nbr + '0', len);
	}
	else if (nbr < 0)
	{
		ft_putchar_len('-', len);
		ft_number(nbr * -1, len);
	}
}
