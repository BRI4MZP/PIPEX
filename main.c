/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:29:46 by briveiro          #+#    #+#             */
/*   Updated: 2023/09/12 17:46:41 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void ft_void(void)
// {
// 	system("leaks -q a.out");
// }

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

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc != 5)
		return (output_msg("Error: Wrong number of arguments\n"));
	pipex = ft_initpipex();
	pipex->fdin = open(argv[1], O_RDONLY);
	if (pipex->fdin < 0)
		output_msg("Wrong input file\n");
	pipex->fdout = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC);
	if (pipex->fdout < 0)
		output_msg("Wrong output file\n");
	if (pipe(pipex->pipe) < 0)
		output_msg("Error: Pipe failure\n");
	pipex->envv = all_the_path(envp);
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
		first(pipex, argv, envp, pipex->envv);
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
		last(pipex, argv, envp, pipex->envv);
	free_pipes(pipex);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	free(pipex);
	return (0);
}

	// 	pipe(pipex->fd);
	// pipex->pid = fork();
	// if (pipex->pid == 0)  // el hijo
	// {
	// 	close(pipex->fd[END_READ]);
	// 	write(pipex->fd[END_WRITE], "ABCDE", 5);
	// 	dup2(pipex->fd[END_WRITE], STDOUT_FILENO);
	// 	close(pipex->fd[END_WRITE]);
	// 	execlp("/bin/ls", "ls", "-l", NULL);
	// 	exit(0);
	// }
	// else // padre
	// {
	// 	close(pipex->fd[END_WRITE]);
	// 	count = read(pipex->fd[END_READ], pipex->buffer, sizeof(pipex->buffer));
	// 	close(pipex->fd[END_WRITE]);
	// 	printf("%s", pipex->buffer);

	// }
	// free(pipex);