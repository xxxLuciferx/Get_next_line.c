/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:34:44 by khaimer           #+#    #+#             */
/*   Updated: 2022/12/03 23:56:48 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			read_char;
	char		*string;
	char		*line;
	char		*fre;
	static char *static_string;
	
	read_char = 1;
	string = malloc(BUFFER_SIZE + 1);
	while(read_char != 0)
	{
		read_char = read(fd, string, BUFFER_SIZE);
		if(read_char < 0)
		{
			free(static_string);
			free(string);
			static_string = NULL;
			return(NULL);
		}
		string[read_char] = '\0';
		fre = static_string;
		static_string = ft_strjoin(static_string,string);
		free (fre);
		if(ft_strchr(string, '\n'))
			break;
	}
	line = get_first(static_string);
	if(ft_strlen(line) == 0)
	{
		free (line);
		line = NULL;
	}
	fre = static_string;
	static_string = get_last(static_string);
	free (string);
	free (fre);
	return(line);
}
// int main()
// {
// 	int fd;

// 	fd = open("youssef.txt", O_RDONLY);
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// }