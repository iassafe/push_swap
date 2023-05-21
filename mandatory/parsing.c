/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:01:48 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/20 14:12:37 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_check(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '+' || str[i][j] == '-')
			{
				if (!ft_isdigit(str[i][j + 1]))
					ft_error("Error\n");
			}
			else if (ft_isdigit(str[i][j])
				&& str[i][j + 1] && str[i][j + 1] != ' '
				&& !ft_isdigit(str[i][j + 1]))
				ft_error("Error\n");
			j++;
		}
		i++;
	}
}

void	ft_number(char **str)
{
	int		i;
	int		j;
	long	n;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			n = ft_atoi(str[i]);
			if (n < -2147483648 || n > 2147483647)
				ft_error("Error\n");
			if (!(str[i][j] >= '0' && str[i][j] <= '9')
			&& str[i][j] != '+' && str[i][j] != '-')
				ft_error("Error\n");
			j++;
		}
		i++;
	}
}

void	ft_duplicat(char **str)
{
	int	i;
	int	k;
	int	k_nb;
	int	i_nb;

	k = 0;
	while (str[k])
	{
		i = 1;
		while (str[i])
		{
			k_nb = ft_atoi(str[k]);
			i_nb = ft_atoi(str[i]);
			if (k_nb == i_nb && i != k)
				ft_error("Error\n");
			i++;
		}
		k++;
	}
}
