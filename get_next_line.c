/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <marvin@r42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:56:27 by thjacque          #+#    #+#             */
/*   Updated: 2020/11/10 19:13:39 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*getline(int fd,char *actual)
{
	char	buffer[BUFFER_SIZE + 1];
	int		i;
	int		j;

	j = 0;
	while (read(fd, buffer, BUFFER_SIZE))
	{
		i = newline(buffer);
		if (i != -1)
		{
			ft_strncat(actual, buffer, BUFFER_SIZE + 1);
			return (actual);
		}
		ft_strncat(actual, buffer, BUFFER_SIZE + 1);

	}
	return (NULL);
}

int 	get_next_line(int fd, char **line)
{
	static char *actual;
	static int	j;
	int			i;

	if (checkparams(fd, line, &actual, &j) < 0)
		return (-1);
	if ((*actual))
		ft_strcpy((*line), actual);
	actual = getline(fd, actual);
	if (actual == NULL)
		return (0);
	i = 0;
	if(actual[i])
	{
		while (actual[i] != '\n' && actual[i])
			i++;
		actual[i] = 0;
		ft_strcpy((*line), actual);
		actual = &actual[i + 1];
		return (1);
	}
	ft_strcpy((*line), "");
	return (0);
}

int main (int ac, char **av){
	char *line;
	int fd;

	if(!(line = malloc(BUFFER_SIZE + 1)))
		return (1);
	fd = (ac == 2) ? open(av[1], O_RDONLY) : 0;
	while (get_next_line(fd, &line) > 0)
		printf("%s\n", line);
	free (line);
}
