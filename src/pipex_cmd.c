#include "../inc/pipex.h"

char	**pipex_cmd_arg(char *cmd)
{
	char	**cmd_arg;

	cmd_arg = NULL;
	cmd_arg = ft_split(cmd, ' ');
	return (cmd_arg);
}
