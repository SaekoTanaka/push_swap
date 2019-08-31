/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_letters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 06:37:21 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/30 15:57:33 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_letters(char const *s, char c, size_t j)
{
	size_t	i;

	i = 0;
	while (s[j] != c && s[j])
	{
		i++;
		j++;
	}
	return (i);
}

size_t	ft_count_letters2(char const *s, char c, char d, size_t j)
{
	size_t	i;

	i = 0;
	while (s[j] != c && s[j] != d && s[j])
	{
		i++;
		j++;
	}
	return (i);
}
