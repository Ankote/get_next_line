/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:31:13 by aankote           #+#    #+#             */
/*   Updated: 2022/11/15 17:31:15 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize);
char *get_next_line(int fd);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strdup(const char *s1);
size_t ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_substr(char const *s, unsigned int start, unsigned int len);
void *ft_calloc(size_t count, size_t size);

#endif
