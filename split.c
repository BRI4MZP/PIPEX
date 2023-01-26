/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:22:22 by briveiro          #+#    #+#             */
/*   Updated: 2023/01/26 03:19:54 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	char	*dest;
	size_t	count;

	s2 = (char *)s1;
	dest = (char *)malloc((ft_strlen(s2) + 1));
	count = -1;
	if (!dest)
		return (NULL);
	while (s2[++count])
		dest[count] = s2[count];
	dest[count] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	count;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	count = -1;
	while (++count < len)
		s2[count] = *(s + start + count);
	s2[count] = '\0';
	return (s2);
}

size_t	contador(char const *s, char c)
{
	size_t	contadorpalablas;
	size_t	coincidencia;

	contadorpalablas = 0;
	coincidencia = 1;
	while (*s)
	{
		if (*s != c && coincidencia)
		{
			coincidencia = 0;
			contadorpalablas++;
		}
		else if (*s == c)
			coincidencia = 1;
		s++;
	}
	return (contadorpalablas);
}

void	creador(char **cadena, char const *s, char c, size_t palabras)
{
	char	*cambio;

	while (*s && *s == c)
		s++;
	while (palabras--)
	{
		cambio = ft_strchr(s, c);
		if (cambio)
		{
			*cadena = ft_substr(s, 0, cambio - s);
			while (*cambio && *cambio == c)
				cambio++;
			s = cambio;
		}
		else
			*cadena = ft_substr(s, 0, ft_strlen(s) + 1);
		cadena++;
	}
	*cadena = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**cadena;
	size_t	palabras;

	if (!s)
		return (NULL);
	palabras = contador(s, c);
	cadena = malloc(sizeof(char **) * (palabras + 1));
	if (!cadena)
		return (NULL);
	creador(cadena, s, c, palabras);
	return (cadena);
}
