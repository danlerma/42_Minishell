/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:18:03 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/23 17:01:16 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	free_nodes(t_lst *nodes)
{
	int		nodes_i;
	t_lst	*aux;

	aux = nodes;
	nodes_i = 1;
	while (aux)
	{
		//printf("Node %i ...\n", nodes_i);
		//printf ("Puntero argv ->%p\n", aux->argv);
		free(aux->argv);
		free(aux->type);
		free(aux->flag);
		//printf("Liberado\n");
		free(aux);
		aux = aux->next;
		nodes_i++;
	}
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != 0)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
