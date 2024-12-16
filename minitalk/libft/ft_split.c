/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:34:49 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/16 16:35:35 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}


/**
 *  !Explanation of Changes:
*   *Boundary Condition (i <= ft_strlen(s)):
*   *
*   *The loop should terminate when i == ft_strlen(s) to avoid over-reading beyond the string length, but the condition was adjusted to handle the boundary correctly without causing an off-by-one error.
*   *Early Return for NULL Input:
*   *
*   *We added a check for s being NULL at the start of ft_split. If s is NULL, we can return NULL immediately without performing any further work.
*   *Improvement in word_dup:
*   *
*   *The word_dup function now returns NULL if start >= finish. This ensures we do not allocate memory unnecessarily for an empty word.
*   *Memory Allocation Handling:
*   *
*   *The function checks the return of malloc properly. If memory allocation fails, it returns NULL.
*   *Null-Termination:
*   *
*   *The array of strings (split) is explicitly null-terminated by setting split[j] = NULL at the end.
*   *
 * #include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	if (start >= finish)
		return (NULL);
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))  // Iterate till the end of string
	{
		if (s[i] != c && index < 0)  // Beginning of a word
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)  // End of a word
		{
			split[j++] = word_dup(s, index, i);  // Copy word to split array
			index = -1;  // Reset index for the next word
		}
		i++;
	}
	split[j] = NULL;  // Null-terminate the array of strings
	return (split);
}

 */