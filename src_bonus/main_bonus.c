/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:29:18 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/16 01:29:03 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

static void	alloc_resources(t_data *data)
{
	int	i;

	i = -1;
	data->pipex.pipes = malloc((data->pipex.amount_cmd + 1) * sizeof(int *));
	while (++i < data->pipex.amount_cmd)
		data->pipex.pipes[i] = malloc(data->pipex.amount_cmd * sizeof(int));
	data->pipex.pid = malloc(data->pipex.amount_cmd + 1 * sizeof(int));
}

static void	pipex_pre(int argc, char *argv[], t_data *data)
{
	if (argc < 5)
	{
		ft_printf("Error\n./pipex needs 4 arguments.\n");
		exit(EXIT_FAILURE);
	}
	data->pipex.i = -1;
	data->pipex.exit = 0;
	data->pipex.tmpin = dup(0);
	data->pipex.tmpout = dup(1);
	data->pipex.amount_cmd = argc - 3;
	data->file.infile = open(argv[1], O_RDONLY);
	if (data->file.infile == -1)
		fd_error(argv[1], INFILE, data);
	data->file.outfile = open(argv[argc - 1], \
	O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->file.outfile == -1)
		fd_error(argv[argc - 1], OUTFILE, data);
	alloc_resources(data);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	pipex_pre(argc, argv, &data);
	pipex(&data, argv, envp);
	clean_alloc(&data);
	return (data.pipex.exit);
}
