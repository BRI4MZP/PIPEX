/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:13:06 by briveiro          #+#    #+#             */
/*   Updated: 2023/01/26 03:20:28 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define NOT_YET -1
#define END_READ 0
#define END_WRITE 1
typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int 	fdin;
	int		fdout;
	char	**argv;
	char	**envv;
	char	**spl;
	char	**path;
	char	*full;
	int		pipe[2];
	
}				t_pipex;

char 	**all_the_path(char **path);
void	free_childs(t_pipex *pipex);
void	free_pipes(t_pipex *pipex);
void	free_pipex(t_pipex *pipex);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*all_path(char **path, char *argv);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
size_t	contador(char const *s, char c);
// char 	**ft_slasher(char **str);
void	creador(char **cadena, char const *s, char c, size_t palabras);
// char *get_path(char **path);
t_pipex *ft_initpipex();
void	first(t_pipex *pipex, char **argv, char **env, char **aux);
void	last(t_pipex *pipex, char **argv, char **env, char **aux);
int		output_error(char *error);
// status para el estado de los hijos
// pid identificador proceso de hijos