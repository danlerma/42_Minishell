/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_create_rework.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:30:16 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/16 13:36:41 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*get_word(t_list *lst)
{
	char	*aux;

	aux = ft_strdup(lst->content);
	return (aux);
}

int	get_n_words_per_token(t_list *lst)
{
	int		i;
	t_list	*aux;
	char	*str_aux;

	i = 0;
	aux = lst;
	while (aux)
	{
		if (aux->content == 0)
			break ;
		str_aux = get_word(aux);
		if (ft_strncmp(str_aux, "|", 1) == 0)
		{
			free(str_aux);
			break ;
		}
		free(str_aux);
		i++;
		aux = aux->next;
	}
	return (i);
}

void	set_nodes_data_rework(t_lst *nodes, t_list *lst)
{
	t_list	*aux;
	t_lst	*aux_nodes;
	int		i;

	aux_nodes = nodes;
	aux = lst;
	while (aux)
	{
		i = 0;
		aux_nodes->n_words = get_n_words_per_token(aux);
		aux_nodes->argv = ft_calloc(sizeof(char *), aux_nodes->n_words + 1);
		aux_nodes->type = ft_calloc(sizeof(int *), aux_nodes->n_words);
		aux_nodes->flag = ft_calloc(sizeof(int *), aux_nodes->n_words);
		aux_nodes->built = 0;
		while (i < aux_nodes->n_words)
		{
			aux_nodes->argv[i] = get_word(aux);
			aux = aux->next;
			i++;
		}
		if (aux)
			aux = aux->next;
		aux_nodes = aux_nodes->next;
	}
}

t_lst	*make_nodes_rework(t_list *lst)
{
	t_list	*aux;
	t_lst	*nodes;
	t_lst	*aux_nodes;
	char	*str_aux;

	aux = lst;
	nodes = ft_calloc(sizeof(t_lst), 1);
	aux_nodes = nodes;
	while (aux)
	{
		str_aux = get_word(aux);
		if (ft_strncmp(str_aux, "|", 1) == 0)
		{
			aux_nodes->next = ft_calloc(sizeof(t_lst), 1);
			aux_nodes = aux_nodes->next;
		}
		free(str_aux);
		aux = aux->next;
	}
	return (nodes);
}

t_lst	*create_nodes_rework(char const *s, t_mirage *env)
{
	t_lst	*nodes;
	t_list	*lst;

	lst = split_data_rework(s);
	nodes = make_nodes_rework(lst);
	set_nodes_data_rework(nodes, lst);
	nodes = set_data_nodes(nodes, env);
	free_argv(lst);
	return (nodes);
}
