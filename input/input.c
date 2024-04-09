/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 11:30:24 by gpirro        #+#    #+#                 */
/*   Updated: 2022/02/28 20:07:33 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**get_paths(char *envp[])
{
	int		i;
	char	*path;
	char	**paths;

	if (envp == NULL)
		exit_error(EXIT_FAILURE, "envp is empty");
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	path = ft_strtrim(envp[i], "PATH=");
	if (path == NULL)
		exit_error(EXIT_FAILURE, "strtrim returned NULL");
	paths = ft_split(path, ':');
	if (paths == NULL)
		exit_error(EXIT_FAILURE, "split returned NULL");
	free(path);
	return (paths);
}

char	*append_cmd_to_path(char *path, char *cmd)
{
	char	*fullPath;
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	if (tmp == NULL)
		exit_error(EXIT_FAILURE, "strjoin failed");
	fullPath = ft_strjoin(tmp, cmd);
	free(tmp);
	if (fullPath == NULL)
		exit_error(EXIT_FAILURE, "strjoin failed");
	return (fullPath);
}

static int	find_amount_of_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
		i++;
	return (i);
}

char	*find_exec_path(char **paths, char *cmd)
{
	int		i;
	char	*path;
	char	*exec;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	if (paths == NULL)
		exit_error(EXIT_FAILURE, "PATHS is empty");
	exec = ft_split_first(cmd, ' ');
	i = -1;
	while (paths[++i])
	{
		path = append_cmd_to_path(paths[i], exec);
		if (access(path, X_OK) == 0)
			break ;
		free(path);
	}
	if (i == find_amount_of_paths(paths) && (access(path, X_OK) != 0))
		exit_error(EXIT_FAILURE, "Could not find executable path");
	free(exec);
	return (path);
}
