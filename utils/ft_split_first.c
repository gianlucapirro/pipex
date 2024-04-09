/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_last.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 18:51:28 by gianlucapir   #+#    #+#                 */
/*   Updated: 2022/02/28 20:00:07 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../pipex.h"

char	*ft_split_first(char const *s, char c)
{
	int		i;
	char	**exec;
	char	*res;

	exec = ft_split(s, c);
	if (exec == NULL)
		exit_error(EXIT_FAILURE, "klaar meee");
	i = 1;
	while (exec[i])
	{
		free(exec[i]);
		i++;
	}
	res = exec[0];
	free(exec);
	return (res);
}
