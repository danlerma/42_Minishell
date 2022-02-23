/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mod_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:41:56 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/23 12:52:11 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	partscount(char const *s, char c);
static int	move_along(char *s);
static int	nextword(char *str, char c);
static char	**make_array(char **array, char const *s, char c);
static char	*getword(char *s, char c);

char	**ft_split_mod_2(char const *s, char c)
{
	char	**aux1;

	if (s == NULL)
		return (0);
	//printf("Palabras contadas -> %i\n",partscount(s, c));
	aux1 = ft_calloc(sizeof(char *), partscount(s, c) + 1);
	if (aux1 == NULL)
		return (0);
	aux1 = make_array(aux1, s, c);
	return (aux1);
}

static char	**make_array(char **array, char const *s, char c)
{
	int		i;
	int		counted;
	int		to_count;
	char	*aux1;

	aux1 = (char *)s;
	to_count = 0;
	counted = partscount(s, c);
	i = 0;
	//printf("Puntero makearray 1 ->%p\n",s);
	//printf("Puntero makearray 2 ->%p\n",aux1);
	while (to_count < counted)
	{
		array[to_count] = getword(&aux1[i], c);
		i += nextword(&aux1[i], c);
		i += move_along(&aux1[i]);
		to_count++;
	}
	free(aux1);
	return (array);
}

static int	move_along(char *s)
{
	int		i;

	i = 0;
	//printf("Puntero move along ->%p\n",s);
	if (s[i] == 34 || s[i] == 39)
		i++;
	while ((s[i] == ' ' && s[i] != 0))
	{
		i++;
	}
	return (i);
}

static int	nextword(char *s, char c)
{
	char	aux;
	int		i;

	i = 0;
	//printf("Puntero nextword ->%p\n",s);
	while (s[i] != 0)
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
		{
			return (i);
		}
		if (s[i] == 34 || s[i] == 39)
		{
			aux = s[i++];
			while ((s[i] != aux && s[i] != 0))
				i++;
			return (i);
		}
		i++;
	}
	return (i);
}

static char	*getword(char *s, char c)
{
	char	aux;
	int		i;

	i = 0;
	//printf("Puntero getword ->%p\n",s);
	while (s[i] != 0)
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
		{
			return (ft_substr(s, 0, i));
		}
		if (s[i] == 34 || s[i] == 39)
		{
			aux = s[i++];
			while ((s[i] != aux && s[i] != 0))
				i++;
			return (ft_substr(s, 0, ++i));
		}
		i++;
	}
	return (ft_substr(s, 0, i));
}

int	partscount(char const *s, char c)
{
	char	aux;
	int		cont;
	int		i;

	cont = 1;
	i = 0;
	if (c == '\0')
	{
		if (ft_strlen((char *)s) > 0)
			return (1);
		return (0);
	}
	while (s[i] != 0)
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			cont++;
		if (s[i] == 34 || s[i] == 39)
		{
			aux = s[i++];
			while ((s[i] != aux && s[i] != 0))
				i++;
		}
		i++;
	}
	return (cont);
}
