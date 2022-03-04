/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:21:37 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/04 14:53:48 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char static	*join_and_liberate_str(char *s, char *s2, char c, int intent)
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

char	static	*get_variable_value(char *s, t_mirage *env)
{
	int		i;
	char	*var;
	char	*aux;

	i = 1;
	if (s[i] == 0 || s[i] == 34 || s[i] == 39 || s[i] == ' ')
		return (ft_strdup("$"));
	while (s[i] != 0)
	{
		if (s[i] == '\\' || s[i] == 34 || s[i] == 39
			|| s[i] == '$' || s[i] == ' ')
		{
			i--;
			break ;
		}
		i++;
	}
	var = ft_substr(s, 1, i);
	aux = getvariable(var, env);
	free(var);
	return (aux);
}

int	static	get_variable_tam(char *s)
{
	int		i;

	i = 1;
	while (s[i] != 0)
	{
		if (s[i] == '\\' || s[i] == 34 || s[i] == 39
			|| s[i] == '$' || s[i] == ' ')
		{
			i--;
			break ;
		}
		i++;
	}
	return (i);
}

char	static	*get_inside_quotes(char *s, t_mirage *env)
{
	char	*aux;
	char	auxchar;
	int		i;

	auxchar = s[0];
	i = 1;
	aux = ft_strdup("");
	while (s[i] != 0)
	{
		if (s[i] == auxchar && s[i - 1] != '\\')
			break ;
		else if (s[i] == '\\')
			aux = join_and_liberate_str(aux, 0, s[++i], 1);
		else if (s[i] == '$' && auxchar == 34)
		{
			aux = join_and_liberate_str(aux, get_variable_value(&s[i], env), 0, 2);
			i += get_variable_tam(&s[i]);
		}
		else
			aux = join_and_liberate_str(aux, 0, s[i], 1);
		i++;
	}
	i++;
	return (aux);
}

int static	get_tam_inside_quotes(char *s)
{
	char	auxchar;
	int		i;

	auxchar = s[0];
	i = 1;
	while (s[i] != 0)
	{
		if (s[i] == auxchar && s[i - 1] != '\\')
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
		if (s[i] == '\\')
			aux = join_and_liberate_str(aux, 0, s[++i], 1);
		else if (s[i] == 34 || s[i] == 39)
		{
			aux = join_and_liberate_str(aux, get_inside_quotes(&s[i], env), 0, 2);
			i += get_tam_inside_quotes(&s[i]);
		}
		else if (s[i] == '$')
		{
			aux = join_and_liberate_str(aux, get_variable_value(&s[i], env), 0, 2);
			i += get_variable_tam(&s[i]);
		}
		else
			aux = join_and_liberate_str(aux, 0, s[i], 1);
		i++;
	}
	return (aux);
}
