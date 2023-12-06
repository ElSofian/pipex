/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:33:18 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/06 18:02:01 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;
	
	if (check(ac, av) == -1)
		return (1);
	if (pipe(fd) < 0)
	{
		perror("[Pipe]");
		return (2);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("[Pid]");
		return (3);
	}
	if (pid == 0)
	{
		child(fd, av, env);
	}
	wait(NULL);
	parent(fd, av, env);
	return (0);
}

// int	main(int ac, char **av, char **env)
// {
// 	// int	i;

// 	(void)ac;
// 	(void)av;
// 	// i = 0;
// 	// while (env[i])
// 	// {
// 	// 	ft_printf("env[%d]: %s\n", i, env[i]);
// 	// 	i++;
// 	// }
// 	ft_printf("env[25]: %s\n", env[25]);
// 	ft_printf("cmd name: %s\n", get_cmd_name("ls -l"));
// 	ft_printf(get_cmd_path(get_cmd_name("ls -l"), env));
// }
