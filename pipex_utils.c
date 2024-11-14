/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edy.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:05:53 by liyu-her          #+#    #+#             */
/*   Updated: 2024/11/14 20:56:22 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/pipex.h"

void	ft_execute(char *av, char **ev)
{
	char	**cmd;
	int		i;
	char	*path;

	i = 0;
	cmd = ft_split(av, ' ');
	path = ft_path(cmd[0], ev);
	if (!path)
	{
		while (cmd[i])
			free(cmd[i]);
		free(cmd[i]);
		ft_exit("Path Error\n", 1);
	}
	if (execve(path, cmd, ev) == -1)
		ft_exit("Error\n", 1);
}

void	ft_childprocess(char *av, char **ev)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_exit("Pipe Failed\n", 1);
	pid = fork();
	if (pid == -1)
		ft_exit("Pid Failed\n", 1);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		ft_execute(av, ev);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	ft_gnl(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}

void	here_doc(char *lim, int ac)
{
	pid_t	cursor;
	int		fd[2];
	char	*line;

	if (ac < 6)
		ft_exit("Bad Argument\n", 1);
	if (pipe(fd) == -1)
		ft_exit("Piped Failed\n", 0);
	cursor = fork();
	if (cursor == 0)
	{
		close(fd[0]);
		while (ft_gnl(&line))
		{
			if (ft_strncmp(line, lim, ft_strlen(lim)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void	ft_exit(char *str, int i)
{
	if (i == 0)
	{
		perror(str);
		exit(EXIT_SUCCESS);
	}
	else
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
}
