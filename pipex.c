/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 11:17:45 by gpirro        #+#    #+#                 */
/*   Updated: 2022/02/03 12:55:54 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	close_pipe(int	*pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
}

static void	child_process(int pipefd[], char *argv[], char *envp[], int	in_out)
{
	int	fd;

	if (in_out == 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			exit(0);
		dup2(fd, STDIN_FILENO);
		dup2(pipefd[1], STDOUT_FILENO);
		close_pipe(pipefd);
		execve(create_full_path(find_directories(envp), argv[2]), \
		ft_split(argv[2], ' '), envp);
	}
	else
	{
		fd = open(argv[4], O_RDWR | O_CREAT);
		if (fd == -1)
			exit(0);
		dup2(pipefd[0], STDIN_FILENO);
		dup2(fd, STDOUT_FILENO);
		close_pipe(pipefd);
		execve(create_full_path(find_directories(envp), argv[3]), \
		ft_split(argv[3], ' '), envp);
	}
}

static int	pipex(char *envp[], char *argv[])
{
	int	pipefd[2];
	int	pid1;
	int	pid2;

	if (pipe(pipefd) == -1)
		return (-1);
	pid1 = fork();
	if (pid1 < 0)
		return (-1);
	if (pid1 == 0)
		child_process(pipefd, argv, envp, 0);
	pid2 = fork();
	if (pid2 < 0)
		return (-1);
	if (pid2 == 0)
		child_process(pipefd, argv, envp, 1);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{	
	check_error(argc);
	return (pipex(envp, argv));
}
