/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:33:18 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/04 11:06:47 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int ac, char **av, char **env)
{
	int	fd[2];
	pid_t	pid;

	// int	i = 0;
	// while (env[i])
	// {
	// 	ft_printf("env[%d]: %s\n", i, env[i]);
	// 	i++;
	// }
	if (check(ac, av) == -1)
		return (1);
	if (pipe(fd) < 0)
	{
		ft_printf("Pipe failed.\n");
		return (2);
	}
	pid = fork();
	if (pid < 0)
	{
		ft_printf("Making the child process has failed.\n");
		return (3);
	}
	if (pid == 0)
	{
		if (child(fd, av, env) < 0)
			return (4);
	}
	if (parent(fd, av, env) < 0)
		return (5);
	return (0);
}
