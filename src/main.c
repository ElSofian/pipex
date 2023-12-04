/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:33:18 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/04 08:37:51 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	display_banner(char *color)
{
	ft_printf("\n\t\t%s██████╗ ██╗██████╗ ███████╗██╗  ██╗%s", color, END);
	ft_printf("\n\t\t%s██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝%s", color, END);
	ft_printf("\n\t\t%s██████╔╝██║██████╔╝█████╗   ╚███╔╝%s", color, END);
	ft_printf("\n\t\t%s██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗%s", color, END);
	ft_printf("\n\t\t%s██║     ██║██║     ███████╗██╔╝ ██╗%s", color, END);
	ft_printf("\n\t\t%s╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝%s\n", color, END);
	ft_printf("⊱ ──────────────────────── {.⋅ ✯ ⋅.} ───────────────────────── ⊰\
			\n\n");
}

int	main(int ac, char **av)
{
	// int	pid = fork();
	// if (pid != 0)
	// 	ft_printf("Parent: %d\n", pid);
	// else
	// 	ft_printf("Child: %d\n", pid);
	// return (0);
	int		i;
	
	if (check(ac, av) == -1)
		return (0);
	i = 0;
	while (av[i])
	{
		ft_printf("%s\n", av[i]);
		i++;
	}
	return (0);
}
