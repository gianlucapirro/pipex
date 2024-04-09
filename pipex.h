/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 11:29:43 by gpirro        #+#    #+#                 */
/*   Updated: 2022/02/28 19:13:33 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "printf/includes/ft_printf.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "utils/libft.h"

typedef struct s_paths
{
	char	**paths;
	char	*pathin;
	char	*pathout;
	char	**cmdsin;
	char	**cmdsout;
}	t_paths;

char	**get_paths(char *envp[]);
void	exit_error(int errorcode, char *msg);
char	*append_cmd_to_path(char *path, char *cmd);
char	*find_exec_path(char **paths, char *cmd);
void	close_pipe(int	*pipefd);
t_paths	paths_init(char *envp[], char *argv[], t_paths *path);
void	cmds_init(char *argv, char ***cmd);
void	free_struct(t_paths *path);

#endif