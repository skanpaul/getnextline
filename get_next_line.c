/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:09:27 by ski               #+#    #+#             */
/*   Updated: 2021/12/06 18:09:30 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
/* ************************************************************************** */
ssize_t code_a(int fd, char *new, char *buf, size_t *start, size_t *end);
ssize_t code_b(int fd, char *new, char *buf, size_t *start, size_t *end);
/* ************************************************************************** */
char	*get_next_line(int fd)
{
	/* --------------------------------------------------- */
	/* INITIALISATION ------------------------------------ */
	/* --------------------------------------------------- */
	char			*new;
	char			*old;
	static char		buf[BUFFER_SIZE + 1];
	static size_t	start = 0;
	static size_t	end = 0;
	ssize_t			rd_ret;
	
	buffer[BUFFER_SIZE]= '\0';

	old_line = NULL;
	read_ret = 0;
		
	new_line = ft_substr("", 0, 0);
	/* TEST 1: ancien buffer complètement lu ? --------------- */

	if ((start != 0) && (end != 0))
	{
		rd_ret = read(fd, (void *)buf, BUFFER_SIZE);
		if ((rd_ret == -1) || (rd_ret == 0))
		return (NULL);
		
		rd_ret = code_b(fd, new, buf, &start, &end); // FAIRE CODE B
		if (rd_ret == -1) || (rd_ret == 0)
			return (NULL);
	}
	
	// FAIRE CODE A
	
	return (new_line);
}

/* ************************************************************************** */
/* BUFFER AVEC 1 OU PLUSIEURS FINS DE LIGNES ******************************** */
/* ************************************************************************** */
ssize_t *code_a(int fd, char *new, char *buf, size_t *start, size_t *end)
{
	char *old;
	ssize_t	rd_ret;

	





	free(old);
	return (new);
}

/* ************************************************************************** */
/* BUFFER SANS FIN DE LIGNE ************************************************* */
/* ************************************************************************** */
ssize_t code_b(int fd, char *new, char *buf, size_t *start, size_t *end)
{
	char	*old;
	ssize_t	rd_ret;

	
	while (!have_endline_char(buf))
	{
		old = new;
		new = ft_strjoin(old, new);		
		free(old);
		*start = 0;
		*end = 0;

		rd_ret = read(fd, (void *)buf, BUFFER_SIZE);
		if ((rd_ret == -1) || (rd_ret == 0))
			return (rd_ret);
	}
	return (rd_ret);
}


/* ************************************************************************** */
/* GIVE NEXT END ************************************************************ */
/* ************************************************************************** */
size_t give_next_end(char *buf, size_t *start, size_t *end)
{
	*end = *start;
	while (buf[*end] != 0x0A)
		(*end)++;





}

