/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 11:17:45 by gpirro        #+#    #+#                 */
/*   Updated: 2022/02/28 19:31:18 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process_write(int *pipefd, char *argv[], \
char *envp[], t_paths path)
{
	int		fd;

	fd = open(argv[1], O_RDONLY, 0644);
	if (fd < 0)
		exit_error(EXIT_FAILURE, "could not open file");
	dup2(fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close_pipe(pipefd);
	close(fd);
	if (execve(path.pathin, path.cmdsin, envp) < 0)
		exit_error(EXIT_FAILURE, "could not execute cmd");
}

void	child_process_read(int *pipefd, char *argv[], \
char *envp[], t_paths path)
{
	int		fd;

	fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		exit_error(EXIT_FAILURE, "could not write to | clear | create file");
	dup2(fd, STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
	close_pipe(pipefd);
	close(fd);
	if (execve(path.pathout, path.cmdsout, envp) < 0)
		exit_error(EXIT_FAILURE, "could not execute cmd");
}

int	pipex(char *argv[], char *envp[], t_paths path)
{
	int	pid1;
	int	pid2;
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		exit_error(EXIT_FAILURE, "pipe failed");
	pid1 = fork();
	if (pid1 < 0)
		exit_error(EXIT_FAILURE, "pid1 error");
	if (pid1 == 0)
		child_process_write(pipefd, argv, envp, path);
	pid2 = fork();
	if (pid2 < 0)
		exit_error(EXIT_FAILURE, "pid1 error");
	if (pid2 == 0)
		child_process_read(pipefd, argv, envp, path);
	close_pipe(pipefd);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{	
	t_paths	path;

	if (argc != 5)
		exit_error(EXIT_FAILURE, "please use pipex like this \"infile\
 cmd1 cmd2 outfile\"");
	path = paths_init(envp, argv, &path);
	cmds_init(argv[2], &(path.cmdsin));
	cmds_init(argv[3], &(path.cmdsout));
	pipex(argv, envp, path);
	free_struct(&path);
	return (0);
}
