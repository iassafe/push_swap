/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:01:48 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/15 14:30:59 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_error(char *str)
{
	ft_putstr(str);
	exit(1);
}

void	ft_parsing(t_s *swap)
{
	ft_check(swap->table);
	ft_number(swap->table);
	ft_duplicat(swap->table);
	ft_link(swap->table, swap);
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
				if ((!(str[i][j + 1] >= '0' && str[i][j + 1] <= '9')))
					ft_error("Error\n");
			}
			j++;
		}
		i++;
	}
}

void	ft_number(char **str)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			n = ft_atoi(&str[i][j]);
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

	i = 1;
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
