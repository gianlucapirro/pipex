/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/16 11:28:18 by gpirro        #+#    #+#                 */
/*   Updated: 2022/02/28 15:33:44 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putstr(char *str, int should_i_free)
{
	int	i;

	i = 0;
	if (str == 0)
		return (write(2, "(null)", 6));
	while (str[i])
	{
		write(2, str + i, 1);
		i++;
	}
	if (should_i_free)
		free(str);
	return (i);
}
