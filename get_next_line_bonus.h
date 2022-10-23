/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lporras- <lporras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:54:48 by lporras-          #+#    #+#             */
/*   Updated: 2022/10/23 13:29:20 by lporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

# include<stdio.h>
# include<unistd.h>
# include<ctype.h>
# include<stdlib.h> 
# include<string.h>
# include<stddef.h>
# include<sys/types.h>
# include<sys/stat.h>
# include <fcntl.h> 
# include<errno.h>
# include <stdarg.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *str);

# define FILES_MAX 4096

size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif