/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:51:46 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/13 16:34:53 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap_bonus.h"

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

char	*ft_strjoin_space(char *left_str, char *buff, char s)
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

char	*ft_strchr(const char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char) c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set, t_data	*dt)
{
	char	*l;

	dt->i = 0;
	if (s1[0] == '\0')
		ft_error("Error\n");
	if (!s1)
		return (NULL);
	while (s1[dt->i])
	{
		if (ft_strchr(set, s1[dt->i]) == 0)
			break ;
		dt->i++;
	}
	dt->j = ft_strlen(s1);
	while (dt->j != 0)
	{
		if (ft_strchr(set, s1[dt->j]) == 0)
			break ;
		dt->j--;
	}
	dt->k = (dt->j - dt->i + 1);
	l = ft_substr(s1, dt->i, dt->k);
	return (l);
}
