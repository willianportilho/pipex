/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:29:18 by wportilh          #+#    #+#             */
/*   Updated: 2022/08/08 05:02:04 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	pipex_pre(argc, argv, &data);
	pipex(&data, argv, envp);
	return (data.pipex.exit);
}
