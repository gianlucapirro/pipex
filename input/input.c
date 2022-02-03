/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 11:30:24 by gpirro        #+#    #+#                 */
/*   Updated: 2022/02/03 11:28:57 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*check_error(int argc)
{
	if (argc > 5)
		write(2, "Error: too many arguments given\n", 32);
	else if (argc < 5)
		write(2, "Error: not enough arguments given\n", 34);
	else
		return (NULL);
	exit(0);
}

char	**find_directories(char *envp[])
{
	int		i;
	char	*path;
	char	**paths;

	i = 0;
	while (strncmp(envp[i], "PATH", 4) != 0)
		i ++;
	path = ft_strtrim(envp[i], "PATH=");
	paths = ft_split(path, ':');
	return (paths);
}

char	*append_cmd_to_path(char *path, char *cmd)
{
	char	*full_path;

	full_path = ft_strjoin(path, "/");
	full_path = ft_strjoin(full_path, cmd);
	return (full_path);
}

char	*create_full_path(char **paths, char *cmd)
{
	int		i;
	char	**args;

	i = 0;
	args = ft_split(cmd, ' ');
	while (access(append_cmd_to_path(paths[i], args[0]), F_OK) != 0)
		i++;
	return (append_cmd_to_path(paths[i], args[0]));
}
