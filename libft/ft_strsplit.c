/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnakar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 09:47:02 by mnakar            #+#    #+#             */
/*   Updated: 2018/06/25 15:47:34 by mnakar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		number_of_words(char const *s, char c)
{
	int	indicator;
	int	count;

	indicator = 0;
	count = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		while (*s && *s != c)
		{
			s++;
			indicator = 1;
		}
		if (*s == '\0' || *s == c)
		{
			count += (indicator == 1) ? 1 : 0;
			indicator = 0;
			s++;
		}
	}
	return (count);
}

static int		char_count(char const *s, char c)
{
	int count;

	count = 0;
	while (*s && *s != c)
	{
		count++;
		s++;
	}
	return (count);
}

static int		copy_chars(char **orig, char *curr_word, int chr, char c)
{
	while (**orig && **orig != c)
	{
		curr_word[chr] = **orig;
		chr++;
		(*orig)++;
	}
	return (chr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		word;
	int		chr;

	chr = 0;
	word = 0;
	res = (char **)malloc(sizeof(char *) * (number_of_words(s, c) + 1));
	if (res == NULL || s == NULL)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			chr = 0;
			res[word] = (char *)malloc(sizeof(char) * (char_count(s, c) + 1));
			if (res[word] == NULL)
				return (NULL);
			chr = copy_chars((char **)&s, res[word], chr, c);
			res[word++][chr] = '\0';
		}
	}
	res[word] = 0;
	return (res);
}
