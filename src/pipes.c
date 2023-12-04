/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:59:05 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/04 11:32:56 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	child(int *fds, char **av, char **env)
{
	int	fd;

	(void)env;
	fd = open(av[1], 0);
	dup2(fd, 0);
	dup2(fds[1], 1);
	close(fds[0]);
	return (1);
}

int	parent(int *fds, char **av, char **env)
{
	int	fd;

	(void)env;
	fd = open(av[4], 1);
	dup2(fd, 1);
	dup2(fds[0], 0);
	close(fds[1]);
	return (1);
}
