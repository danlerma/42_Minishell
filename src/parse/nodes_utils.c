/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:35:49 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/17 12:27:24 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	nodes_check_error(t_lst *list)
{
	t_lst	*aux;

	aux = list;
	if (aux->next == 0 && aux->n_words == 0)
		return (0);
	while (aux)
	{
		if (aux->n_words == 0)
		{
			printf("syntax error near unexpected token '|'\n");
			return (0);
		}
		aux = aux->next;
	}
	return (1);
}
