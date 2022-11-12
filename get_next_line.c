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

static int	newlineindex(const char *s)
{
	int i;

    i = 0;

	while (s[i] != '\n')
	{
		i++;
	}
	return (i);
}

char *get_read(int fd)
{
   static char *line;
   char *buff;
   char *s;
   int i;

   i = 1;
   s = calloc(1,1);
   while (i > 0 && ft_strchr(s, '\n') == 0)
   {
      buff = malloc(BUFFER_SIZE);
      i = read(fd,buff,BUFFER_SIZE); 
      s = ft_strdup(ft_strjoin(s, buff));
     
      if (buff)
        free(buff);
   }
   line = ft_strchr(s, '\n');
   printf("%s|\n",line);
   return (ft_substr(s,0,newlineindex(s)));
}
/*

lislfgilsrvwrfwrgnvl lisnrlfvs lsfrilgvslfnlsrfn ilinlrsf\n
rifeeeeelsli;sr slrinlsr ,inilrfl;s jslnrfnlsi liisnrfnil\n
jler;o;o;nir llif;sFKR lor;vo;srfvbkl kjrsnflslr hmlsrilv\n
snkllf; ilrsnvlsl jnirofosor; iknrvron klsnrili  rsufjbvs\n
eesrlsibl/ j,ilsrivnsl visfivisr isrvhri rslvisrivb rsils\n
bfl kusbrklfb mrbkusrb kfbukrbfks kmrß˙rrhlaelf klilrkfs\





*/
char *get_next_line(int fd)
{
  return(get_read(fd));
}
