/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmei <rmei@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:40:20 by rmei              #+#    #+#             */
/*   Updated: 2024/05/02 17:39:55 by rmei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/* Counts how many strings will result from the split of s by the delimeter c */
static int	ft_substr_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

/* Counts the length of the substring at 's' until delimeter 'c' is met */
static int	ft_substr_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s && *(s++) != c)
		len++;
	return (len);
}

/* If a nested allocation fails, frees memory allocated to an array of ptrs */
static void	ft_ptr_array_free(char **ptr_array, char **array)
{
	if (*ptr_array)
		return ;
	while (ptr_array != array)
		free(*(ptr_array--));
	free(*ptr_array);
	free(array);
}

/* Returns an array of strings, splitting 's' by the delimeter 'c', or NULL */
char	**ft_split(char const *s, char c)
{
	char	**array;
	char	**ptr_array;
	int		substr_len;

	array = (char **) malloc((ft_substr_count(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	ptr_array = array;
	while (*s)
	{
		while (*s == c)
			s++;
		substr_len = ft_substr_len(s, c);
		if (!substr_len)
			break ;
		*ptr_array = (char *) malloc((substr_len + 1) * sizeof(char));
		ft_ptr_array_free(ptr_array, array);
		if (!*ptr_array)
			return (NULL);
		ft_strlcpy(*ptr_array, s, substr_len + 1);
		ptr_array++;
		s += substr_len;
	}
	*ptr_array = (void *)0;
	return (array);
}
