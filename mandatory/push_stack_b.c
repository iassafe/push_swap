/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:16:45 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/15 15:38:30 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_size(t_s *swap)
{
	t_node	*node;

	swap->size_stack_b = 1;
	node = swap->stack_b;
	while (node)
	{
		swap->size_stack_b++;
		node = node->next;
	}
}

void	ft_push_stack_a(t_s *swap, t_data *dt)
{
	t_node	*node;
	int		pos;
	int		ind_max;

	ind_max = dt->count - 1;
	while (swap->stack_b)
	{
		pos = 0;
		node = swap->stack_b;
		while (node && node->index != ind_max)
		{
			pos++;
			node = node->next;
		}
		while (swap->stack_b->index != ind_max)
		{
			if (pos < (swap->size_stack_b / 2))
				ft_rb(swap);
			else if (pos >= (swap->size_stack_b / 2))
				ft_rrb(swap);
		}
		ft_push_a(swap);
		ind_max--;
		swap->size_stack_b--;
	}
}

void	ft_push_stack_b(t_s *swap, t_data *dt)
{
	int	i;
	int	j;

	i = 0;
	if (dt->count <= 100)
		j = 15;
	else
		j = 30;
	while (swap->stack_a)
	{
		if (swap->stack_a->index < i)
		{
			ft_push_b(swap);
			i++;
		}
		else if (swap->stack_a->index < (i + j))
		{
			ft_push_b(swap);
			ft_rb(swap);
			i++;
		}
		else
			ft_ra(swap);
	}
}
