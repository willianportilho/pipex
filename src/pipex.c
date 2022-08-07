/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 02:11:46 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/08 01:53:58 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static int	child(t_data *data, char *envp[])
{
	close(data->pipex.fd[0]);
	if (data->file.infile == -1)
		exit(EXIT_FAILURE);
	if (!data->path.cmd_path)
		exit(127);
	dup2(data->pipex.fd[1], STDOUT_FILENO);
	close(data->pipex.fd[1]);
	execve(data->path.cmd_path, data->arg.cmd, envp);
	ft_printf("%s: command error", data->arg.cmd[0]);
	return (-1);
}

static int	parent(t_data *data, char *envp[])
{
	close(data->pipex.fd[1]);
	if (data->file.outfile == -1)
		exit(EXIT_FAILURE);
	if (!data->path.cmd2_path)
		exit(127);
	dup2(data->pipex.fd[0], STDIN_FILENO);
	close(data->pipex.fd[0]);
	dup2(data->file.outfile, STDOUT_FILENO);
	close(data->file.outfile);
	execve(data->path.cmd2_path, data->arg.cmd2, envp);
	ft_printf("%s: command2 error", data->arg.cmd2[0]);
	return (-1);
}

void	pipex(t_data *data, char *envp[])
{
	pipe(data->pipex.fd);
	data->pipex.pid1 = fork();
	if (data->pipex.pid1 == 0)
		data->pipex.exit = child(data, envp);
	waitpid(data->pipex.pid1, NULL, 0);
		parent(data, envp);
}
