/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhandou <yrhandou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:59:30 by yrhandou          #+#    #+#             */
/*   Updated: 2024/12/19 12:15:35 by yrhandou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	char	*temp;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	temp = str;
	while (*s1)
		*temp++ = *s1++;
	while (*s2)
		*temp++ = *s2++;
	*temp = '\0';
	return (str);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	i;
	size_t	len;

	i = 0;
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	dup = malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	while (len > i)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(&s[i]));
	return (NULL);
}
