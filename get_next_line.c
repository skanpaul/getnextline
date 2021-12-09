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
	/* --------------------------------------------------- */
	/* INITIALISATION ------------------------------------ */
	/* --------------------------------------------------- */
	char			*new_line;
	char			*old_line;
	static char		buffer[BUFFER_SIZE + 1];
	static size_t	start;
	static size_t	end;
	ssize_t			read_ret;

	new_line = ft_newline_gnl();
	old_line = NULL;
	start = 0;
	end = 0;
	read_ret = 0;
	buffer[BUFFER_SIZE]= '\0';

	/* ------------------------------------------------------- */
	/* TEST 1: ancien buffer complètement lu ? --------------- */
	/* ------------------------------------------------------- */
	if (start != 0)
	{
		/* --------------------------------------------------- */
		/* REMPLIR BUFFER ------------------------------------ */
		/* --------------------------------------------------- */
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret < 0)
		{
			printf("ATTENTION: le read a eu un probleme\n"); 			
			free(new_line);
			return (new_line);
		}	
		printf("nombre de caracteres lus: %ld\n", read_ret);		
		/* --------------------------------------------------- */
		// if (read_ret == 0)
			// alors lecture accomplie jusqu a fin de fichier
			// FAIRE QQCH
		/* else
		{
			// FAIRE QQCH
		}	 */

		/* --------------------------------------------------- */
		/* TEST 2: buffer contient fin de ligne? ------------- */
		/* --------------------------------------------------- */
		// while (!(buffer, 0x0A))
		// {
			/* ----------------------------------------------- */
			/* CODE A ---------------------------------------- */
			/* ----------------------------------------------- */

		// }

	}
	/* ------------------------------------------------------- */
	/* CODE B ------------------------------------------------ */
	/* ------------------------------------------------------- */

	return (new_line);
}
/* ************************************************************************** */
/* char *code_a(char *new_line, char *buffer, size_t start, size_t end)
{
	char *old_line;

	old_line = new_line;

	new_line = ft_strjoin_gnl(old_line, buffer, BUFFER_SIZE);



	free(old_line);
	return (new_line);
} */

/* ************************************************************************** */




