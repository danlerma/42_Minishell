/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:55:19 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/02 20:24:32 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H

# define PARSE_H

# include <minishell.h>

char	**ft_split_mod_2(char const *s, char c);
//char	**split_data(char const *s);
t_list	*split_data(char const *s);
t_list	*split_data_rework(char const *s);
t_list	*make_lst(t_list *lst, char const *s);
t_lst	*create_nodes(char **argv);
t_lst	*create_nodes_rework(t_list *lst);
t_lst	*set_data_nodes(t_lst *nodes);
int		nodes_check_error(t_lst *list);
void	free_nodes(t_lst *nodes);
void	free_argv(t_list *argv, char *str);
char	*real_str(char *s);

#endif
