/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 02:11:46 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/16 01:29:08 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

static void	close_pipes(t_data *data)
{
	int	j;

	j = -1;
	while (++j < data->pipex.amount_cmd - 1)
	{
		close(data->pipex.pipes[j][0]);
		close(data->pipex.pipes[j][1]);
	}
}

static int	executer(t_data *data, char *argv[], char *envp[])
{
	char	*cmd_path;
	char	**cmd_arg;

	cmd_arg = pipex_cmd_arg(argv[data->pipex.i + 2], data);
	cmd_path = pipex_cmd_path(cmd_arg[0], envp);
	if (!cmd_path)
	{
		clean_alloc(data);
		process_clean(&cmd_path, &cmd_arg);
	}
	if (execve(cmd_path, cmd_arg, envp) == -1)
		perror("pipex: exec:");
	process_clean(&cmd_path, &cmd_arg);
	clean_alloc(data);
	exit(EXIT_FAILURE);
}

static void	last_child(t_data *data)
{
	if (data->file.outfile == -1)
	{
		clean_alloc(data);
		exit(EXIT_FAILURE);
	}
	dup2(data->pipex.pipes[data->pipex.i - 1][0], STDIN_FILENO);
	dup2(data->file.outfile, STDOUT_FILENO);
	close(data->file.outfile);
}

static void	child(t_data *data, char *argv[], char *envp[])
{
	if (data->pipex.i == 0)
	{
		dup2(data->file.infile, STDIN_FILENO);
		close(data->file.infile);
		dup2(data->pipex.pipes[data->pipex.i][1], STDOUT_FILENO);
		if (data->file.infile == -1)
		{
			clean_alloc(data);
			exit (EXIT_FAILURE);
		}
	}
	else if (data->pipex.i < data->pipex.amount_cmd - 1)
	{
		dup2(data->pipex.pipes[data->pipex.i - 1][0], STDIN_FILENO);
		dup2(data->pipex.pipes[data->pipex.i][1], STDOUT_FILENO);
	}
	else
		last_child(data);
	close_pipes(data);
	executer(data, argv, envp);
}

void	pipex(t_data *data, char *argv[], char *envp[])
{
	int	wstatus;

	while (++data->pipex.i < data->pipex.amount_cmd)
	{
		if (pipe(data->pipex.pipes[data->pipex.i]) == -1)
			function_fail("pipe");
	}
	data->pipex.i = -1;
	while (++data->pipex.i < data->pipex.amount_cmd)
	{
		data->pipex.pid[data->pipex.i] = fork();
		if (data->pipex.pid[data->pipex.i] == -1)
			function_fail("fork");
		if (data->pipex.pid[data->pipex.i] == 0)
			child(data, argv, envp);
	}
	close_pipes(data);
	data->pipex.i = -1;
	while (++data->pipex.i < data->pipex.amount_cmd)
	{
		waitpid(data->pipex.pid[data->pipex.i], &wstatus, 0);
		if (WIFEXITED(wstatus))
			data->pipex.exit = WEXITSTATUS(wstatus);
	}
}
