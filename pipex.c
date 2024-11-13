/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:01:12 by liyu-her          #+#    #+#             */
/*   Updated: 2024/10/07 20:05:50 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"

char	*ft_path(char *cmd, char **ev)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(ev[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(ev[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

int	ft_file(char *av, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(av, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(av, O_RDONLY, 0777);
	if (file == -1)
		ft_exit("File cannot be opened\n", 1);
	return (file);
}

int	main(int ac, char **av, char **ev)
{
	int	i;
	int	filein;
	int	fileout;

	if (ac >= 5)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0)
		{
			i = 3;
			fileout = ft_file(av[ac - 1], 0);
			here_doc(av[2], ac);
		}
		else
		{
			i = 2;
			fileout = ft_file(av[ac - 1], 1);
			filein = ft_file(av[1], 2);
			dup2(filein, STDIN_FILENO);
		}
		while (i < ac - 2)
			ft_childprocess(av[i++], ev);
		dup2(fileout, STDOUT_FILENO);
		ft_execute(av[ac - 2], ev);
	}
	ft_exit("Bad Argument\n", 0);
}
