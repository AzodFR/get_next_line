/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <marvin@r42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:56:24 by thjacque          #+#    #+#             */
/*   Updated: 2020/11/10 19:09:15 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		checkparams(int fd, char **line, char **actual, int *nb)
{
	int		i;

	if (fd < 0 || !line)
		return (-1);
	if (!*nb)
		(*nb) = 1;
	if (!(*actual))
		if (!((*actual) = malloc((BUFFER_SIZE * (*nb)++ + 1) * sizeof(char))))
			return (-1);
	return (0);
}

int		newline(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

char	*ft_strcpy(char *dest, char *src)
{
		int		i;

		i = 0;
		while (src[i])
		{
				dest[i] = src[i];
				i++;
		}
		dest[i] = '\0';
		return (dest);
}

char    *ft_strncat(char *dest, char *src, unsigned int nb)
{
        unsigned int            i;
        unsigned int            j;

        i = 0;
        j = 0;
        while (dest[i])
                i++;
        while (src[j] && j < nb)
        {
                dest[j + i] = src[j];
                j++;
        }
        dest[j + i] = '\0';
        return (dest);
}
