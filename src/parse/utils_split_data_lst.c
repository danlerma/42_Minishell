/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split_data_lst.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:19:16 by dlerma-c          #+#    #+#             */
/*   Updated: 2022/03/21 13:19:40 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	is_separator_rework(char const *c)
{
	if (c[0] == ' ' || c[0] == '>' || c[0] == '<' || c[0] == '|')
	{
		return (1);
	}
	return (0);
}

int	get_tam_word_rework(char const *s)
{
	int		tam;
	char	aux;

	tam = 0;
	while (s[tam] != 0)
	{
		if (s[tam] == 34 || s[tam] == 39)
		{
			aux = s[tam];
			while (s[tam] != 0)
			{
				tam++;
				if (s[tam] == aux)
					break ;
			}
		}
		else if (is_separator_rework(&s[tam]))
			return (tam);
		tam++;
	}
	return (tam);
}
