/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_set_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:15:05 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/16 13:37:57 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static t_lst	*set_real_words(t_lst *node, t_mirage *env)
{
	int		i;
	char	*aux;

	i = 0;
	while (i < node->n_words)
	{
		aux = node->argv[i];
		node->argv[i] = real_str(aux, env);
		free(aux);
		i++;
	}
	return (node);
}

static int	is_builtin(char *str)
{
	if (ft_strncmp(str, "echo", sizeof(str)) == 0)
		return (1);
	if (ft_strncmp(str, "cd", sizeof(str)) == 0)
		return (1);
	if (ft_strncmp(str, "pwd", sizeof(str)) == 0)
		return (1);
	if (ft_strncmp(str, "export", sizeof(str)) == 0)
		return (1);
	if (ft_strncmp(str, "unset", sizeof(str)) == 0)
		return (1);
	if (ft_strncmp(str, "exit", sizeof(str)) == 0)
		return (1);
	return (0);
}

static t_lst	*set_flags_nodes(t_lst *node)
{
	int		i;

	i = 0;
	while (i < node->n_words)
	{
		if (node->type[i] == 8)
			node->flag[i] = 1;
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
	while (i < node->n_words)
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
		if (is_builtin(node->argv[i]))
			node->built = 1;
		if (i > 0 && (node->type[i - 1] == 2 || node->type[i - 1] == 4 \
			|| node->type[i - 1] == 7))
			node->type[i] = 5;
		if (i > 0 && (node->type[i - 1] == 6))
			node->type[i] = 8;
		i++;
	}
	return (node);
}

t_lst	*set_data_nodes(t_lst *nodes, t_mirage *env)
{
	t_lst	*aux;

	aux = nodes;
	while (aux)
	{
		aux = set_real_words(aux, env);
		aux = set_types_nodes(aux);
		aux = set_flags_nodes(aux);
		aux = aux->next;
	}
	return (nodes);
}
