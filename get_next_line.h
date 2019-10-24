/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:33:28 by tmarx             #+#    #+#             */
/*   Updated: 2019/10/24 20:39:48 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define MAX_OPEN 4096
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int				get_next_line(int fd, char **line);
void			ft_strjoin(char **s1, char *s2, int s2_size);
void			*ft_calloc(unsigned int nmemb, unsigned int size);
unsigned int	ft_strlen(const char *str);
char			*first_line(const char *str);
void			cut(char **str);
unsigned int	count_bl(const char *str);
#endif
