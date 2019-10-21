/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:45:38 by tmarx             #+#    #+#             */
/*   Updated: 2019/10/21 13:45:57 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_file
{
	int				fd;
	char			*res;
	struct s_file	*next;
}					t_file;

int					get_next_line(int fd, char **line);
void				*ft_calloc(unsigned int nmemb, unsigned int size);
int					count_bl(char *str);
int					ft_strlen(char *str);
void				strappend(char **dest, char *append,
					unsigned int append_size);
void				get_first_line(char **buffer, char **line);
char				*cut_first_chars(char *src, unsigned int i);
char				**fd_to_res(int fd, t_file **list);
#endif
