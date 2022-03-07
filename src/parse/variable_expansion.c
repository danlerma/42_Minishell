/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expansion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:05:02 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/03/07 17:42:09 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		static	is_char_special_parameter(char c)
{
	if (c == '@' || c == '*' || c == '#' || c == '?' || c == '$' \
	|| c == '-' || c == '!' || c == 34 || c == 39 || c == ' ')
		return (1);
	return (0);
}

char	*get_variable_value(char *s, t_mirage *env)
{
	int		i;
	char	*var;
	char	*aux;

	i = 1;
	if (ft_isdigit(s[i]))
		return (ft_strdup(""));
	if (s[i] == ' ')
		return (ft_strdup("$"));
	while (s[i] != 0)
	{
		if (is_char_special_parameter(s[i]))
		{
			i--;
			break ;
		}
		i++;
	}
	var = ft_substr(s, 1, i);
	//printf("Variable leida $%s\n", var);
	aux = getvariable(var, env);
	free(var);
	return (aux);
}

int	get_variable_tam(char *s)
{
	int		i;

	i = 1;
	if (ft_isdigit(s[i]))
		return (2);
	if (s[i] == ' ')
		return (2);
	while (s[i] != 0)
	{
		if (is_char_special_parameter(s[i]))
		{
			i--;
			break ;
		}
		i++;
	}
	return (i);
}
