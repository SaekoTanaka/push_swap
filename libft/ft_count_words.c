/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 06:36:41 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/30 15:59:54 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char const *s, char c)
{
	size_t	word_count;

	word_count = 0;
	while (*s)
	{
		if (*s != c && *s)
		{
			if (*(s + 1) == c || *(s + 1) == '\0')
				word_count++;
		}
		s++;
	}
	return (word_count);
}

size_t	ft_c2(char const *s, char c, char d)
{
	size_t	word_count;

	word_count = 0;
	while (*s)
	{
		if (*s != c && *s != d && *s)
		{
			if (*(s + 1) == c || *(s + 1) == d || *(s + 1) == '\0')
				word_count++;
		}
		s++;
	}
	return (word_count);
}
