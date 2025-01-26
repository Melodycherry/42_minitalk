/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaffita <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:09:14 by mlaffita          #+#    #+#             */
/*   Updated: 2024/11/06 15:24:31 by mlaffita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_int(unsigned int u, int *len)
{
	if (u >= 10)
		ft_unsigned_int(u / 10, len);
	ft_putchar_len(u % 10 + '0', len);
}
