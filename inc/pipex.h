/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:11:31 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/01 03:21:27 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft.h"
# include <unistd.h> // Checar depois se é necessário
# include <fcntl.h>
# include <sys/wait.h>

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
	char	*cmd_p;
	char	*cmd2_p;
}			t_path;

typedef struct s_pipex
{
	int	i;
	int	fd[2];
	int	pid;
}		t_pipex;

typedef struct s_data
{
	t_file	file;
	t_path	path;
	t_arg	arg;
	t_pipex	pipex;
}			t_data;

void	pre_pipex(int argc, char *argv[], char *envp[], t_data *data);
void	pipex(t_data *data, char *envp[]);

#endif