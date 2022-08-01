/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 02:20:17 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/01 03:26:38 by wportilh         ###   ########.fr       */
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
		exit(EXIT_FAILURE);
	}
}

static void	get_cmd(char *argv[], t_data *data)
{
	int		i;
	char	*temp;
	char	*temp2;

	i = 0;
	data->path.cmd_p = NULL;
	data->path.cmd2_p = NULL;
	data->arg.cmd = ft_split(argv[2], ' '); // Depois vou resolver a questão dos espaços fazendo uma função que leia isso
	data->arg.cmd2 = ft_split(argv[3], ' ');
	while (data->path.all_path[i])
	{
		temp = ft_strjoin(data->path.all_path[i], \
		ft_strjoin("/", data->arg.cmd[0]));
		temp2 = ft_strjoin(data->path.all_path[i++], \
		ft_strjoin("/", data->arg.cmd2[0]));
		if (!access(temp, F_OK) && ((data->path.cmd_p) == NULL))
			data->path.cmd_p = ft_strdup(temp);
		if (!access(temp2, F_OK) && ((data->path.cmd2_p) == NULL))
			data->path.cmd2_p = ft_strdup(temp2);
		free(temp);
		free(temp2);
	}
	if (!data->path.cmd_p)
		ft_printf("Error:\ncmd1 not found.\n");
	if (!data->path.cmd2_p)
		ft_printf("Error:\ncmd2 not found.\n");
}

void	pre_pipex(int argc, char *argv[], char *envp[], t_data *data)
{
	if (argc != 5)
	{
		ft_printf("Error\n./pipex needs 4 arguments.\n");
		exit(EXIT_FAILURE);
	}
	get_path(envp, data);
	get_cmd(argv, data);
	data->file.infile = open(argv[1], O_RDONLY | O_CREAT, 0777);
	data->file.outfile = open(argv[4], O_WRONLY | O_CREAT, 0777);
}
