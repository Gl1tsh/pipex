/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:17:29 by nagiorgi          #+#    #+#             */
/*   Updated: 2023/11/16 15:16:18 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Divise une chaîne de caractères en mots en utilisant    */
/*   la variable 'separator' comme séparateur.                                */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - str : La chaîne de caractères à diviser                             */
/*      - separator : Le caractère de séparation                              */
/*                                                                            */
/*   Retour :                                                                 */
/*      - Un tableau de chaînes de caractères contenant les mots extraits de  */
/*        'str'. Le tableau est terminé par un pointeur NULL.                 */
/*      - NULL en cas d'échec (allocation mémoire ou paramètre invalide).     */
/*                                                                            */
/*   Si échec :                                                               */
/*      - La fonction renvoie NULL si l'allocation mémoire échoue ou si 'str' */
/*        est NULL.                                                           */
/* *****************************************************************   by.XVI */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*str)
	{
		if (*str != c && count == 0)
		{
			count = 1;
			i++;
		}
		else if (*str == c)
			count = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (finish - start + 1));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **strs, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(strs[i++]);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	k;
	int		index;
	char	**result;

	i = -1;
	k = 0;
	index = -1;
	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !result)
		return (NULL);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			result[k] = word_dup(s, index, i);
			if (!result[k++])
				return (ft_free(result, k));
			index = -1;
		}
	}
	result[k] = 0;
	return (result);
}
