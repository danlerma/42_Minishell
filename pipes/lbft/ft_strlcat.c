/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <dlerma-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:12:29 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/09/15 17:03:06 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	countsrc;
	unsigned int	countdst;
	unsigned int	i;
	size_t			result;

	countsrc = ft_strlen((char *)src);
	countdst = ft_strlen(dst);
	i = 0;
	if (dstsize <= countdst)
		return (dstsize + countsrc);
	if (dstsize != 0)
	{
		while (src[i] && countdst < dstsize - 1)
		{
			dst[countdst] = src[i];
			countdst++;
			i++;
		}
	}
	result = countdst + ft_strlen(&src[i]);
	dst[countdst] = '\0';
	return (result);
}
