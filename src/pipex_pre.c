/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_pre.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 02:20:17 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/08 00:36:33 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	get_path(char *envp[], t_data *data)
{
	int		i;
	char	*line;

	i = 0;
	data->path.all_path = NULL;
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
		{
			line = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
			data->path.all_path = ft_split(line, ':');
			free (line);
		}
		i++;
	}
	if (!data->path.all_path)
	{
		ft_printf("Error\n\"PATH\" not found.\n");
		free(data->path.all_path);
		exit(EXIT_FAILURE);
	}
}

static void	get_cmd(char *argv[], t_data *data)
{
	int		i;
	char	*temp;
	char	*temp2;

	i = 0;
	data->path.cmd_path = NULL;
	data->path.cmd2_path = NULL;
	data->arg.cmd = ft_split(argv[2], ' '); // Depois vou resolver a questão dos espaços fazendo uma função que leia isso
	data->arg.cmd2 = ft_split(argv[3], ' ');
	while (data->path.all_path[i])
	{
		temp = ft_strjoin(data->path.all_path[i], \
		ft_strjoin("/", data->arg.cmd[0]));
		temp2 = ft_strjoin(data->path.all_path[i++], \
		ft_strjoin("/", data->arg.cmd2[0]));
		if ((access(temp, F_OK) == 0) && ((data->path.cmd_path) == NULL))
			data->path.cmd_path = ft_strdup(temp);
		if ((access(temp2, F_OK) == 0) && ((data->path.cmd2_path) == NULL))
			data->path.cmd2_path = ft_strdup(temp2);
		free(temp);
		free(temp2);
	}
	if (!data->path.cmd_path)
		cmd_error(data->arg.cmd[0]);
	if (!data->path.cmd2_path)
		cmd_error(data->arg.cmd2[0]);
}

void	pipex_pre(int argc, char *argv[], char *envp[], t_data *data)
{
	if (argc != 5)
	{
		ft_printf("Error\n./pipex needs 4 arguments.\n");
		exit(EXIT_FAILURE);
	}
	data->pipex.exit = 0;
	get_path(envp, data);
	get_cmd(argv, data);
	data->file.infile = open(argv[1], O_RDONLY);
	if (data->file.infile == -1)
		fd_error(argv[1], INFILE, data);
	data->file.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->file.outfile == -1)
		fd_error(argv[4], OUTFILE, data);
	dup2(data->file.infile, STDIN_FILENO);
	close(data->file.infile);
	dup2(data->file.outfile, STDOUT_FILENO);
	close(data->file.outfile);
}
