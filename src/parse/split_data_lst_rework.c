/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_data_lst_rework.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 13:24:04 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/02 19:19:36 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	is_separator_rework(char const *c)
{
	if (c[0] == ' ' || c[0] == '>' || c[0] == '<' || c[0] == '|')
	{
		return (1);
	}
	return (0);
}
/*
static int	tam_between_quotes(char const *s)
{
	int		tam;
	char	aux;

	tam = 0;
	aux = s[tam];
	while (s[tam] != 0)
	{
		tam++;
		if (s[tam] == aux && s[tam - 1] == '\\')
			break ;
	}
	return (tam);
}
*/

static int	get_tam_word_rework(char const *s)
{
	int		tam;
	char	aux;

	tam = 0;
	while (s[tam] != 0)
	{
		if (s[tam] == '\\')
			tam++;
		else if (s[tam] == 34 || s[tam] == 39)
		{
			aux = s[tam];
			while (s[tam] != 0)
			{
				tam++;
				if (s[tam] == aux && s[tam - 1] != '\\')
					break ;
			}
		}
		else if (is_separator_rework(&s[tam]))
			return (tam);
		tam++;
	}
	return (tam);
}

static int	get_tam_token_rework(char const *s)
{
	if (s[0] == '>' || s[0] == '<' || s[0] == '|')
	{
		if (s[1] == '>' || s[1] == '<')
			return (2);
		return (1);
	}
	return (0);
}

static int	dst_next_word_rework(char const *s)
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

static t_list	*make_lst_rework(t_list *lst, char const *s)
{
	t_list	*aux_lst;
	int		i;

	i = 0;
	aux_lst = lst;
	while (s[i] != 0)
	{
		i += dst_next_word_rework(&s[i]);
		if (!is_separator_rework(&s[i]) && s[i] != 0)
		{
			lst->content = ft_substr (s, i, get_tam_word_rework(&s[i]));
			i += get_tam_word_rework(&s[i]);
		}
		else if (s[i] != 0)
		{
			lst->content = ft_substr (s, i, get_tam_token_rework(&s[i]));
			i += get_tam_token_rework(&s[i]);
		}
		else
			break ;
		lst->next = ft_lstnew(0);
		lst = lst->next;
	}
	return (aux_lst);
}
//printf("palabra: %s\n",lst->content);

t_list	*split_data_rework(char const *s)
{
	t_list	*aux;

	if (s == NULL)
		return (0);
	aux = make_lst_rework(ft_lstnew(0), s);
	return (aux);
}