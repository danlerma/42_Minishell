/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:35:49 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/04 15:05:48 by mortiz-d         ###   ########.fr       */
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

char	*getvariable(char *var, t_mirage *env)
{
	t_mirage	*aux;

	aux = env;
	if (ft_strlen(var) == 0)
		return (ft_strdup(""));
	else
	{
		while (aux)
		{
			if (ft_strncmp(aux->name, var, ft_strlen(var)) == 0
				&& ft_strlen(var) == ft_strlen(aux->name))
				return (ft_strdup(aux->value));
			aux = aux->next;
		}
	}
	return (ft_strdup(""));
}
