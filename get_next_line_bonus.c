/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:12:58 by khaimer           #+#    #+#             */
/*   Updated: 2022/12/14 16:44:30 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*invalid_fd(char *string, char **static_string)
{
	free(string);
	free(*static_string);
	*static_string = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	int			read_char;
	char		*string;
	char		*pointer;
	static char	*static_string[OPEN_MAX];

	read_char = 1;
	string = malloc(BUFFER_SIZE + 1);
	while (read_char != 0)
	{
		read_char = read(fd, string, BUFFER_SIZE);
		if (read_char < 0)
			return (invalid_fd(string, &static_string[fd]));
		string[read_char] = '\0';
		static_string[fd] = ft_strjoin(static_string[fd], string);
		if (ft_strchr(string, '\n'))
			break ;
	}
	free (string);
	string = get_first(static_string[fd]);
	pointer = static_string[fd];
	static_string[fd] = get_last(static_string[fd]);
	free (pointer);
	return (string);
}
