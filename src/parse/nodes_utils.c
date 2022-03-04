/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:35:49 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/04 13:23:52 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	nodes_check_error(t_lst *list)
{
	t_lst	*aux;
	int		i;

	i = 1;
	aux = list;
	if (aux->next == 0 && aux->n_words == 0)
		return (0);
	while (aux)
	{
		printf("Nodo : %i tiene %i palabras\n", i, aux->n_words);
		if (aux->n_words == 0)
		{
			printf("syntax error near unexpected token `|'\n");
			return (0);
		}
		aux = aux->next;
	}
	return (1);
}
/*
void	getvariable(char *var, t_mirage *env)
{
	char		*env;
	t_mirage	*aux;

	aux = env;
	while (aux)
	{
		printf("variable : %i\n",aux->var);
		printf("var : %s\n",aux->var);
		printf("name : %s\n",aux->name);
		printf("content : %s\n",aux->value);
		aux = aux->next;
	}
}
*/