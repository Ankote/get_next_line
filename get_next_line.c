/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:09:12 by aankote           #+#    #+#             */
/*   Updated: 2022/11/08 19:09:14 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"


void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
  	size_t i;

  i = 0;
	if (count && size > SIZE_MAX / count)
		return (0);
	ptr = (char *)malloc(count * size);
	if (ptr)
	{
		while (ptr[i] && i < size * count)
      		ptr[i] = 0;
		return (ptr);
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_free(char *buff,char *buf)
{
	char *temp;

	temp = ft_strjoin(buff,buf);
	free(buff);
	return (temp);
}


char *get_read(int fd, char *res)
{
   char *buff;
   int i;

   i = 1;
   if (!res)
	ft_calloc(1, 1);
   buff = ft_calloc(BUFFER_SIZE + 1, 1);
   while (i > 0 )
   {
		i = read(fd, buff, BUFFER_SIZE); 
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		res = ft_free(res, buff);
		if(ft_strchr(buff, '\n'))
			break;
	}
	free(buff);
	return (res);
}

char *get_line(char *buff)
{
	char *line;
	int i;

	i = 0;
	if (!buff[i])
		return (0);
	while ((buff[i] && buff[i] != '\n'))
		i++;
	line = ft_calloc(i + 2, 1);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i ++;
	}
	if(buff[i] && buff[i] == '\n')
		line[i++] ='\n';
	line[i] = '\0';
	return (line);
}

char *get_next(char *buffer)
{
	int i;
	int j;
	char *line;

	i = 0;
	while(buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	line = ft_calloc(ft_strlen(buffer) - i + 1,1);
	//skep \n
	i ++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *line;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0 ,0 ) < 0)
		return (0);
	buffer = get_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = get_next(buffer);
	return(line);
}
