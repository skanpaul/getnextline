/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:09:59 by ski               #+#    #+#             */
/*   Updated: 2021/12/06 18:10:02 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

/* ************************************************************************** */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/* ************************************************************************** */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	new_len;
	char	*new;
	size_t	i;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup("\0"));
	if (len > s_len)
		new_len = s_len - start + 1;
	else
		new_len = len + 1;
	new = (char *)malloc(sizeof(char) * new_len);
	if (!new)
		return (0);
	i = 0;
	while (i < new_len - 1)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

/* ************************************************************************** */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;	
	size_t	new_len;
	char	*new;

	if ((s1 == 0) | (s2 == 0))
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_len = s1_len + s2_len + 1;
	new = (char *)malloc(new_len * sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_memmove(new, s1, s1_len);
	ft_memmove(new + s1_len, s2, s2_len);
	new[new_len - 1] = '\0';
	return (new);
}

/* ************************************************************************** */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (0);
	if ((src < dst) & (len > 0))
	{
		i = len - 1;
		while (i > 0)
		{
			*((char *)dst + i) = *((char *)src + i);
			i--;
		}
		*((char *)dst + i) = *((char *)src + i);
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*((char *)dst + i) = *((char *)src + i);
			i++;
		}
	}
	return (dst);
}

/* ************************************************************************** */
char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	mem_len;
	char	*new;

	mem_len = ft_strlen(s1) + 1;
	new = (char *)malloc(mem_len * sizeof(char));
	if (new == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
