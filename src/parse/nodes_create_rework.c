/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_create_rework.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:30:16 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/03 15:25:26 by mortiz-d         ###   ########.fr       */
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
	int		n_words;

	aux_nodes = nodes;
	aux = lst;
	//printf("Circus begin\n");
	while (aux)
	{
		i = 0;
		//printf("Busca desde la palabra :%s\n",aux->content);
		n_words = get_n_words_per_token(aux);
		//printf("Nwords : %i\n", n_words);
		aux_nodes->argv = ft_calloc(sizeof(char *), n_words + 1);
		aux_nodes->type = ft_calloc(sizeof(int *), n_words);
		aux_nodes->flag = ft_calloc(sizeof(int *), n_words);
		while (i < n_words)
		{
			aux_nodes->argv[i] = get_word(aux);
			//printf("palabra :%s\n",aux_nodes->argv[i]);
			aux = aux->next;
			i++;
		}
		//printf("Sigue al siguiente palabra tras leer\n");
		if (aux)
			aux = aux->next;
		//printf("aux node %p\n", aux_nodes);
		//printf("aux node->next %p\n", aux_nodes->next);
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

t_lst	*create_nodes_rework(t_list *lst)
{
	t_lst	*nodes;

	nodes = make_nodes_rework(lst);
	printf("Termina de crear las cosas y nos disponemos a llenarlas\n");
	set_nodes_data_rework(nodes, lst);
	return (nodes);
}
