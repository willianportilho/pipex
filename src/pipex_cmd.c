/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 02:24:33 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/09 04:32:38 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	cut_value(char ***cmd_arg)
{
	int		i;
	int		i2;
	char	*temp;

	i = 0;
	i2 = 0;
	while ((*cmd_arg)[i])
	{
		if (((*cmd_arg)[i][i2] == '\'') || ((*cmd_arg)[i][i2] == '\"'))
		{
			temp = ft_substr((*cmd_arg)[i], 1, ft_strlen((*cmd_arg)[i]) - 2);
			free ((*cmd_arg)[i]);
			(*cmd_arg)[i] = temp;
		}
		i++;
	}
}

static void	turn_back(char ***cmd_arg)
{
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	while ((*cmd_arg)[i])
	{
		while ((*cmd_arg)[i][i2])
		{
			if (((*cmd_arg)[i][i2] == '\'') || ((*cmd_arg)[i][i2] == '\"'))
			{
				i2++;
				while (((*cmd_arg)[i][i2] != '\'') \
				&& ((*cmd_arg)[i][i2] != '\"') && ((*cmd_arg)[i][i2]))
				{
					if ((*cmd_arg)[i][i2] == '`')
						(*cmd_arg)[i][i2] = ' ';
					i2++;
				}
			}
			i2++;
		}
		i++;
		i2 = 0;
	}
}

static void	swap_value(char **cmd, t_data *data)
{
	int		i;

	i = 0;
	while ((*cmd)[i])
	{
		if (((*cmd)[i] == '\'') || ((*cmd)[i] == '\"'))
		{
			i++;
			while ((((*cmd)[i] != '\'') && ((*cmd)[i] != '\"')) && ((*cmd)[i]))
			{
				if ((*cmd)[i] == ' ')
				{
					(*cmd)[i] = '`';
					data->pipex.check = 1;
				}
				i++;
			}
		}
		i++;
	}
}

char	**pipex_cmd_arg(char *cmd, t_data *data)
{
	char	**cmd_arg;

	cmd_arg = NULL;
	data->pipex.check = 0;
	swap_value(&cmd, data);
	cmd_arg = ft_split(cmd, ' ');
	if (data->pipex.check == 1)
	{
		data->pipex.check = 0;
		turn_back(&cmd_arg);
		cut_value(&cmd_arg);
	}
	return (cmd_arg);
}
