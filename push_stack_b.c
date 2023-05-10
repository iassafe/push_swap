/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:16:45 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/10 18:33:07 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_size(t_s *swap)
{
	t_node	*node;

	swap->size_stack_a = 0;
	node = swap->stack_a;
	while (node)
	{
		swap->size_stack_a++;
		node = node->next;
	}
}

int	ft_check_index(t_s *swap, int chunk)
{
	t_node	*node;

	node = swap->stack_a;
	while (node)
	{
		if (node->index < chunk)
			return (0);
		node = node->next;
	}
	return (1);
}

void	ft_init_data(t_data *dt, t_s *swap)
{
	int chunk;
	int offset;
	int start;
	int end;

	offset = (dt->len_tab / 8);
	dt->mid = (dt->len_tab / 2);
	chunk = offset;
	while (swap->stack_a)
	{
		start = dt->mid - chunk;
		end = dt->mid + chunk;
		if ((swap->stack_a->index >= start) && (swap->stack_a->index <= end))
			ft_push_b(swap);
		while ((swap->stack_a->index < start) && (swap->stack_a->index > end))
		{
			if (swap->stack_a->index < (swap->size_stack_a / 2))
				ft_ra(swap);
			else if (swap->stack_a->index >= (swap->size_stack_a / 2))
				ft_rra(swap);
		}
		if (ft_check_index(swap, (end - start)))
			chunk += offset;
	}
}

void	ft_push_stack(t_s *swap, t_data *dt)
{
	int	chunk;
	int	new_chunk;
	int	index_chunk;
	int	mid_chunk;

	chunk = (dt->count / 5);
	new_chunk = chunk;
	index_chunk = 0;
	while (swap->stack_a)
	{
		if (swap->stack_a->index >= chunk)
		{
			ft_ra(swap);
		}
		else
		{
			mid_chunk = ((chunk + index_chunk) - (chunk / 2));
			if (swap->stack_a->index <= mid_chunk)
			{
				ft_push_b(swap);
			}
			else
			{
				ft_push_b(swap);
				if (swap->stack_a && swap->stack_a->index >= chunk)
					ft_rr(swap);
				else if (swap->stack_a && swap->stack_a->index < chunk)
					ft_rb(swap);
				if (swap->stack_a == NULL)
					ft_rb(swap);
			}
		}
		if ((ft_check_index(swap, chunk)))
		{
			chunk += new_chunk;
			index_chunk++;
		}
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
