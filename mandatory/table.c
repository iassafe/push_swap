/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 19:43:18 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/13 10:45:07 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_link(char **str, t_s *swap)
{
	t_node	*node;
	t_node	*p;
	int		i;

	i = 0;
	p = NULL;
	while (str[i])
	{
		node = malloc(sizeof(t_node));
		node->data = ft_atoi(str[i]);
		node->next = NULL;
		if (p == NULL)
		{
			p = node;
			swap->stack_a = p;
		}
		else
		{
			p->next = node;
			p = node;
		}
		i++;
	}
}

void	ft_table(t_s *swap, t_data *dt)
{
	t_node	*node;
	int		i;

	dt->tab = malloc((dt->count) * sizeof(int));
	node = swap->stack_a;
	i = 0;
	while (node)
	{
		dt->tab[i++] = node->data;
		node = node->next;
	}
}

void	ft_sort_table(t_data *dt)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i <= (dt->count - 1))
	{
		j = i + 1;
		tmp = 0;
		while (j < (dt->count))
		{
			if (dt->tab[i] > dt->tab[j])
			{
				tmp = dt->tab[i];
				dt->tab[i] = dt->tab[j];
				dt->tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_index_stack(t_s *swap, t_data *dt)
{
	int		i;
	t_node	*node;

	node = swap->stack_a;
	i = 0;
	while (i < dt->count)
	{
		while (node)
		{
			if (node->data == dt->tab[i])
			{
				node->index = i;
				node = swap->stack_a;
				break ;
			}
			node = node->next;
		}
		i++;
	}
}
