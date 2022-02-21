/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 13:04:56 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/08/11 18:07:57 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	y;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		y = 0;
		while (haystack[i + y] == needle[y] && (y + i) < len)
		{
			if (haystack[i + y] == '\0' && needle[y] == '\0')
				return ((char *)&haystack[i]);
			y++;
		}
		if (needle[y] == '\0')
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}
