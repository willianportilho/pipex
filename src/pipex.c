/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 02:11:46 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/01 03:46:44 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	pipex_dup(t_data *data)
{
	if (data->pipex.i == 1)
	{
		dup2(data->file.infile, STDIN_FILENO);
		dup2(data->file.outfile, STDOUT_FILENO);
		close(data->file.infile);
		close(data->file.outfile);
	}
	else
	{
		dup2(data->pipex.fd[0], STDIN_FILENO);
		dup2(data->file.outfile, STDOUT_FILENO);
		close(data->pipex.fd[0]);
		close(data->file.outfile);
	}
}

static int	pipex_exec(t_data *data, char *envp[])
{
	if (pipe(data->pipex.fd) == -1)
		ft_printf("Error\npipe\n");
	data->pipex.pid = fork();
	if (data->pipex.pid == 0)
	{
		data->pipex.i = 1;
		pipex_dup(data);
		execve(data->path.cmd_p, data->arg.cmd, envp);
		return (0);
	}
	ft_printf("Aqui também.\n");
	wait(NULL);
	return (0);
}

void	pipex(t_data *data, char *envp[])
{
	pipex_exec(data, envp);
}
