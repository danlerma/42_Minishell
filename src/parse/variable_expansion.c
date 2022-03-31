/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:05:02 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/21 16:32:05 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	is_char_special_parameter(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (0);
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

char	*get_variable_value(char *s, t_mirage *env)
{
	int		i;
	char	*var;
	char	*aux;

	i = 1;
	if (ft_isdigit(s[i]))
		return (ft_strdup(""));
	if (s[i] == '?')
		return (ft_itoa(g_output_code));
	if (is_char_special_parameter(s[i]))
		return (ft_strdup("$"));
	while (s[i] != 0)
	{
		i++;
		if (is_char_special_parameter(s[i]))
		{
			i--;
			break ;
		}
	}
	var = ft_substr(s, 1, i);
	aux = getvariable(var, env);
	free(var);
	return (aux);
}

int	get_variable_tam(char *s)
{
	int		i;

	i = 1;
	if (ft_isdigit(s[i]))
		return (1);
	if (s[i] == '?')
		return (1);
	if (is_char_special_parameter(s[i]))
		return (0);
	while (s[i] != 0)
	{
		i++;
		if (is_char_special_parameter(s[i]))
		{
			i--;
			break ;
		}
	}
	if (s[i] == 0)
		i--;
	return (i);
}
