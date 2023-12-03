/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:33:18 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/03 17:43:39 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(void)
{
	int	pid = fork();
	if (pid != 0)
		ft_printf("Parent: %d\n", pid);
	else
		ft_printf("Child: %d\n", pid);
	return (0);
}