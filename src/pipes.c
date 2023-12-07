/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:59:05 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/07 10:11:12 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	child(int *fds, char **av, char **env)
{
	int		fd;
	char	*cmd_path;
	char	**cmd;

	cmd = ft_split(av[2], ' ');
	cmd_path = get_cmd_path(cmd[0], env);
	fd = open(av[1], O_RDONLY, 0777);
	close(fds[0]);
	dup2(fd, STDIN_FILENO);
	dup2(fds[1], STDOUT_FILENO);
	if (execve(cmd_path, cmd, env) == -1)
	{
		free(cmd_path);
		ft_freetab(cmd);
		perror("[Executing command]");
		return (-1);
	}
	ft_freetab(cmd);
	free(cmd_path);
	return (1);
}

int	parent(int *fds, char **av, char **env)
{
	int		fd;
	char	**cmd;
	char	*cmd_path;

	cmd = ft_split(av[3], ' ');
	cmd_path = get_cmd_path(cmd[0], env);
	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	close(fds[1]);
	dup2(fd, STDOUT_FILENO);
	dup2(fds[0], STDIN_FILENO);
	if (execve(cmd_path, cmd, env) == -1)
	{
		free(cmd_path);
		ft_freetab(cmd);
		perror("[Executing command]");
		return (-1);
	}
	ft_freetab(cmd);
	free(cmd_path);
	return (1);
}
