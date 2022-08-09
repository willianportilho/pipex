/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:29:18 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/10 01:14:55 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

static void	pipex_pre(int argc, char *argv[], t_data *data)
{
	int	arguments;

	arguments = 0;
	if (argc < 5)
	{
		ft_printf("Error\n./pipex needs 4 or more arguments.\n");
		exit(EXIT_FAILURE);
	}
	data->pipex.exit = 0;
	data->file.infile = open(argv[1], O_RDONLY);
	if (data->file.infile == -1)
		fd_error(argv[1], INFILE, data);
	data->file.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->file.outfile == -1)
		fd_error(argv[4], OUTFILE, data);
	while (argv[arguments])
		arguments++;
	arguments += -3;
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	pipex_pre(argc, argv, &data);
	pipex(&data, argv, envp);
	return (data.pipex.exit);
}
