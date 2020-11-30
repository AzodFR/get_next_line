/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:27:10 by thjacque          #+#    #+#             */
/*   Updated: 2020/11/30 08:31:42 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_strdel(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

char	*joinnfree(char *str1, char *str2)
{
	char	*newstr;
	int		i;
	int		j;

	if (!str1 || !str2)
		return (NULL);
	i = ft_strlen(str1);
	j = ft_strlen(str2);
	if (!(newstr = malloc((i + j + 1) * sizeof(char))))
		return (NULL);
	j = -1;
	ft_strcpy(newstr, str1);
	while (str2[++j])
		newstr[i++] = str2[j];
	free(str1);
	newstr[i] = 0;
	return (newstr);
}

char	*forward(char *rest, char **line, int *eof)
{
	char				*tmp;
	unsigned int		i;

	i = 0;
	if (rest && rest[i])
	{
		while (rest[i] != '\n' && rest[i])
			i++;
		if (rest[i] == '\n')
		{
			*line = (i == 0) ? ft_strdup("") : ft_substr(rest, 0, i);
			tmp = ft_strdup(rest + i + 1);
			ft_strcpy(rest, tmp);
			ft_strdel(&tmp);
			return (*line);
		}
		else
		{
			*line = (i == 0) ? ft_strdup("") : ft_substr(rest, 0, i);
			*eof = 1;
			return (*line);
		}
	}
	*eof = 1;
	return (ft_strdup(""));
}

char	*get_actual_line(char *buffer, char **rest, int fd)
{
	int		i;
	char	*temp;

	while ((i = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
		if (i < 0)
			return ((char *)-1);
		if (!rest[fd])
			if (!(rest[fd] = ft_strdup("")))
				return ((char *)-1);
		buffer[i] = 0;
		if (!(temp = joinnfree(rest[fd], buffer)))
			return ((char *)-1);
		rest[fd] = temp;
		if (ft_strchr(rest[fd], '\n'))
			break ;
	}
	return (rest[fd]);
}

int		get_next_line(int fd, char **line)
{
	static char		*rest[4096];
	char			buffer[BUFFER_SIZE + 1];
	int				eof;

	eof = 0;
	if (fd < 0 || read(fd, buffer, 0) < 0 || !line || BUFFER_SIZE < 1)
	{
		*line = NULL;
		return (-1);
	}
	if ((rest[fd] = get_actual_line(buffer, rest, fd)) == (char *)-1)
	{
		*line = NULL;
		return (-1);
	}
	*line = forward(rest[fd], line, &eof);
	if (eof == 1)
		ft_strdel(&rest[fd]);
	return (eof != 1);
}
