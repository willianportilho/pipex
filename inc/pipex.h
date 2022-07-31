/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 05:11:31 by wportilh          #+#    #+#             */
/*   Updated: 2022/07/30 20:37:35 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft.h"
# include <unistd.h> // Checar depois se é necessário

typedef struct s_file
{
	char	*infile;
	char	*outfile;
}			t_file;

typedef struct s_arg
{
	char	**cmd;
	char	**cmd2;
}			t_arg;

typedef struct s_path
{
	char	**all_path;
	char	*cmd_p;
	char	*cmd2_p;
}			t_path;

typedef struct s_data
{
	t_file	file;
	t_path	path;
	t_arg	arg;
}			t_data;

void	pre_pipex(int argc, char *argv[], char *envp[], t_data *data);

#endif