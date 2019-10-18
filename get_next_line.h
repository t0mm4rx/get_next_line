/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:38:48 by tmarx             #+#    #+#             */
/*   Updated: 2019/10/18 10:44:00 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

# include <unistd.h>
# include <libc.h>
# include <fcntl.h>
# include <sys/types.h>

int	get_next_line(int fd, char **line);
void	*ft_calloc(unsigned int nmemb, unsigned int size);
int	count_bl(char *str);
int	ft_strlen(char *str);
char	*strappend(char *dest, char *append, unsigned int append_size);
char	*get_first_line(char **buffer, char **line);
char	*cut_first_chars(char *src, unsigned int i);
#endif
