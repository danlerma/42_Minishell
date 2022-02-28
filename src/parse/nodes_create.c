/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:30:16 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/23 15:41:17 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	number_nodes(char **argv)
{
	int		i;
	int		n_nodes;

	i = 0;
	n_nodes = 1;
	while (argv[i] != 0)
	{
		if (ft_strncmp(argv[i], "|", 1) == 0)
			n_nodes++;
		i++;
	}
	//printf("Hay %i nodos\n",n_nodes);
	return (n_nodes);
}

static int	*sizesinsidenodes(char **argv, int n_nodes)
{
	int	*s_inside_nodes;
	int	i;
	int	j;
	int	size;

	s_inside_nodes = ft_calloc(sizeof(int), n_nodes + 1);
	i = 0;
	size = 0;
	j = 0;
	while (argv[i] != 0)
	{
		if (ft_strncmp(argv[i], "|", 1) == 0)
		{
			s_inside_nodes[j] = size;
			size = -1;
			j++;
		}
		size++;
		i++;
	}
	s_inside_nodes[j] = size;
	return (s_inside_nodes);
}

static t_lst	*declare_nodes(char **argv)
{
	t_lst	*nodes;
	t_lst	*aux;
	int		*s_inside_nodes;
	int		i;
	int		n_nodes;

	i = 0;
	n_nodes = number_nodes(argv);
	nodes = ft_calloc(sizeof(t_lst), 1);
	aux = nodes;
	s_inside_nodes = sizesinsidenodes(argv, n_nodes);
	while (i < n_nodes)
	{
		aux->type = ft_calloc(sizeof(int), s_inside_nodes[i]);
		aux->flag = ft_calloc(sizeof(int), s_inside_nodes[i]);
		aux->argv = ft_calloc(sizeof(char *), s_inside_nodes[i] + 1);
		if (i + 1 < n_nodes)
		{
			aux->next = ft_calloc(sizeof(t_lst), 1);
			aux = aux->next;
		}
		i++;
	}
	free(s_inside_nodes);
	return (nodes);
}
//printf("declarando con tamaño %i\n",s_inside_nodes[i]);
//printf("Tamaño de los arrays creados %i -> en la lista", s_inside_nodes[i]);

static t_lst	*fill_nodes(char **argv, t_lst	*nodes)
{
	t_lst	*aux;
	int		i;
	int		j;

	i = 0;
	j = 0;
	aux = nodes;
	while (argv[i] != 0)
	{
		if (ft_strncmp(argv[i], "|", 1) != 0)
		{
			aux->argv[j] = argv[i];
			aux->type[j] = -1;
			aux->flag[j] = -1;
			j++;
		}
		else
		{
			aux = aux->next;
			j = 0;
		}
		i++;
	}
	return (nodes);
}
//printf("New node set : \n");
	//printf("Frase -> %s\n", argv[i]);
	//printf("Frase copiada -> %s\n", aux->argv[j]);
	//printf("type -> %i\n", aux->type[j]);
	//printf("flag -> %i\n", aux->flag[j]);
	//printf("detecta una pipe\n");

t_lst	*create_nodes(char **argv)
{
	t_lst	*nodes;

	nodes = declare_nodes(argv);
	nodes = fill_nodes(argv, nodes);
	return (nodes);
}
/*t_lst	*aux;
	aux = nodes;
	while (aux->next != 0)
	{
		printf("Nodo %p \n",aux);
		aux = aux->next;
	}
	printf("Nodo %p \n",aux);*/
	