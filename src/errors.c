/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:07:44 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/14 13:00:09 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static int	check_cmds(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i] && i < ac - 2)
	{
		j = -1;
		if (ft_strcmp(av[i], "") == 0)
		{
			perror("[Args]: One of the command/file is empty.");
			return (-1);
		}
		while (av[i][++j])
		{
			if (av[i][j] <= 'a' && av[i][j] >= 'z')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_files(int ac, char **av)
{
	int	res;
	int	ret;
	int	ret2;
	int	fd;
	int	fd2;

	res = 1;
	fd = open(av[1], O_RDONLY, 0777);
	fd2 = open(av[ac - 1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	ret = read(fd, 0, 0);
	ret2 = access(av[ac - 1], W_OK);
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

void	check(int ac, char **av)
{
	if (ac < 5)
		perror("[Args]: Not enough arguments.");
	if (check_files(ac, av) == -1 || check_cmds(ac, av) == -1
		|| ac < 5)
		exit(EXIT_FAILURE);
}
