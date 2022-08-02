/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:49:04 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/03 01:05:45 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipex_clear(t_data *data)
{
	int	i;

	i = 0;
	while (data->arg.cmd[i])
		free(data->arg.cmd[i++]);
	i = 0;
	while (data->arg.cmd2[i])
		free(data->arg.cmd2[i++]);
	free(data->arg.cmd);
	free(data->arg.cmd2);
	free(data->path.cmd_path);
	free(data->path.cmd2_path);
	free (data->path.all_path);
}
