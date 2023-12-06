/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:07:44 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/06 17:03:44 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	check(int ac, char **av)
{
	if (check_args(ac, av) == -1 || check_files(av) == -1
		|| check_cmds(av) == -1)
		return (-1);
	return (1);
}

int	check_cmds(char **av)
{
	int	i;

	i = 0;
	while (av[1][i])
	{
		if (av[1][i] <= 'a' && av[1][i] >= 'z')
			return (-1);
		i++;
	}
	i = 0;
	while (av[2][i])
	{
		if (av[2][i] <= 'a' && av[2][i] >= 'z')
			return (-1);
		i++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	if (ac != 5)
	{
		perror("[Args]: Not enough or too many arguments.");
		return (-1);
	}
	if (ft_strcmp(av[1], "") == 0 || ft_strcmp(av[2], "") == 0
		|| ft_strcmp(av[3], "") == 0 || ft_strcmp(av[4], "") == 0)
	{
		perror("[Args]: One of the arguments is empty.");
		return (-1);
	}
	return (1);
}

int	check_files(char **av)
{
	int	res;
	int	ret;
	int	ret2;
	int	fd;
	int	fd2;

	res = 1;
	fd = open(av[1], O_RDONLY, 0777);
	fd2 = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	ret = read(fd, 0, 0);
	ret2 = access(av[4], W_OK);
	if (fd < 0 || fd2 < 0 || ret < 0 || ret2 < 0)
		res = -1;
	if (fd < 0)
		perror("[Fd]");
	if (fd2 < 0)
		perror("[Fd2]");
	if (ret < 0)
		perror("[Ret]");
	if (ret2 < 0)
		perror("[Ret2]");
	close(fd);
	close(fd2);
	return (res);
}
