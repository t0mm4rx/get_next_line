/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:29:37 by tmarx             #+#    #+#             */
/*   Updated: 2019/11/18 12:29:43 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void			ft_strjoin(char **s1, char *s2, int s2_size)
{
	char	*res;
	int		i;
	int		j;
	int		s;

	i = -1;
	j = -1;
	s = ft_strlen(*s1);
	if (!(*s1) || !s2)
		return ;
	s2[s2_size] = '\0';
	res = ft_calloc(sizeof(char), s + s2_size + 1);
	if (!res)
		return ;
	while (++i < s)
		res[i] = (*s1)[i];
	while (++j < s2_size)
		res[i + j] = s2[j];
	res[i + j] = '\0';
	free(*s1);
	*s1 = res;
}

void			*ft_calloc(unsigned int nmemb, unsigned int size)
{
	void	*res;
	int		i;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < (int)nmemb * (int)size)
		((unsigned char*)res)[i++] = '\0';
	return (res);
}

unsigned int	ft_strlen(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*first_line(char const *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(res = ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	while (i--)
		res[i] = str[i];
	return (res);
}

void			cut(char **str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
		i++;
	if (!(res = ft_calloc(ft_strlen(*str) - i + 1, sizeof(char))))
		return ;
	while ((*str)[i])
		res[j++] = (*str)[i++];
	free(*str);
	*str = res;
}
