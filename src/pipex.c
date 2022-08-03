/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 02:11:46 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/04 00:15:50 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static int	child(t_data *data, char *envp[])
{
	int	err;
	if (access(data->path.cmd_path, F_OK) == 0)
	{
		close(data->pipex.fd[0]);
		dup2(data->pipex.fd[1], STDOUT_FILENO);
		close(data->pipex.fd[1]);
		err = execve(data->path.cmd_path, data->arg.cmd, envp);
		if (err == -1)
			ft_printf("bash: %s: exec command error\n", data->arg.cmd[0]);
		return (-1);
	}
	exit(EXIT_FAILURE);
}

static int	child2(t_data *data, char *envp[])
{
	int	err;
	if (access(data->path.cmd2_path, F_OK) == 0)
	{
		close(data->pipex.fd[1]);
		dup2(data->pipex.fd[0], STDIN_FILENO);
		close(data->pipex.fd[0]);
		dup2(data->file.outfile, STDOUT_FILENO);
		close(data->file.outfile);
		err = execve(data->path.cmd2_path, data->arg.cmd2, envp);
		if (err == -1)
			ft_printf("bash: %s: exec command error 2\n", data->arg.cmd2[0]);
		return (-1);
	}
	exit(127);
}

void	pipex(t_data *data, char *envp[])
{
	if (pipe(data->pipex.fd) == -1)
		ft_printf("Error\npipe");
	data->pipex.pid1 = fork();
	if (data->pipex.pid1 == -1)
		ft_printf("Error\nfork");
	if (data->pipex.pid1 == 0)
		child(data, envp);
	data->pipex.pid2 = fork();
	if (data->pipex.pid2 == -1)
		ft_printf("Error\nfork2");
	if (data->pipex.pid2 == 0)
		child2(data, envp);
	//close(data->pipex.fd[0]);
	//close(data->pipex.fd[1]);
	//waitpid(data->pipex.pid1, NULL, 0);
	//waitpid(data->pipex.pid2, NULL, 0);
}
