/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_set_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:15:05 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/01 16:02:41 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*join_and_liberate_str(char *s, char c)
{
	char	*aux;

	aux = ft_strjoin_2(s, c);
	free(s);
	return (aux);
}

char	*unquote_str(char *s)
{
	char	*aux;
	char	auxchar;
	int		i;

	i = 0;
	aux = ft_strdup("");
	while (s[i] != 0)
	{
		if (s[i] == 34 || s[i] == 39)
		{
			auxchar = s[i];
			i++;
			while (s[i] != 0)
			{
				if (s[i] == auxchar)
					break ;
				aux = join_and_liberate_str(aux, s[i]);
				i++;
			}
			i++;
		}
		else
			aux = join_and_liberate_str(aux, s[i++]);
	}
	return (aux);
}

static t_lst	*set_flags_nodes(t_lst *node)
{
	int		i;
	char	*aux;

	i = 0;
	while (node->argv[i] != 0)
	{
		if (node->type[i] == 8)
		{
			node->flag[i] = 1;
			aux = node->argv[i];
			node->argv[i] = unquote_str(aux);
			free(node->argv[i]);
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
		aux = set_types_nodes(aux);
		aux = set_flags_nodes(aux);
		aux = aux->next;
	}
	return (nodes);
}
