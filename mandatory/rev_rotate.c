/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:04:54 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/13 17:16:55 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_s *swap)
{
	ft_rev_rotate_a(swap);
	ft_rev_rotate_b(swap);
	write(1, "rrr\n", 4);
}
