/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:28:51 by stanaka           #+#    #+#             */
/*   Updated: 2019/03/08 12:06:54 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;

	if (*s2 == '\0')
	{
		return ((char*)s1);
	}
	while (*s1 != '\0')
	{
		if (*s1 == *s2)
		{
			i = 0;
			while (s2[i] != '\0' && s1[i] == s2[i])
			{
				i++;
				if (s2[i] == '\0')
					return ((char*)s1);
			}
		}
		s1++;
	}
	return (NULL);
}
