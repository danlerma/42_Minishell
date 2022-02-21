/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlerma-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:23:05 by dlerma-c          #+#    #+#             */
/*   Updated: 2021/07/29 12:23:09 by dlerma-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	char			*d;
	const char		*s;

	d = dst;
	s = src;
	if (s < d)
	{
		i = len;
		while (--i >= 0)
			d[i] = s[i];
		return (dst);
	}
	else
	{
		if (s > d)
		{
			i = -1;
			while (++i < (int)len)
				d[i] = s[i];
			return (dst);
		}
	}
	return (NULL);
}
