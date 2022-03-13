/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:21:37 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/09 13:25:24 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*join_and_liberate_str(char *s, char *s2, char c, int intent)
{
	char	*aux;

	if (intent == 1)
	{
		aux = ft_strjoin_2(s, c);
	}
	else if (intent == 2)
	{
		aux = ft_strjoin(s, s2);
		free (s2);
	}
	else
	{
		aux = ft_strdup("Error al conbinar");
	}	
	free (s);
	return (aux);
}

static char	*get_inside_quotes(char *s, t_mirage *env)
{
	char	*aux;
	char	auxchar;
	int		i;

	auxchar = s[0];
	i = 1;
	aux = ft_strdup("");
	while (s[i] != 0)
	{
		if (s[i] == auxchar)
			break ;
		else if (s[i] == '$' && auxchar == 34)
		{
			if (s[i + 1] == auxchar)
				aux = join_and_liberate_str(aux, 0, '$', 1);
			else
				aux = join_and_liberate_str(aux, \
				get_variable_value(&s[i], env), 0, 2);
			i += get_variable_tam(&s[i]);
		}
		else
			aux = join_and_liberate_str(aux, 0, s[i], 1);
		i++;
	}
	return (aux);
}
//printf("Underquote readed : %s\n",aux);

static int	get_tam_inside_quotes(char *s)
{
	char	auxchar;
	int		i;

	auxchar = s[0];
	i = 1;
	while (s[i] != 0)
	{
		if (s[i] == auxchar)
			break ;
		i++;
	}
	return (i);
}

char	*real_str(char *s, t_mirage *env)
{
	char	*aux;
	int		i;

	i = 0;
	aux = ft_strdup("");
	while (s[i] != 0)
	{
		if (s[i] == 34 || s[i] == 39)
		{
			aux = join_and_liberate_str(aux, \
			get_inside_quotes(&s[i], env), 0, 2);
			i += get_tam_inside_quotes(&s[i]);
		}
		else if (s[i] == '$' && s[i + 1] != 0)
		{
			aux = join_and_liberate_str(aux, \
			get_variable_value(&s[i], env), 0, 2);
			i += get_variable_tam(&s[i]);
		}
		else
			aux = join_and_liberate_str(aux, 0, s[i], 1);
		i++;
	}
	return (aux);
}
