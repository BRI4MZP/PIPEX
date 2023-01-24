/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:26:15 by briveiro          #+#    #+#             */
/*   Updated: 2023/01/24 04:35:58 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*all_path(char **path, char *argv)
{
	char	*temp;
	int		count;

	count = -1;
	while (path[++count])
	{
		temp = ft_strjoin(path[count], argv);
		if (access(temp, X_OK) == 0)
			return (temp);
		free(temp);
	}
	return (NULL);
}

void	first(t_pipex *pipex, char **argv, char **env, char **aux)
{
	dup2(pipex->pipe[1], 1);
	close(pipex->pipe[0]);
	dup2(pipex->fdin, 0);
	pipex->argv = ft_split(argv[2], ' ');
	pipex->full = all_path(aux, pipex->argv[0]);
	if (!pipex->full)
	{
		printf("ERRORRRRRRR");
		exit(1);
	}
	execve(pipex->full, pipex->argv, env);
}

void	last(t_pipex *pipex, char **argv, char **env, char **aux)
{
	dup2(pipex->pipe[0], 0);
	close(pipex->pipe[1]);
	dup2(pipex->fdout, 1);
	pipex->argv = ft_split(argv[3], ' ');
	pipex->full = all_path(aux, pipex->argv[0]);
	if (!pipex->full)
	{
		printf("ERRORRRRRRR");
		exit(1);
	}
	execve(pipex->full, pipex->argv, env);
}
