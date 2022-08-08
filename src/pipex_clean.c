/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 23:18:10 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/08 23:20:58 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipex_clean(char **cmd_path, char ***cmd_arg)
{
	int	i;

	i = 0;
	free(*cmd_path);
	while ((*cmd_arg)[i])
		free((*cmd_arg)[i++]);
	free(*cmd_arg);
	exit(127);
}
