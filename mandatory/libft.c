/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:37:42 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/20 14:15:41 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

long	ft_atoi(const char *str)
{
	int				i;
	int				s;
	unsigned long	n;

	n = 0;
	s = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i++] - 48;
	}
	return (s * n);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s || !(*s))
		return (NULL);
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	while (s[i + start] != '\0' && i < len)
	{
		p[i] = s[i + start];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static char	**free_memory(char **p)
{
	size_t	n;

	n = 0;
	while (p[n])
	{
		free(p[n]);
		n++;
	}
	free(p);
	return (NULL);
}

static size_t	nbword(char const *str, char c)
{
	int		i;
	size_t	counter;

	counter = 0;
	i = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i + 1] == '\0' || (str[i] == c && str[i + 1] != c))
			counter++;
		i++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**split;
	size_t	k;
	size_t	start;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	split = (char **)malloc((nbword(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (i < nbword(s, c) && s[k])
	{
		while (s[k] == c)
			k++;
		start = k;
		while (s[k] != c && s[k])
			k++;
		split[i] = ft_substr(s, start, k - start);
		if (split[i++] == NULL)
			return (free_memory(split));
	}
	split[i] = NULL;
	return (split);
}
