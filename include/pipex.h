/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42kl.edy.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:07:13 by liyu-her          #+#    #+#             */
/*   Updated: 2024/11/14 20:57:24 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"

int		ft_file(char *av, int i);
void	ft_exit(char *str, int i);
void	here_doc(char *lim, int ac);
char	*ft_path(char *cmd, char **ev);
void	ft_childprocess(char *av, char **ev);
void	ft_execute(char *av, char **ev);
int		ft_gnl(char **line);

#endif