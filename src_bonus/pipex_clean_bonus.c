/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_clean_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 23:18:10 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/16 01:29:10 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	clean_alloc(t_data *data)
{
	int	i;

	i = -1;
	if (data->pipex.pipes)
	{
		while (data->pipex.pipes[++i])
			free(data->pipex.pipes[i]);
	}
	free(data->pipex.pipes);
	data->pipex.pipes = NULL;
	free(data->pipex.pid);
	data->pipex.pid = NULL;
}

void	clean_cmd_error(char **temp2, char **cmd_path, \
char ***all_path, char *cmd)
{
	int		i;
	char	*temp;
	char	*cmd_join;

	i = 0;
	temp = ft_strjoin("pipex: ", cmd);
	cmd_join = ft_strjoin(temp, ": command not found\n");
	while ((*all_path)[i])
		free((*all_path)[i++]);
	free(*all_path);
	free(*cmd_path);
	free(*temp2);
	free(temp);
	ft_putstr_fd(cmd_join, 2);
	free(cmd_join);
}

void	clean_cmd_ok(char **temp, char **temp2, char ***all_path)
{
	int	i;

	i = 0;
	while ((*all_path)[i])
		free((*all_path)[i++]);
	free(*all_path);
	free(*temp);
	free(*temp2);
}

void	process_clean(char **cmd_path, char ***cmd_arg)
{
	int	i;

	i = 0;
	free(*cmd_path);
	while ((*cmd_arg)[i])
		free((*cmd_arg)[i++]);
	free(*cmd_arg);
	exit(NO_CMD);
}
