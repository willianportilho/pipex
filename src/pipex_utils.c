/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 02:20:17 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/08 05:48:11 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static char	**get_path(char *envp[])
{
	int		i;
	char	*line;
	char	**all_path;

	i = 0;
	all_path = NULL;
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
		{
			line = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 5);
			all_path = ft_split(line, ':');
			free (line);
		}
		i++;
	}
	if (!all_path)
	{
		ft_printf("Error\n\"PATH\" not found.\n");
		free(all_path);
		exit(EXIT_FAILURE);
	}
	return (all_path);
}

char	*get_cmd_path(char *cmd, char *envp[])
{
	char	**all_path;
	char	*cmd_path;
	char	*temp;
	char	*temp2;
	int		i;

	all_path = get_path(envp);
	temp = NULL;
	cmd_path = NULL;
	i = 0;
	temp2 = ft_strjoin("/", cmd);
	while (all_path[i])
	{
		temp = ft_strjoin(all_path[i], temp2);
		if (access(temp, F_OK) == 0)
		{
			cmd_path = ft_strdup(temp);
			free(temp);
			i = 0;
			while (all_path[i])
				free(all_path[i++]);
			free(all_path);
			free(temp2);
			return(cmd_path);
		}
		free(temp);
		i++;
	}
	i = 0;
	while (all_path[i])
		free(all_path[i++]);
	free(all_path);
	if (!cmd_path)
		cmd_error(cmd);
	free(cmd_path);
	free(temp2);
	return(NULL);
}

void	pipex_pre(int argc, char *argv[], t_data *data)
{
	if (argc != 5)
	{
		ft_printf("Error\n./pipex needs 4 arguments.\n");
		exit(EXIT_FAILURE);
	}
	data->pipex.exit = 0;
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
