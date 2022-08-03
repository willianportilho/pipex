/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 02:11:46 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/03 21:49:13 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static int	child(t_data *data, char *envp[])
{
	close(data->pipex.fd[0]);
	dup2(data->pipex.fd[1], STDOUT_FILENO);
	close(data->pipex.fd[1]);
	execve(data->path.cmd_path, data->arg.cmd, envp);
	ft_printf("bash: %s: command error", data->arg.cmd[0]);
	return (-1);
}

static int	child2(t_data *data, char *envp[])
{
	close(data->pipex.fd[1]);
	dup2(data->pipex.fd[0], STDIN_FILENO);
	close(data->pipex.fd[0]);
	dup2(data->file.outfile, STDOUT_FILENO);
	close(data->file.outfile);
	execve(data->path.cmd2_path, data->arg.cmd2, envp);
	ft_printf("bash: %s: command error", data->arg.cmd2[0]);
	return (-1);
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
}
