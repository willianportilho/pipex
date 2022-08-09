/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:26:13 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/10 00:01:50 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	fd_error(char *file_err, int check, t_data *data)
{
	char	*str;

	str = ft_strjoin("pipex: ", file_err);
	perror(str);
	free(str);
	if (check == OUTFILE)
		exit (EXIT_FAILURE);
	else
	{
		if (access(file_err, F_OK) != 0)
			data->pipex.exit = 1;
	}
}

void	cmd_error(char *cmd_err)
{
	char	*str;

	str = ft_strjoin("pipex: ", cmd_err);
	perror(str);
	free(str);
}

void	quotes_error(void)
{
	ft_printf("Error\nBad input in single quotes (\') or (\") double quotes.\n");
	exit(EXIT_FAILURE);
}
