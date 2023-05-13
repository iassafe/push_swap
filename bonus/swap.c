/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:56:17 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/13 16:40:36 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap_bonus.h"

void	ft_swap_a(t_s *swap)
{
	t_node	tmp;
	t_node	node;

	if (swap->stack_a == NULL || swap->stack_a->next == NULL)
		return ;
	node.data = swap->stack_a->next->data;
	tmp.data = swap->stack_a->data;
	swap->stack_a->data = node.data;
	swap->stack_a->next->data = tmp.data;
}

void	ft_sa(t_s *swap)
{
	ft_swap_a(swap);
}

void	ft_swap_b(t_s *swap)
{
	t_node	tmp;
	t_node	node;

	if (swap->stack_b == NULL || swap->stack_b->next == NULL)
		return ;
	node.data = swap->stack_b->next->data;
	tmp.data = swap->stack_b->data;
	swap->stack_b->data = node.data;
	swap->stack_b->next->data = tmp.data;
}

void	ft_sb(t_s *swap)
{
	ft_swap_b(swap);
}

void	ft_ss(t_s *swap)
{
	if (swap->stack_a)
		ft_swap_a(swap);
	if (swap->stack_b)
		ft_swap_b(swap);
}
