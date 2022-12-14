/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khaimer <khaimer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:18:37 by khaimer           #+#    #+#             */
/*   Updated: 2022/12/14 16:54:13 by khaimer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

int		ft_strchr(char *string, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
char	*get_first(char *static_string);
char	*get_last(char *static_string);
char	*get_next_line(int fd);

#endif