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
char	*get_next_line(int fd)
{
	// DECLARATION
	char			*new;
	static char		buf[BUFFER_SIZE + 1];
	static size_t	start = 0;
	static size_t	end = 0;
	ssize_t			rd_ret;
	
	// INITIALISATION
	buf[BUFFER_SIZE]= '\0';
	rd_ret = 0;	
	
	// A faire seulement si on finit de lire une ligne
	new = ft_substr("", 0, 0);

	// BOUCLE DU CODE B
	rd_ret = code_b(fd, new, buf, &start, &end);
	if ((rd_ret == -1) || (rd_ret == 0))
		return (NULL);

	// FAIRE CODE A
	rd_ret = code_a(fd, new, buf, &start, &end);
	if ((rd_ret == -1) || (rd_ret == 0))
		return (NULL);
	
	return (new);
}

/* ************************************************************************** */
/* CODE A: LECTURE --> BUFFER AVEC 1 OU PLUSIEURS FINS DE LIGNES ************ */
/* ************************************************************************** */
ssize_t code_a(int fd, char *new, char *buf, size_t *start, size_t *end)
{
	char *old;
	char *extract;
	ssize_t	rd_ret;
	
	// Remplir buffer, SI NECESSAIRE
	rd_ret = fill_buf(fd, buf, start, end);
	if ((rd_ret == -1) || (rd_ret == 0))
		return (rd_ret);

	// Préparation de l'index end
	while ((buf[*end] != 0x0A) && (buf[*end] != '\0'))
		(*end)++;

	// Extraction de 
	// 1) ligne ENTIÈRE OU
	// 2) DEBUT de ligne OU 
	// 3) FIN de ligne
	extract = ft_substr(buf, *start, (*end - *start + 1));
	if (!extract)
		return (-1);

	// Construction de la vrai ligne de texte
	old = new;
	new = ft_strjoin(old, extract);
	if (!new)
		return (-1);
	free (extract);
	free (old);

	// Préparation du prochain "start" et "end"
	if (buf[*end] == '\0')
		*end = 0;
	else
		(*end)++;
	*start = *end;

	return (rd_ret);
}

/* ************************************************************************** */
/* CODE B: LECTURE -->BUFFER SANS FIN DE LIGNE ****************************** */
/* ************************************************************************** */
ssize_t code_b(int fd, char *new, char *buf, size_t *start, size_t *end)
{
	char	*old;
	ssize_t	rd_ret;

	rd_ret = 1;
	
	// Remplir buffer, SI NECESSAIRE
	rd_ret = fill_buf(fd, buf, start, end);
	if ((rd_ret == -1) || (rd_ret == 0))
		return (rd_ret);

	// -----------------------------------
	while (!have_endlinechar(buf))
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
/*  */
/* ************************************************************************** */
char	*have_endlinechar(char *buffer)
{
	int	i;

	i = 0;
	while ((buffer[i] != 0x0A) && (buffer[i] != '\0'))
		i++;
	if (buffer[i] == 0x0A)
		return (&buffer[i]);
	return (NULL);
}

/* ************************************************************************** */
/* GIVE NEXT END ************************************************************ */
/* ************************************************************************** */
/* size_t give_next_end(char *buf, size_t *start, size_t *end)
{
	*end = *start;
	while (buf[*end] != 0x0A)
		(*end)++;

} */

/* ************************************************************************** */
/* REMPLIR LE BUFFER ******************************************************** */
/* ************************************************************************** */
ssize_t fill_buf(int fd, char *buf, size_t *start, size_t *end)
{
	ssize_t rd_ret;

	if ((*start == 0) && (*end == 0)) /* si ANCIEN buffer completement lu alors: */
	{
		rd_ret = read(fd, (void *)buf, BUFFER_SIZE);
		if ((rd_ret == -1) || (rd_ret == 0))
			return (rd_ret);
	}
	return (rd_ret);
}

