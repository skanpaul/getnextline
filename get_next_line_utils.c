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
char	*ft_newline_gnl(void)
{
	char	*new;
	new = (char *)malloc(1 * sizeof(char));
	if (!new)
		return (NULL);
	new[0] = '\n';
	return (new);
}

/* ************************************************************************** */
size_t	ft_strlen_gnl(const char *s_gnl)
{
	size_t	i;

	i = 0;
	while (s_gnl[i] != '\n')
	{
		i++;
	}
	return (i);
}

/* ************************************************************************** */
char	*ft_strjoin_gnl(char const *s1_gnl, char const *s2_gnl, int buffer_size)
{
	size_t	s1_gnl_len;
	size_t	s2_gnl_len;	
	size_t	new_len;
	char	*new;


	buffer_size++; // A EFFACER TOUT DE SUITE, BIDON 


	if ((s1_gnl == 0) | (s2_gnl == 0))
		return (NULL);
	s1_gnl_len = ft_strlen_gnl(s1_gnl);
	s2_gnl_len = ft_strlen_gnl(s2_gnl);
	new_len = s1_gnl_len + s2_gnl_len + 1;
	new = (char *)malloc(new_len * sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_memmove(new, s1_gnl, s1_gnl_len);
	ft_memmove(new + s1_gnl_len, s2_gnl, s2_gnl_len);
	new[new_len - 1] = '\n';
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
char	*have_endlinechar(char *buffer, int buffer_size)
{
	int		i;

	i = 0;
	while ((buffer[i] != 0x0A) && (i < (buffer_size - 1)))
	{
		
		i++;
	}
	// if ()

	// if (i == )
	// 	return ((char *)s + i);
	return (0);
}

