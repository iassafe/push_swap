/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:51:46 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/07 14:09:16 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_error(char *str)
{
	ft_putstr(str);
	exit(1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return ;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

char	*ft_strjoin(char *left_str, char *buff, char s)
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
	result = malloc(ft_strlen(left_str) + ft_strlen(buff) + 2);
	if (result == NULL)
		return (NULL);
	while (left_str[i])
	{
		result[i] = left_str[i];
		i++;
	}
	while (buff[j])
		result[i++] = buff[j++];
	result[i] = s;
	result[i + 1] = '\0';
	free(left_str);
	return (result);
}
