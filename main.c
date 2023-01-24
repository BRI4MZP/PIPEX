/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:29:46 by briveiro          #+#    #+#             */
/*   Updated: 2023/01/24 06:38:48 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_void(void)
{
	system("leaks -q a.out");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	char	**aux;

	atexit(ft_void);
	if (argc != 5)
		return(printf("%s", "Número de argumentos incorrecto"), 0);
	pipex = ft_initpipex(envp);
	pipex->fdin = open(argv[1], O_RDONLY);
	if (pipex->fdin < 0)
		printf("%s\n", "EL ARCHIVO DE LECTURA NO EXISTE BRO");
	pipex->fdout = open(argv[4], O_CREAT | O_RDWR | O_TRUNC);
	if (pipex->fdout < 0)
		printf("%s\n", "ARCHIVO DE ESCRITURA ERRONEO");
	if (pipe(pipex->pipe) < 0)
		printf("%s", "error en pipe");
	// flag = ft_split(argv[1], ' ');
	aux = all_the_path(envp);
	pipex->pid1 = fork();
	if (pipex->pid1)
		first(pipex, argv, envp,  aux);
	pipex->pid2 = fork();
	if (pipex->pid2)
		last(pipex, argv, envp,  aux);
	free(aux);
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