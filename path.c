/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:01:59 by briveiro          #+#    #+#             */
/*   Updated: 2023/01/21 16:52:23 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*all_the_path(char **path, char *argv)
{
	t_pipex	*pipex;
	char	**spl;
	char	*aux;
	char	*combo;
	int		count;

	count = 0;
	while (path[count])
	{
		if (path[count][0] == 'P' && path[count][1] == 'A'
			&& path[count][2] == 'T')
			break ;
		count++;
	}
	spl = ft_split(&path[count][5], ':');
	count = -1;
	while (spl[++count])
	{
		combo = ft_strjoin(spl[count], "/");
		aux = ft_strjoin(combo, argv);
		if (access(aux, X_OK) == 0)
		{
			free(spl);
			return (free(combo), aux);
		}
	}
	free(spl);
	return (0);
}

// char *get_path(char **path)
// {
// 	char	**all_the_paths;
	
// 	all_the_paths = all_the_path(path);
// }