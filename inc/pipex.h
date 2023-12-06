/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:33:38 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/06 17:11:46 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define END "\033[0m"

int		check(int ac, char **av);
int		check_args(int ac, char **av);
int		check_cmds(char **av);
int		check_files(char **av);
int		child(int *fds, char **av, char **env);
int		parent(int *fds, char **av, char **env);
char	*get_cmd_name(char *cmd);
char	*get_cmd_path(char *cmd, char **env);

#endif