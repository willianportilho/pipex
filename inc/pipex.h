/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:11:31 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/09 01:13:17 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define INFILE 0
# define OUTFILE 1
# define NO_CMD 127

# include "./libft.h"
# include <unistd.h> // checar qual função usa
# include <fcntl.h>
# include <sys/wait.h>
#include <stdio.h> // checar qual função usa (perror?)

typedef struct s_file
{
	int	infile;
	int	outfile;
}		t_file;

typedef struct s_pipex
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		exit;
	int		status;
}		t_pipex;

typedef struct s_data
{
	t_file	file;
	t_pipex	pipex;
}			t_data;

void	pipex(t_data *data, char *argv[], char *envp[]);
void	pipex_pre(int argc, char *argv[], t_data *data);
void	pipex_cmd(char *cmd, char *envp[]);
void	fd_error(char *file_err, int check, t_data *data);
void	cmd_error(char *cmd_err);
char	*get_cmd_path(char *cmd, char *envp[]);
char	**pipex_cmd_arg(char *cmd);
void	pipex_clean(char **cmd_path, char ***cmd_arg);

#endif