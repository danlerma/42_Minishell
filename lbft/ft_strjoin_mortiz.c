/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_mortiz.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortiz-d <mortiz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:45:43 by mortiz-d          #+#    #+#             */
/*   Updated: 2022/02/28 16:55:36 by mortiz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_2(char const *s1, char s2)
{
	char	*aux1;
	char	*aux2;
	int		auxsize;

	if (s1 == NULL || s2 == '\0')
		return (0);
	auxsize = ft_strlen((char *)s1) + 2;
	aux1 = ft_calloc(sizeof(char), auxsize);
	if (aux1 == NULL)
		return (0);
	ft_strlcpy(aux1, (char *)s1, auxsize);
	aux2 = ft_calloc(sizeof(char), 2);
	aux2[0] = s2;
	ft_strlcat(aux1, (char *)aux2, auxsize);
	free(aux2);
	return (aux1);
}
