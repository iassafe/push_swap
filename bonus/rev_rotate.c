/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:04:54 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/13 11:53:51 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap_bonus.h"

void	ft_rev_rotate_a(t_s *swap)
{
	t_node	*node;
	t_node	*ptr;

	node = swap->stack_a;
	while (node->next->next)
		node = node->next;
	ptr = node->next;
	ptr->next = swap->stack_a;
	node->next = NULL;
	swap->stack_a = ptr;
}

void	ft_rra(t_s *swap)
{
	ft_rev_rotate_a(swap);
}

void	ft_rev_rotate_b(t_s *swap)
{
	t_node	*node;
	t_node	*ptr;

	node = swap->stack_b;
	while (node->next->next)
		node = node->next;
	ptr = node->next;
	ptr->next = swap->stack_b;
	node->next = NULL;
	swap->stack_b = ptr;
}

void	ft_rrb(t_s *swap)
{
	ft_rev_rotate_b(swap);
}

void	ft_rrr(t_s *swap)
{
	if (swap->stack_a)
		ft_rev_rotate_a(swap);
	if (swap->stack_b)
		ft_rev_rotate_b(swap);
}
