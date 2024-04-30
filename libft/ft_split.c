/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:40:20 by rmei              #+#    #+#             */
/*   Updated: 2024/04/30 17:52:42 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/* Counts how many strings will result from the split of s by the delimeter c */
static int	ft_strcount(char const *s, char c)
{
	int	count;

	count = 1;
	// Edit code here: gotta move pointer as long as the delimeter is met first!
	// Then add to count.
	while (*s)
		if (c == *(s++))
			count++;
	return (count);
}

/* Counts the length of the substring at 's' until delimeter 'c' is met */
static int	ft_substrlen(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *(s++) != c)
		len++;
	return (len);
}

/* Frees memory from 2D array */
static void	ft_arrayfree(char **array)
{
	while (*array)
		free(*(array++));
	free((array));
}

/* Returns an array of strings, splitting 's' by the delimeter 'c', or NULL */
char	**ft_split(char const *s, char c)
{
	char	**array;
	int		array_buffer;
	int		substr_buffer;
	int		i;

	array_buffer = ft_strcount(s, c) + 1;
	array = (char **) malloc(array_buffer * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	while (array[i])
	{
		substr_buffer = ft_substrlen(s, c) + 1;
		array[i] = (char *) malloc(substr_buffer * sizeof(char));
		ft_strlcpy(array[i], s, substr_buffer);
		if (!array[i])
		{
			ft_arrayfree(array);
			return (NULL);
		}
		s += substr_buffer;
		i++;
	}
	array[i] = (void *)0;
	return (array);
}
