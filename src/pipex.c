/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 02:11:46 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/08 05:50:41 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static int	child(t_data *data, char *argv[], char *envp[])
{
	char	*cmd_path;
	char	**cmd_arg;
	int		i;

	close(data->pipex.fd[0]);
	if (data->file.infile == -1)
		exit(EXIT_FAILURE);
	cmd_arg = pipex_cmd_arg(argv[2]);
	cmd_path = get_cmd_path(cmd_arg[0], envp);
	if (!cmd_path)
	{
		free(cmd_path);
		i = 0;
		while (cmd_arg[i])
			free(cmd_arg[i++]);
		free(cmd_arg);
		exit(127);
	}
	dup2(data->pipex.fd[1], STDOUT_FILENO);
	close(data->pipex.fd[1]);
	execve(cmd_path, cmd_arg, envp);
	ft_printf("%s: command error", cmd_arg[0]);
	return (-1);
}

static int	parent(t_data *data, char *argv[], char *envp[])
{
	char	*cmd_path;
	char	**cmd_arg;
	int		i;

	close(data->pipex.fd[1]);
	if (data->file.outfile == -1)
		exit(EXIT_FAILURE);
	cmd_arg = pipex_cmd_arg(argv[3]);
	cmd_path = get_cmd_path(cmd_arg[0], envp);
	if (!cmd_path)
	{
		free(cmd_path);
		i = 0;
		while (cmd_arg[i])
			free(cmd_arg[i++]);
		free(cmd_arg);
		exit(127);
	}
	dup2(data->pipex.fd[0], STDIN_FILENO);
	close(data->pipex.fd[0]);
	dup2(data->file.outfile, STDOUT_FILENO);
	close(data->file.outfile);
	execve(cmd_path, cmd_arg, envp);
	ft_printf("%s: command2 error", cmd_arg[0]);
	return (-1);
}

void	pipex(t_data *data, char *argv[], char *envp[])
{
	pipe(data->pipex.fd);
	data->pipex.pid1 = fork();
	if (data->pipex.pid1 == 0)
		data->pipex.exit = child(data, argv, envp);
	waitpid(data->pipex.pid1, NULL, 0);
		parent(data, argv, envp);
}
