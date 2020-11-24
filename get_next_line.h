/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <marvin@r42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:54:25 by thjacque          #+#    #+#             */
/*   Updated: 2020/11/10 19:09:22 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		checkparams(int fd, char **line, char **actual, int *nb);
int		newline(char *str);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
char	*ft_strcpy(char *dest, char *src);
#endif
