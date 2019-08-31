/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 09:58:50 by stanaka           #+#    #+#             */
/*   Updated: 2019/08/30 19:20:44 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**split;
	size_t	j;
	size_t	n;

	if (!s)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(char*) * (ft_count_words(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c && s[j])
		{
			n = ft_count_letters(s, c, j);
			if (!(split[i] = ft_strsub(&s[j], 0, n)))
				return (NULL);
			i++;
			j = j + n - 1;
		}
		j++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_strsplit2(char const *s, char c, char d)
{
	size_t	i;
	char	**split;
	size_t	j;
	size_t	n;

	if (!s)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(char*) * (ft_c2(s, c, d) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c && s[j] != d && s[j])
		{
			n = ft_count_letters2(s, c, d, j);
			if (!(split[i] = ft_strsub(&s[j], 0, n)))
				return (NULL);
			i++;
			j = j + n - 1;
		}
		j++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_strsplit3(int ac, char **av, char c)
{
	int	n;
	char **arr;
	int	i;
	int k;
	int j;

	n = 1;
	i = 0;
	while (n < ac)
	{
		i += ft_count_words(av[n], c);
		n++;
	}
	arr = (char **)malloc(sizeof(char*) * (i + 1));
	arr[i] = NULL;
	n = 1;
	i = 0;
	while (n < ac)
	{
		j = 0;
		while (av[n][j])
		{
			if (av[n][j] != c && av[n][j])
			{
				k = ft_count_letters(av[n], c, j);
				if (!(arr[i] = ft_strsub(&av[n][j], 0, k)))
					return (NULL);
				i++;
				j = j + k - 1;
			}
			j++;
		}
		n++;
	}
	return (arr);
}
