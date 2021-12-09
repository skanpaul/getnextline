/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:09:38 by ski               #+#    #+#             */
/*   Updated: 2021/12/06 18:09:40 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/* ************************************************************************** */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
/* -------------------------------------------------------------------------- */
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
/* -------------------------------------------------------------------------- */
char	*get_next_line(int fd);


// CHECK IF THE READ RETURN IS GOOD OR NOT
// >=0	l’ouverture de fichier c’est bien passé et le nombre est à utiliser comme filedescriptor
// -1	en cas d’erreur


/* -------------------------------------------------------------------------- */
char	*ft_newline_gnl(void);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strchr(const char *s, int c);
/* ************************************************************************** */
# endif
