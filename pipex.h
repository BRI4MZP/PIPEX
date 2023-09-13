/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: briveiro <briveiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:13:06 by briveiro          #+#    #+#             */
/*   Updated: 2023/09/12 19:18:33 by briveiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# define NOT_YET -1
# define END_READ 0
# define END_WRITE 1

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		fdin;
	int		fdout;
	char	**argv;
	char	**envv;
	char	**spl;
	char	**path;
	char	*full;
	int		pipe[2];
}		t_pipex;

int		main(int argc, char **argv, char **envp);
char	*all_path(char **path, char *argv);
void	first(t_pipex *pipex, char **argv, char **env, char **aux);
void	last(t_pipex *pipex, char **argv, char **env, char **aux);
int		output_msg(char *error);
void	free_pipes(t_pipex *pipex);
void	free_pipex(t_pipex *pipex);
void	free_childs(t_pipex *pipex);
char	**all_the_path(char **path);
char	**ft_split(char const *s, char c);
void	creador(char **cadena, char const *s, char c, size_t palabras);
size_t	contador(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
t_pipex	*ft_initpipex(void);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
#endif