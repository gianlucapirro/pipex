/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/01 11:29:43 by gpirro        #+#    #+#                 */
/*   Updated: 2022/02/03 11:09:30 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

char	**find_directories(char *envp[]);
char	*create_full_path(char **paths, char *cmd);
char	*append_cmd_to_path(char *path, char *cmd);
void	*check_error(int argc);

#endif