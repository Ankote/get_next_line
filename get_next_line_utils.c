/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:26:29 by aankote           #+#    #+#             */
/*   Updated: 2022/11/09 10:26:31 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (copy)
	{
		ft_strlcpy(copy, s1, len + 1);
		return (copy);
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	unsigned int	st;
	unsigned int	i;
	char			*substr;

	i = 0;
	st = start;
	if (s == NULL)
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start < len)
	{
		substr = (char *)malloc((ft_strlen(s) - start + 1));
		len = ft_strlen(s) - start;
	}
	else
		substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr)
	{
		while (s[st] && st < len + start)
			substr[i++] = s[st++];
		substr[i] = '\0';
		return (substr);
	}
	return (0);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if ((char)c == 0)
		return ((char *)s + ft_strlen(s));
	while (i < ft_strlen(s))
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (src != NULL)
	{
		while (src[i] && i < dstsize - 1 && dstsize > 0)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	size_t	total_size;
	char	*newstr;

	i = 0;
	j = 0;
	if (!s1)
	{
		newstr = malloc(ft_strlen(s2));
		
		return ((char *)s2);
	}
	total_size = ft_strlen(s1) + ft_strlen(s2);
	newstr = malloc(sizeof(char) * (total_size + 1));
	if (!newstr)
		return (0);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[j])
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	return (newstr);
}

