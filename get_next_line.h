/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:27:04 by thjacque          #+#    #+#             */
/*   Updated: 2020/12/01 10:11:41 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

int				ft_strlen(char *s);
char			*ft_strchr(char *s, char c);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(char *s);
char			*ft_substr(char *str, unsigned int start, unsigned int len);
int				get_next_line(int fd, char **line);
#endif
