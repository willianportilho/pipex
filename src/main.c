/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:29:18 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/22 18:03:24 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include <stdio.h>

int	main(void)
{
	int	id;

	id = fork();
	ft_printf("Hello World %d Error\n", id);
}
