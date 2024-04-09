/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/04 13:22:04 by gpirro        #+#    #+#                 */
/*   Updated: 2021/10/28 11:25:19 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*array;
	int		total;

	total = count * size;
	if (total == 0)
		total = 1;
	array = malloc(total);
	if (!array)
		return (NULL);
	ft_memset(array, 0, total);
	return (array);
}
