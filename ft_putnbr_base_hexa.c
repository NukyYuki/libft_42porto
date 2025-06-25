/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipinhei <mipinhei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:49:48 by mipinhei          #+#    #+#             */
/*   Updated: 2025/05/21 16:16:07 by mipinhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hex(unsigned int nb, char *base)
{
	int		count;

	count = 0;
	if (nb > ((unsigned)ft_strlen(base) - 1))
		count += ft_putnbr_hex(nb / (ft_strlen(base)), base);
	count += ft_putchar(base[nb % (ft_strlen(base))]);
	return (count);
}
