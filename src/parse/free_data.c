/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:18:03 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/09 13:50:24 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_nodes(t_lst *nodes, char *str)
{
	int		nodes_i;
	t_lst	*aux;
	int		i;

	free(str);
	nodes_i = 1;
	while (nodes)
	{
		i = 0;
		while (i < nodes->n_words)
		{
			free(nodes->argv[i]);
			i++;
		}
		free(nodes->argv);
		free(nodes->type);
		free(nodes->flag);
		aux = nodes->next;
		free(nodes);
		nodes = aux;
		nodes_i++;
	}
}

void	free_argv(t_list *argv)
{
	t_list	*aux;

	while (argv)
	{
		aux = argv;
		argv = argv->next;
		free(aux->content);
		free (aux);
	}
	free(argv);
}
