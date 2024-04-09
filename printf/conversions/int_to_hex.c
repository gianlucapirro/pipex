/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int_to_hex.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gianlucapirro <gianlucapirro@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 18:07:13 by gianlucapir   #+#    #+#                 */
/*   Updated: 2021/10/29 11:12:03 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*handle_zero(char *new)
{
	new[0] = '0';
	new[1] = 0;
	return (new);
}

char	*int_to_hex(unsigned int number)
{
	char	*new;
	int		temp;
	int		i;

	new = (char *)ft_calloc(10, sizeof(char));
	if (!new)
		return (0);
	if (number == 0)
		return (handle_zero(new));
	i = 0;
	while (number != 0)
	{
		temp = 0;
		temp = number % 16;
		if (temp < 10)
			new[i] = temp + 48;
		else
			new[i] = temp + 55;
		i++;
		number /= 16;
	}
	return (ft_rev_int_tab(new, ft_strlen(new)));
}
