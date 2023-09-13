/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:53:48 by briveiro          #+#    #+#             */
/*   Updated: 2023/09/12 18:39:33 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	c;

	c = 0;
	while (c < n)
	{
		((char *)s)[c] = 0;
		c++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;

	ret = malloc(count * size);
	if (ret)
	{
		ft_bzero(ret, (count * size));
		return (ret);
	}
	else
		return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != 0)
	{
		count++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	int	p;
	int	lensss ;

	lensss = ft_strlen(s);
	p = -1;
	if ((char )c == 0)
		return (((char *)s + lensss));
	while (s[++p])
	{
		if (s[p] == (char)c)
			return (((char *)s + p));
	}
	return (0);
}
