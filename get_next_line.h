/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:33:28 by tmarx             #+#    #+#             */
/*   Updated: 2019/10/24 13:13:40 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <libc.h>
# define MAX_OPEN 4096
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int				get_next_line(int fd, char **line);
char			*ft_strjoin(char const *s1, char const *s2);
void			*ft_calloc(unsigned int nmemb, unsigned int size);
unsigned int	ft_strlen(const char *str);
char			*first_line(const char *str);
void			cut(char **str);
#endif
