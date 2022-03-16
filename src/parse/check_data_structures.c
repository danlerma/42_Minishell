/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_structures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:14:46 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/16 13:38:31 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
//Estas funciones deben de ser borradas antes de entregar , no aportan nada
//al codigo, solo sirven para checkear la integridad de los nodos y el parseo
void	show_recorded_lst(t_list *argv)
{
	t_list	*aux;

	aux = argv;
	while (aux)
	{
		aux = aux->next;
	}
}

void	show_nodes(t_lst *nodes)
{
	int		i;
	int		nodes_i;
	t_lst	*aux;

	aux = nodes;
	nodes_i = 1;
	i = 0;
	while (aux)
	{
		printf("Node %i :\n", nodes_i);
		printf("Built in - %i\n", aux->built);
		while (aux->argv[i] != 0)
		{
			printf("Argv - %s - %p\n", aux->argv[i], aux->argv[i]);
			printf("Type - %i\n", aux->type[i]);
			printf("Flag - %i\n", aux->flag[i]);
			printf("\n");
			i++;
		}
		i = 0;
		aux = aux->next;
		nodes_i++;
	}
}
