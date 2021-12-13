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
char    *create_segment(int fd, char *buf, int *full_line);

/* -------------------------------------------------------------------------- */
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strdup_gnl(const char *s1);
void	*ft_memmove_gnl(void *dst, const void *src, size_t len);

/* ************************************************************************** */
# endif
