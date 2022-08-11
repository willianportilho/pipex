/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:11:31 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/11 19:33:37 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define INFILE 0
# define OUTFILE 1
# define NO_CMD 127

# include "./libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_file
{
	int	infile;
	int	outfile;
}		t_file;

typedef struct s_pipex
{
	int	fd[2];
	int	pid;
	int	exit;
	int	check;
}		t_pipex;

typedef struct s_data
{
	t_file	file;
	t_pipex	pipex;
}			t_data;

void	clean_cmd_error(char **temp2, char **cmd_path, \
char ***all_path, char *cmd);
void	clean_cmd_ok(char **temp, char **temp2, char ***all_path);
void	fd_error(char *file_err, int check, t_data *data);
void	function_fail(char *f_name);
void	pipex(t_data *data, char *argv[], char *envp[]);
void	process_clean(char **cmd_path, char ***cmd_arg);
void	quotes_error(void);

char	**pipex_cmd_arg(char *cmd, t_data *data);
char	*pipex_cmd_path(char *cmd, char *envp[]);

#endif