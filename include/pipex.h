/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:07:13 by liyu-her          #+#    #+#             */
/*   Updated: 2024/10/15 13:46:29 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../mainlibft/libft.h"

int		ft_file(char *av, int i);
void	ft_exit(char *str, int i);
void	here_doc(char *lim, int ac);
char	*ft_path(char *cmd, char **ev);
void	ft_childprocess(char *av, char **ev);
void	ft_execute(char *av, char **ev);
int		ft_gnl(char **line);

#endif