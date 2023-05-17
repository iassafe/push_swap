/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:17:46 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/17 14:39:23 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap_bonus.h"

void	ft_rotate_a(t_s *swap)
{
	t_node	*node;

	if (swap->stack_a == NULL || swap->stack_a->next == NULL)
		return ;
	node = swap->stack_a;
	while (node->next)
		node = node->next;
	node->next = swap->stack_a;
	swap->stack_a = swap->stack_a->next;
	node->next->next = NULL;
}

void	ft_ra(t_s *swap)
{
	ft_rotate_a(swap);
}

void	ft_rotate_b(t_s *swap)
{
	t_node	*node;

	if (swap->stack_b == NULL || swap->stack_a->next == NULL)
		return ;
	node = swap->stack_b;
	while (node->next)
		node = node->next;
	node->next = swap->stack_b;
	swap->stack_b = swap->stack_b->next;
	node->next->next = NULL;
}

void	ft_rb(t_s *swap)
{
	ft_rotate_b(swap);
}

void	ft_rr(t_s *swap)
{
	ft_rotate_a(swap);
	ft_rotate_b(swap);
}
