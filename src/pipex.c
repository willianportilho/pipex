/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 02:11:46 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/10 04:42:20 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static int	child(t_data *data, char *argv[], char *envp[])
{
	char	*cmd_path;
	char	**cmd_arg;

	dup2(data->file.infile, STDIN_FILENO);
	close(data->file.infile);
	close(data->pipex.fd[0]);
	if (data->file.infile == -1)
		exit(EXIT_FAILURE);
	cmd_arg = pipex_cmd_arg(argv[2], data);
	cmd_path = pipex_cmd_path(cmd_arg[0], envp);
	if (!cmd_path)
		process_clean(&cmd_path, &cmd_arg);
	dup2(data->pipex.fd[1], STDOUT_FILENO);
	close(data->pipex.fd[1]);
	if (execve(cmd_path, cmd_arg, envp) == -1)
		ft_printf("exec error");
	process_clean(&cmd_path, &cmd_arg);
	exit(EXIT_FAILURE);
}

static int	parent(t_data *data, char *argv[], char *envp[])
{
	char	*cmd_path;
	char	**cmd_arg;

	close(data->pipex.fd[1]);
	if (data->file.outfile == -1)
		exit(EXIT_FAILURE);
	cmd_arg = pipex_cmd_arg(argv[3], data);
	cmd_path = pipex_cmd_path(cmd_arg[0], envp);
	if (!cmd_path)
		process_clean(&cmd_path, &cmd_arg);
	dup2(data->pipex.fd[0], STDIN_FILENO);
	close(data->pipex.fd[0]);
	dup2(data->file.outfile, STDOUT_FILENO);
	close(data->file.outfile);
	if (execve(cmd_path, cmd_arg, envp) == -1)
		ft_printf("exec2 error");
	process_clean(&cmd_path, &cmd_arg);
	exit(EXIT_FAILURE);
}

void	pipex(t_data *data, char *argv[], char *envp[])
{
	pipe(data->pipex.fd);
	data->pipex.pid = fork();
	if (data->pipex.pid == 0)
		data->pipex.exit = child(data, argv, envp);
	wait(NULL);
	parent(data, argv, envp);
}
