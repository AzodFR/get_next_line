/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:27:04 by thjacque          #+#    #+#             */
/*   Updated: 2020/11/30 08:35:06 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int				ft_strlen(char *s);
char			*ft_strchr(char *s, char c);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(char *s);
char			*ft_substr(char *str, unsigned int start, unsigned int len);
int				get_next_line(int fd, char **line);
#endif