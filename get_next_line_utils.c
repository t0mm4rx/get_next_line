/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmarx <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 11:59:08 by tmarx             #+#    #+#             */
/*   Updated: 2019/10/18 11:58:58 by tmarx            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	void		*res;
	unsigned int	i;

	i = 0;
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	while (i < nmemb)
		((unsigned char *)res)[i++] = '\0';
	return (res);
}

int	count_bl(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i])
		res += (str[i++] == '\n');
	return (res);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*strappend(char *dest, char *append, unsigned int append_size)
{
	char		*new;
	unsigned int	i;
	unsigned int	j;

	if (!(new = ft_calloc(ft_strlen(dest) + append_size + 1, sizeof(char))))
		return (NULL);
	i = 0;
	j = 0;
	while (dest[i])
		new[j++] = dest[i++];
	i = 0;
	while (i < append_size)
		new[j++] = append[i++];
	new[j] = '\0';
	free(dest);
	return (new);
}

char	*cut_first_chars(char *src, unsigned int i)
{
	char	*res;
	int	j;

	res = ft_calloc(ft_strlen(src) - i + 1, sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (src[i])
		res[j++] = src[i++];
	free(src);
	return (res);
}
