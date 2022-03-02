/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:26:24 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/08/12 19:50:17 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*ptr1;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[len] && len > i && ft_strchr(set, s1[len]))
		len--;
	len = len + 1;
	ptr1 = malloc(len - i + 1 * sizeof(char));
	if (ptr1 == NULL)
		return (NULL);
	ft_strlcpy(ptr1, &s1[i], len - i + 1);
	return (ptr1);
}
