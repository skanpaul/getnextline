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

/* ************************************************************************** */
char	*get_next_line(int fd)
{
	char			*line;
	char			*new;			
	char			*old;

	static char		buf[BUFFER_SIZE + 1];
	static int		full_line = 1; // 0: line NOT complete | 1: line complete 
	// ---------------------------------------------------------

	buf[BUFFER_SIZE] = '\0';

	line = create_next_string(fd, buf, &full_line); // ATTENTION, full_line est à tester
	if (!line)
		return (NULL);

	while (full_line == 0)
	{
		old = line;
		new = create_next_string(fd, buf, &full_line);	
		if (!new)
		{
			free (old);
			return (NULL);
		}	
		line = ft_strjoin(old, new);
		if (!line)
		{
			free (old);
			free (new);
			return (NULL);
		}
	
	}

	return (line);	
	
}
/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
// NEED to check "full_line": 0: endline NOT FOUND | 1: endline FOUND
// RETURN: the new string create
char *create_next_string(int fd, char *buf, int *full_line) 
{
	char			*new;
	static ssize_t	start = 0;
	ssize_t			end;
	static ssize_t	char_read = 0;
	// ---------------------------------------------------------

	*full_line = 1;
	// Est-ce que tout le buffer a été traité?
	if (start == char_read)
	{
		start = 0;
		char_read = read(fd, buf, BUFFER_SIZE);
		if ((char_read == 0) || (char_read == -1)) // si fin de fichier ou problem
			return (NULL);
	}
	
	// Cherche le caractère RETOUR-A-LA-LIGNE
	end = start;
	while ((buf[end] != 0x0A) && (buf[end] != '\0'))
		end++;

	// Test si FIN de ligne est inéxistant ==> endline absent?
	if (buf[end] == '\0')
	{
		end--;
		*full_line = 0;
	}		

	// Extrait la ligne trouvée (complète ou tronqué)
	new = ft_substr(buf, start, (end - start));

	// Prépare le prochain START et END
	if (end < char_read - 1)	// si pas encore fin du fichier ou buffer		
		start = ++end;
	else 
		start = char_read;		// si FIN du fichier ou buffer	

	return (new);	
}
