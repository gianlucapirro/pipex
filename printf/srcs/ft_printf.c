/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gpirro@student.42   		+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:39:22 by gianlucapir       #+#    #+#             */
/*   Updated: 2021/10/19 10:39:22 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	check_format(va_list args, char *string, int i, int retval)
{
	int		p;
	char	*s;

	if (string[i] == 'c' || string[i] == 'u' || string[i] == 'i' || \
	string[i] == 'd' || string[i] == 'x' || string[i] == 'X')
		p = va_arg(args, int);
	if (string[i] == 's' || string[i] == 'p')
		s = va_arg(args, char *);
	if (string[i] == 'c')
		retval = ft_putchar(p);
	else if (string[i] == 's')
		retval = ft_putstr(s, 0);
	else if (string[i] == 'p')
		retval = ft_putstr(strlowcase(void_to_hex(s, 0)), 1);
	else if (string[i] == 'u')
		retval = ft_putnbru(p, 1);
	else if (string[i] == 'd' || string[i] == 'i')
		retval = ft_putnbr(p, 1);
	else if (string[i] == 'x')
		retval = ft_putstr(strlowcase(int_to_hex(p)), 1);
	else if (string[i] == 'X')
		retval = ft_putstr(int_to_hex(p), 1);
	else if (string[i] == '%')
		retval = ft_putchar('%');
	return (retval);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*string;
	int		i;
	int		retval;

	i = 0;
	string = (char *)format;
	va_start(args, format);
	retval = 0;
	while (string[i])
	{
		if (string[i] != '%')
			retval += ft_putchar(string[i]);
		else
		{
			i++;
			retval += check_format(args, string, i, retval);
		}
		i++;
	}
	va_end(args);
	return (retval);
}
