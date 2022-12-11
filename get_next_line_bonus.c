/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:12:58 by khaimer           #+#    #+#             */
/*   Updated: 2022/12/11 18:19:15 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	int			read_char;
	char		*string;
	char		*line;
	char		*fre;
	static char *static_string[OPEN_MAX];
	
	read_char = 1;
	string = malloc(BUFFER_SIZE + 1);
	while(read_char != 0)
	{
		read_char = read(fd, string, BUFFER_SIZE);
		if(read_char < 0)
		{
			free(static_string[fd]);
			free(string);
			static_string[fd] = NULL;
			return(NULL);
		}
		string[read_char] = '\0';
		fre = static_string[fd];
		static_string[fd] = ft_strjoin(static_string[fd],string);
		free (fre);
		if(ft_strchr(string, '\n'))
			break;
	}
	line = get_first(static_string[fd]);
	if(ft_strlen(line) == 0)
	{
		free (line);
		line = NULL;
	}
	fre = static_string[fd];
	static_string[fd] = get_last(static_string[fd]);
	free (string);
	free (fre);
	return(line);
}