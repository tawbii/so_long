/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afayad <afayad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:18:16 by afayad            #+#    #+#             */
/*   Updated: 2024/08/02 16:32:00 by afayad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_words(char const *str, char c)
{
	int	count;
	int	i;

	if (str == NULL)
		return (0);
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i] != '\0')
				i++;
		}
		if (str[i] != '\0')
			i++;
	}
	return (count);
}

static void	ft_strncpy(char *str, char const *src, int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
}

static void	ft_helper(char c, char const *s, char **strs, int *k)
{
	int	j;
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			j = 0;
			while (s[i + j] != c && s[i + j] != '\0')
				j++;
			strs[*k] = malloc((j + 1) * sizeof(char));
			if (strs[*k] == NULL)
			{
				while (*k > 0)
					free(strs[--(*k)]);
				free(strs);
				return ;
			}
			ft_strncpy(strs[(*k)++], s + i, j);
			i += j;
		}
		else
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		k;

	if (s == NULL)
		return (NULL);
	strs = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	k = 0;
	ft_helper(c, s, strs, &k);
	strs[k] = NULL;
	return (strs);
}
