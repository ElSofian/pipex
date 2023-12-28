/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:54:21 by soelalou          #+#    #+#             */
/*   Updated: 2023/12/14 13:04:41 by soelalou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_path_dirs(char **env)
{
	int		i;
	char	**dirs;

	i = 0;
	while (ft_strncmp("PATH", env[i], 4) != 0)
		i++;
	dirs = ft_split(env[i] + 5, ':');
	if (!dirs)
		return (NULL);
	return (dirs);
}

char	*get_cmd_name(char *cmd)
{
	int		i;
	int		j;
	char	*cmd_name;

	i = 0;
	while (cmd[i] >= 'a' && cmd[i] <= 'z')
		i++;
	j = 0;
	cmd_name = (char *)malloc(sizeof(char) * (i + 1));
	if (!cmd_name)
		return (NULL);
	while (j < i)
	{
		cmd_name[j] = cmd[j];
		j++;
	}
	cmd_name[j] = '\0';
	return (cmd_name);
}

char	*get_cmd_path(char *cmd, char **env)
{
	int		i;
	int		len;
	char	*path;
	char	**dirs;

	i = -1;
	path = NULL;
	dirs = get_path_dirs(env);
	if (!dirs)
		return (NULL);
	while (dirs[++i])
	{
		len = ft_strlen(dirs[i]) + ft_strlen(cmd) + 2;
		path = (char *)malloc(sizeof(char) * len);
		if (!path)
			return (ft_freetab(dirs), NULL);
		ft_strcpy(path, dirs[i]);
		ft_strcat(path, "/");
		ft_strcat(path, cmd);
		if (access(path, F_OK | X_OK) == 0)
			return (path);
		free(path);
	}
	return (ft_freetab(dirs), NULL);
}
