/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 17:36:28 by gianlucapir   #+#    #+#                 */
/*   Updated: 2022/02/28 17:54:22 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../../pipex.h"

int				ft_printf(const char *format, ...);
int				ft_putstr(char *str, int should_i_free);
int				ft_putchar(int c);
int				ft_putnbr(int nb, int i);
int				ft_putnbru(unsigned int nb, int i);
void			*ft_calloc(size_t count, size_t size);
char			*ft_rev_int_tab(char *tab, int size);
char			*strlowcase(char *str);
char			*void_to_hex(void *string, int i);
char			*int_to_hex(unsigned int number);
char			*ft_memset(void *string, int character, int len);

#endif