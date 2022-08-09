/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_clean_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 23:18:10 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/10 00:04:46 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	clean_cmd_error(char **temp2, char **cmd_path, char ***all_path)
{
	int	i;

	i = 0;
	while ((*all_path)[i])
		free((*all_path)[i++]);
	free(*all_path);
	free(*cmd_path);
	free(*temp2);
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
