/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_data_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:51:06 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/24 20:31:02 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	is_separator(char const *c)
{
	if (c[0] == ' ' || c[0] == '>' || c[0] == '<' || c[0] == '|')
	{
		return (1);
	}
	return (0);
}

static int	get_tam_word(char const *s)
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
		else if (is_separator(&s[tam]))
			return (tam);
		tam++;
	}
	return (tam);
}

static int	get_tam_token(char const *s)
{
	if (s[0] == '>' || s[0] == '<' || s[0] == '|')
	{
		if (s[1] == '>' || s[1] == '<')
			return (2);
		return (1);
	}
	return (0);
}

static int	dst_next_word(char const *s)
{
	int	dst;

	dst = 0;
	while (s[dst] != 0)
	{
		if (s[dst] != ' ')
			break ;
		dst++;
	}
	return (dst);
}

t_list	*make_lst(t_list *lst, char const *s)
{
	t_list	*aux_lst;
	int		i;

	i = 0;
	aux_lst = lst;
	while (s[i] != 0)
	{
		i += dst_next_word(&s[i]);
		if (!is_separator(&s[i]))
		{
			lst->content = ft_substr (s, i, get_tam_word(&s[i]));
			i += get_tam_word(&s[i]);
		}
		else
		{
			lst->content = ft_substr (s, i, get_tam_token(&s[i]));
			i += get_tam_token(&s[i]);
		}
		lst->next = ft_lstnew(0);
		lst = lst->next;
	}
	return (aux_lst);
}
//printf("palabra: %s\n",lst->content);