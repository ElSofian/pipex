/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 08:07:44 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/04 11:10:41 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	check(int ac, char **av)
{
	if (check_args(ac, av) == -1
		|| check_files(av) == -1)
		return (-1);
	return (1);
}

int	check_args(int ac, char **av)
{
	if (ac != 5)
	{
		ft_printf("Not enough or too many arguments.\n");
		return (-1);
	}
	if (*(av[1]) == '\0' || *(av[2]) == '\0')
	{
		ft_printf("You provided one or two empty command(s).\n");
		return (-1);
	}
	return (1);
}

int	check_files(char **av)
{
	int	res;
	int	ret;
	int	fd;
	int	fd2;

	res = 1;
	fd = open(av[1], O_RDONLY, 0777);
	fd2 = open(av[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	ret = read(fd, 0, 0);
	if (fd < 0 || ret < 0 || fd2 < 0)
		res = -1;
	if (fd < 0)
		ft_printf("Couldn't open the first file.\n");
	if (fd2 < 0)
		ft_printf("Couldn't open the second file.\n");
	if (ret < 0)
		ft_printf("Couldn't read the first file.\n");
	close(fd);
	close(fd2);
	return (res);
}
