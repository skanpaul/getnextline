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
	char			*new;
	char			*old;
	char			*extract;
	static char		buf[BUFFER_SIZE + 1];
	static ssize_t	start = 0;
	ssize_t			end;
	static ssize_t	char_read = 0;

	new = ft_substr("", 0, 1);
	buf[BUFFER_SIZE] = '\0';

	// Est-ce que tout le buffer a été traité?
	if (start == char_read)
	{
		start = 0;
		char_read = read(fd, buf, BUFFER_SIZE);

		if ((char_read == 0) || (char_read == -1)) // si fin de fichier ou problem
		{
			free (new);
			return (NULL);
		}
	}
	
	// Cherche le caractère RETOUR-A-LA-LIGNE
	end = start;
	while ((buf[end] != 0x0A) && (buf[end] != '\0'))
		end++;

	// Extrait la ligne trouvée
	extract = ft_substr(buf, start, (end - start));
	if (!extract)
	{
		free (new);
		return (NULL);
	}

	// Prépare le prochain START et END
	if (end < char_read - 1)	// si pas encore fin du fichier ou buffer		
		start = ++end;
	else 
		start = char_read;

	// Renvoie la nouvelle chaine
	old = new;
	new = ft_strjoin(old, extract);
	free (extract);
	free(old);

	return (new);	
}