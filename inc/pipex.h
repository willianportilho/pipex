/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:11:31 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/03 01:03:44 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define INFILE 0
# define OUTFILE 1

# include "./libft.h"
# include <unistd.h> // Checar depois se é necessário
# include <fcntl.h>
# include <sys/wait.h>
#include <stdio.h>

typedef struct s_file
{
	int	infile;
	int	outfile;
}		t_file;

typedef struct s_arg
{
	char	**cmd;
	char	**cmd2;
}			t_arg;

typedef struct s_path
{
	char	**all_path;
	char	*cmd_path;
	char	*cmd2_path;
}			t_path;

typedef struct s_pipex
{
	int	i;
	int	fd[2];
	int	pid;
	int	pid2;
	int	exit;
}		t_pipex;

typedef struct s_data
{
	t_file	file;
	t_path	path;
	t_arg	arg;
	t_pipex	pipex;
}			t_data;

void	pipex_pre(int argc, char *argv[], char *envp[], t_data *data);
void	pipex(t_data *data, char *envp[]);
void	fd_error(char *file_err, int check, t_data *data);
void	pipex_clear(t_data *data);

#endif