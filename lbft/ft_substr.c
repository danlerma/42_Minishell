/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:48:52 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/08/13 12:15:23 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub_str;
	unsigned int	y;
	unsigned int	i;

	y = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	sub_str = (char *)malloc((len + 1) * sizeof(*s));
	if (sub_str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && y < len)
			sub_str[y++] = s[i];
		i++;
	}
	sub_str[y] = '\0';
	return (sub_str);
}
