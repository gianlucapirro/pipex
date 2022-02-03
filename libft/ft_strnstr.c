/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 11:06:44 by gpirro        #+#    #+#                 */
/*   Updated: 2021/10/25 19:32:35 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t nr)
{
	size_t	i;
	size_t	size;

	size = ft_strlen(s2);
	i = 0;
	if (s2[i] == '\0')
		return ((char *)s1);
	if ((int) size > ft_strlen(s1))
		return (NULL);
	while (i < nr)
	{
		if (ft_strncmp(s1 + i, s2, size) == 0)
		{
			if (i + size > nr)
				return (NULL);
			else
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
