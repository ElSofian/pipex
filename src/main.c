/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:33:18 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/14 13:04:02 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static int	execute_cmd(char *cmd_name, char **env)
{
	char	*cmd_path;
	char	**cmd;

	cmd = ft_split(cmd_name, ' ');
	cmd_path = get_cmd_path(cmd[0], env);
	if (execve(cmd_path, cmd, env) == -1)
	{
		free(cmd_path);
		ft_freetab(cmd);
		perror("[Executing command]");
		return (-1);
	}
	ft_freetab(cmd);
	free(cmd_path);
	return (0);
}

static int	create_pipe(int cmd_pos, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;
	char	*cmd_path;
	char	**cmd;

	cmd = NULL;
	cmd_path = NULL;
	if (pipe(fd) < 0)
		return (perror("[Pipe]"), 2);
	pid = fork();
	if (pid < 0)
		return (perror("[Pid]"), 3);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute_cmd(av[cmd_pos], env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	fd0;
	int	fd1;

	check(ac, av);
	i = 2;
	fd0 = open(av[1], O_RDONLY, 0777);
	fd1 = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd0 < 0 || fd1 < 0)
		return (-1);
	dup2(fd0, STDIN_FILENO);
	while (i < ac - 2)
	{
		if (create_pipe(i, av, env) != 0)
		{
			perror("[Pipe execution]");
			return (1);
		}
		i++;
	}
	dup2(fd1, STDOUT_FILENO);
	execve(get_cmd_path(ft_split(av[ac - 2], ' ')[0], env),
		ft_split(av[ac - 2], ' '), env);
	return (0);
}
