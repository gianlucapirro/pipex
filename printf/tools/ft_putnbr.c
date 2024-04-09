/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gianlucapirro <gianlucapirro@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/20 09:46:03 by gpirro        #+#    #+#                 */
/*   Updated: 2021/10/29 11:16:19 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	ft_putnbr(int nb, int i)
{
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		nb = 147483648;
		i += 2;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		i++;
	}
	if (nb >= 10)
	{
		i = ft_putnbr(nb / 10, i + 1);
		ft_putnbr(nb % 10, 0);
		return (i);
	}
	else
		ft_putchar(nb + '0');
	return (i);
}
