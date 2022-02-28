/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:55:19 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/02/24 12:53:45 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H

# define PARSE_H

# include <minishell.h>

char	**ft_split_mod_2(char const *s, char c);
char	**split_data(char const *s);
t_list	*make_lst(t_list *lst, char const *s);
t_lst	*create_nodes(char **argv);
t_lst	*set_data_nodes(t_lst *nodes);
void	free_nodes(t_lst *nodes);
void	free_argv(char **argv, char *str);

#endif
