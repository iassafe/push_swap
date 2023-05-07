/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:52:14 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/06 18:52:26 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_s	*swap)
{
	t_node	*node;

	node = swap->stack_a->next;
	if (swap->stack_a->data > node->data)
		ft_sa(swap);
}

void	ft_sra(t_s *swap)
{
	ft_sa(swap);
	ft_ra(swap);
}

void	ft_sort_three(t_s *swap)
{
	t_node	*node2;
	t_node	*node3;

	node2 = swap->stack_a->next;
	node3 = swap->stack_a->next->next;
	if (swap->stack_a->data > node2->data && node2->data < node3->data)
	{
		if (swap->stack_a->data < node3->data)
			ft_sa(swap);
		else
			ft_ra(swap);
	}
	else if (swap->stack_a->data > node2->data && node2->data > node3->data)
	{
		ft_sa(swap);
		ft_rra(swap);
	}
	else if (swap->stack_a->data < node2->data && node2->data > node3->data)
	{
		if (node3->data > swap->stack_a->data)
			ft_sra(swap);
		else
			ft_rra(swap);
	}
}

void	ft_sort_four(t_s *swap)
{
	t_node	*node;
	t_node	*min;

	min = swap->stack_a;
	node = min;
	while (node->next)
	{
		if (min->data > node->next->data)
			min = node->next;
		node = node->next;
	}
	while (min->data != swap->stack_a->data)
	{
		if (min->next == NULL)
		{
			ft_rra(swap);
		}
		else
			ft_ra(swap);
	}
	ft_push_b(swap);
	ft_sort_three(swap);
	ft_push_a(swap);
}

void	ft_sort_five(t_s *swap)
{
	t_node	*node;
	t_node	*min;

	min = swap->stack_a;
	node = min;
	while (node->next)
	{
		if (min->data > node->next->data)
			min = node->next;
		node = node->next;
	}
	while (min->data != swap->stack_a->data)
		ft_ra(swap);
	ft_push_b(swap);
	ft_sort_four(swap);
	ft_push_a(swap);
}
