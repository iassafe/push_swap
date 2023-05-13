/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:24:02 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/13 16:37:39 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_memcmp( const void *pointer1, const void *pointer2, size_t size )
{
	unsigned char	*u1;
	unsigned char	*u2;
	size_t			i;

	i = 0;
	u1 = (unsigned char *)pointer1;
	u2 = (unsigned char *)pointer2;
	while (size > i)
	{
		if (u1[i] != u2[i])
			return (u1[i] - u2[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	if (left_str == NULL)
	{
		left_str = malloc(1);
		left_str[0] = '\0';
	}
	result = malloc(ft_strlen(left_str) + ft_strlen(buff) + 1);
	if (result == NULL)
		return (NULL);
	while (left_str[i])
	{
		result[i] = left_str[i];
		i++;
	}
	while (buff[j])
		result[i++] = buff[j++];
	result[i] = '\0';
	free(left_str);
	return (result);
}
