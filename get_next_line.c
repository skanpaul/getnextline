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
	char			*line;
	char			*new;
	char			*old;
	static char		buf[BUFFER_SIZE];
	static ssize_t	char_read = BUFFER_SIZE;
	int				line_done;

	if (fd < 0)
		return (NULL);
	line_done = 0;
	line = ft_substr("", 0, 0);
	while (line_done == 0)
	{
		new = create_segment(fd, buf, &line_done, &char_read);
		if (new == NULL)
		{
			if ((char_read == 0) && (line[0] != '\0'))
				return (line);
			free (line);
			return (NULL);
		}
		old = line;
		line = ft_strjoin(old, new);
		free (old);
		free (new);
		if (!line)
			return (NULL);
	}
	return (line);
}
/* ************************************************************************** */

char	*create_segment(int fd, char *buf, int *line_done, ssize_t *char_read)
{
	char			*new;
	static ssize_t	start = BUFFER_SIZE;
	ssize_t			end;

	if (start == *char_read)
	{
		start = 0;
		*char_read = read(fd, buf, BUFFER_SIZE);
		if ((*char_read == 0) || (*char_read == -1))
			return (NULL);
	}
	end = start;
	while ((buf[end] != 0x0A) && (end < (*char_read - 1)))
		end++;
	if (buf[end] == 0x0A)
		*line_done = 1;
	new = ft_substr(buf, start, (end - start + 1));
	if (end >= *char_read - 1)
		start = *char_read;
	else
		start = ++end;
	return (new);
}
/* ************************************************************************** */
// char *create_segment(int fd, char *buf, int *line_done, ssize_t *char_read) 
// {
// 	char			*new;
// 	static ssize_t	start = BUFFER_SIZE;
// 	ssize_t			end;
// 	// ---------------------------------------------------------
// 	// Est-ce que tout le buffer a été complètement analysé ?
// 	if (start == *char_read)
// 	{
// 		start = 0;
// 		*char_read = read(fd, buf, BUFFER_SIZE);
// si fin de fichier ou problem
// 		if ((*char_read == 0) || (*char_read == -1)) 
// 			return (NULL);
// 	}
// 	// Cherche la fin de segment pour le "new" string
// 	end = start;
// 	while ((buf[end] != 0x0A) && (end < (*char_read - 1)))
// 		end++;
// 	// Si RETOUR-A-LA-LIGNE trouvé
// 	if (buf[end] == 0x0A)
// 		*line_done = 1;	// Alors FIN-LIGNE trouvé 
// 	// Extrait la ligne trouvée (complète ou tronqué)
// 	new = ft_substr(buf, start, (end - start + 1));		// crée un "new" string 
// SI:		tous les caractère du buffer ont été analysé
// 	if (end >= *char_read - 1)	
// 		start = *char_read;		// ALORS:	prêt a remplir un nouveau le buffer	
// 	else 
// 		start = ++end;			// SINON:	préparte le prochain START et END
// 	// ----------------------------------------------------------------------
// 	return (new);	
// }