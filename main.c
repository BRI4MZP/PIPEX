/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:29:46 by briveiro          #+#    #+#             */
/*   Updated: 2023/01/21 19:20:12 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void ft_void(void)
// {
// 	system("leaks -q a.out");
// }

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	char	*aux;
	char	**flag;

	// atexit(ft_void);
	if (argc != 5)
		return(printf("%s", "Número de argumentos incorrecto"), 0);
	pipex = ft_initpipex(envp);
	pipex->fda = open(argv[1], O_RDONLY);
	if (pipex->fda < 0)
		printf("%s\n", "EL ARCHIVO DE LECTURA NO EXISTE BRO");
	pipex->fdb = open(argv[4], O_CREAT | O_RDWR | O_TRUNC);
	if (pipex->fdb < 0)
		printf("%s\n", "ARCHIVO DE ESCRITURA ERRONEO");
	flag = ft_split(argv[1], ' ');
	printf("%s\n%s\n", flag[0], flag[1]);
	aux = all_the_path(envp, flag[0]);
	execve(aux, &flag[0], envp);
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