/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_set_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:15:05 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/23 17:30:37 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	check_is_flagged(char *str)
{
	if (str[0] == '"' && str[ft_strlen(str) - 1] == '"')
		return (1);
	return (0);
}

static t_lst	*set_flags_nodes(t_lst *node)
{
	int		i;
	char	*aux;

	i = 0;
	while (node->argv[i] != 0)
	{
		if (check_is_flagged(node->argv[i]))
		{
			node->flag[i] = 1;
			aux = node->argv[i];
			free(node->argv[i]);
			node->argv[i] = ft_substr(aux, 1, ft_strlen(aux) - 2);
		}
		else
			node->flag[i] = 0;
		i++;
	}
	return (node);
}

static t_lst	*set_types_nodes(t_lst *node)
{
	int		i;

	i = 0;
	while (node->argv[i] != 0)
	{
		if (ft_strncmp(node->argv[i], "<", sizeof(node->argv[i])) == 0)
			node->type[i] = 2;
		else if (ft_strncmp(node->argv[i], ">", sizeof(node->argv[i])) == 0)
			node->type[i] = 4;
		else if (ft_strncmp(node->argv[i], "<<", sizeof(node->argv[i])) == 0)
			node->type[i] = 6;
		else if (ft_strncmp(node->argv[i], ">>", sizeof(node->argv[i])) == 0)
			node->type[i] = 7;
		else
			node->type[i] = 1;
		if (i > 0 && (node->type[i - 1] == 2 || node->type[i - 1] == 4 \
			|| node->type[i - 1] == 7))
			node->type[i] = 5;
		if (i > 0 && (node->type[i - 1] == 6))
			node->type[i] = 8;
		i++;
	}
	return (node);
}

t_lst	*set_data_nodes(t_lst *nodes)
{
	t_lst	*aux;

	aux = nodes;
	while (aux)
	{
		aux = set_flags_nodes(aux);
		aux = set_types_nodes(aux);
		aux = aux->next;
	}
	return (nodes);
}
