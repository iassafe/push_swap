/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:16:45 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/08 18:35:32 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_index(t_s *swap, int chunk)
{
	t_node	*node;

	node = swap->stack_a;
	while (node)
	{
		if (node->index < chunk)
			return (1);
		node = node->next;
	}
	return (0);
}

void	ft_push_stack_b(t_s *swap, t_data *dt)
{
	int	chunk;
	int	new_chunk;

	chunk = (dt->count / 5);
	new_chunk = chunk;
	while (swap->stack_a)
	{
		if (swap->stack_a->index < chunk)
			ft_push_b(swap);
		else
		{
			while (swap->stack_a->index >= chunk)
				ft_ra(swap);
			ft_push_b(swap);
		}
		if (!ft_check_index(swap, chunk))
			chunk += new_chunk;
	}
}

void	ft_push_stack_a(t_s *swap, t_data *dt)
{
	int	chunk;

	chunk = dt->count - 1;
	while (swap->stack_b)
	{
		while (swap->stack_b->index != chunk)
			ft_rb(swap);
		ft_push_a(swap);
		chunk--;
	}
}
