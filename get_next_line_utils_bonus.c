/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:27:07 by thjacque          #+#    #+#             */
/*   Updated: 2020/11/30 08:27:05 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, char c)
{
	int		i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return ((char *)&s[i]);
	return (NULL);
}

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = 0;
	return (dest);
}

char	*ft_strdup(char *s)
{
	char	*ptr;
	int		i;

	i = -1;
	if (!(ptr = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	while (s[++i])
		ptr[i] = s[i];
	ptr[i] = 0;
	return (ptr);
}

char	*ft_substr(char *str, unsigned int start, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;
	char			*newstr;

	i = 0;
	j = ft_strlen(str);
	if (start >= j || j == 0)
		return (ft_strdup(""));
	count = start - j;
	if (count > len)
		count = len;
	if (!(newstr = malloc((count + 1) * sizeof(char))))
		return (NULL);
	while (len--)
		newstr[i++] = str[start++];
	newstr[i] = 0;
	return (newstr);
}
