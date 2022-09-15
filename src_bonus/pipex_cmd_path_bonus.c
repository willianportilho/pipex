/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd_path_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 02:20:17 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/16 01:29:14 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

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

char	*pipex_cmd_path(char *cmd, char *envp[])
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
			clean_cmd_ok(&temp, &temp2, &all_path);
			return (cmd_path);
		}
		free(temp);
		i++;
	}
	clean_cmd_error(&temp2, &cmd_path, &all_path, cmd);
	return (NULL);
}
