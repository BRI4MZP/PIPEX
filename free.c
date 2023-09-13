/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:43:58 by briveiro          #+#    #+#             */
/*   Updated: 2023/09/12 19:12:37 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_childs(t_pipex *pipex)
{
	int	count;

	count = -1;
	while (pipex->argv[++count])
		free(pipex->argv[count]);
	free(pipex->argv);
	free(pipex->full);
}

void	free_pipex(t_pipex *pipex)
{
	int	count;

	count = -1;
	close(pipex->fdin);
	close(pipex->fdout);
	while (pipex->path[++count])
		free(pipex->path[count]);
	free(pipex->path);
	free(pipex->pipe);
}

void	free_pipes(t_pipex *pipex)
{
	int	count;

	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	count = 0;
	while (pipex->envv[count])
		free(pipex->envv[count++]);
	free(pipex->envv);
}
