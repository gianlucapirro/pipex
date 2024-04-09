/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 13:01:48 by gpirro        #+#    #+#                 */
/*   Updated: 2022/02/28 19:25:56 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_struct(t_paths *path)
{
	int	i;

	i = 0;
	free(path->pathin);
	free(path->pathout);
	while (path->paths[i])
	{
		free(path->paths[i]);
		i++;
	}
	free(path->paths);
	i = -1;
	while (path->cmdsin[++i])
		free(path->cmdsin[i]);
	free(path->cmdsin);
	i = -1;
	while (path->cmdsout[++i])
		free(path->cmdsout[i]);
	free(path->cmdsout);
}

t_paths	paths_init(char *envp[], char *argv[], t_paths *path)
{
	path->paths = get_paths(envp);
	path->pathin = find_exec_path(path->paths, argv[2]);
	if (path->pathin == 0)
		exit_error(EXIT_FAILURE, "strdup failed");
	path->pathout = find_exec_path(path->paths, argv[3]);
	if (path->pathout == 0)
		exit_error(EXIT_FAILURE, "strdup failed");
	return (*path);
}

void	cmds_init(char *argv, char ***cmd)
{
	char	**tmp;
	int		i;

	tmp = ft_split(argv, ' ');
	*cmd = malloc(sizeof(char *) * (ft_get2dlength(tmp) + 1));
	if (*cmd == NULL)
		exit_error(EXIT_FAILURE, "malloc failed");
	i = -1;
	while (tmp[++i])
	{
		(*cmd)[i] = ft_strtrim(tmp[i], "\'");
		if ((*cmd)[i] == NULL)
			exit_error(EXIT_FAILURE, "Strtrim fails");
		free(tmp[i]);
	}
	(*cmd)[i] = 0;
	free(tmp);
}

void	close_pipe(int	*pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
}

void	exit_error(int errorcode, char *msg)
{
	ft_printf("Error: %s\n", msg);
	exit(errorcode);
}
