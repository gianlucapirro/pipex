/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   void_to_hex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gianlucapirro <gianlucapirro@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 18:07:13 by gianlucapir   #+#    #+#                 */
/*   Updated: 2021/10/29 11:18:26 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*handle_zero2(char *new)
{
	new[0] = '0';
	new[1] = 'x';
	new[2] = '0';
	new[3] = 0;
	return (new);
}

char	*void_to_hex(void *ptr, int i)
{
	unsigned long	number;
	long			temp;
	char			*new;

	number = (long)ptr;
	new = (char *)malloc(sizeof(char) * 18);
	if (!new)
		return (0);
	i = 0;
	if ((char *)ptr == 0)
		return (handle_zero2(new));
	while (number != 0)
	{
		temp = 0;
		temp = number % 16;
		if (temp < 10)
			new[i++] = temp + 48;
		else
			new[i++] = temp + 55;
		number /= 16;
	}
	new[i] = 'x';
	new[i + 1] = '0';
	new[i + 2] = '\0';
	return (ft_rev_int_tab(new, ft_strlen(new)));
}
