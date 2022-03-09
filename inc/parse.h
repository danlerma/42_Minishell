/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:55:19 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/09 13:36:39 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H

# define PARSE_H

# include <minishell.h>

//get raw words
t_list	*split_data_rework(char const *s);
t_list	*make_lst(t_list *lst, char const *s);

//ceate nodes from raw words
t_lst	*create_nodes_rework(t_list *lst, t_mirage *env);
t_lst	*set_data_nodes(t_lst *nodes, t_mirage *env);
int		nodes_check_error(t_lst *list);

//free malloced data
void	free_nodes(t_lst *nodes);
void	free_argv(t_list *argv, char *str);

//refine raw word
char	*real_str(char *s, t_mirage *env);

//expandable var
char	*get_variable_value(char *s, t_mirage *env);
int		get_variable_tam(char *s);
char	*getvariable(char *var, t_mirage *env);

//show structured data
void	show_recorded_lst(t_list *argv);
void	show_nodes(t_lst *nodes);

#endif
