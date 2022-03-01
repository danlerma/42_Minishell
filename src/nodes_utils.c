/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:35:49 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/01 15:38:18 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	nodes_check_error(t_lst *list)
{
	t_lst	*aux;
	int		i;

	aux = list;
	if (aux->next == 0 && aux->argv[0] == 0)
		return (0);
	while (aux)
	{
		i = 0;
		while (aux->argv[i] != 0)
			i++;
		if (i == 0)
		{
			printf("syntax error near unexpected token `|'\n");
			return (0);
		}
		aux = aux->next;
	}
	return (1);
}
