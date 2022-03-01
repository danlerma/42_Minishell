/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:18:03 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/01 21:00:48 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	free_nodes(t_lst *nodes)
{
	int		nodes_i;
	t_lst	*aux;
	int		i;

	nodes_i = 1;
	while (nodes)
	{
		//printf("Node %i ...\n", nodes_i);
		//printf ("Puntero argv ->%p\n", aux->argv);
		i = 0;
		while (nodes->argv[i] != 0)
		{
			free(nodes->argv[i]);
			i++;
		}
		free(nodes->argv);
		free(nodes->type);
		free(nodes->flag);
		//printf("Liberado\n");
		aux = nodes->next;
		free(nodes);
		nodes = aux;
		nodes_i++;
	}
}

void	free_argv(t_list *argv, char *str)
{
	int		i;
	t_list	*aux;

	i = 0;
	//printf("puntero de la frase %p\n",str);
	free(str);
	while (argv)
	{
		aux = argv;
		argv = argv->next;
		free(aux->content);
		free (aux);
	}
	//printf("merde\n");
	//printf ("Puntero array de arrays ->%p\n", argv[i]);
	free(argv);
}
