/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:56:17 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/10 10:47:39 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap_a(t_s *swap)
{
	t_node	tmp;
	t_node	node;

	if (swap->stack_a->data == '\0' || swap->stack_a->next == NULL)
		return ;
	node.data = swap->stack_a->next->data;
	tmp.data = swap->stack_a->data;
	swap->stack_a->data = node.data;
	swap->stack_a->next->data = tmp.data;
}

void	ft_sa(t_s *swap)
{
	ft_swap_a(swap);
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_s *swap)
{
	t_node	tmp;
	t_node	node;

	if (swap->stack_b->data == '\0' || swap->stack_b->next == NULL)
		return ;
	node.data = swap->stack_b->next->data;
	tmp.data = swap->stack_b->data;
	swap->stack_b->data = node.data;
	swap->stack_b->next->data = tmp.data;
}

void	ft_sb(t_s *swap)
{
	ft_swap_b(swap);
	write(1, "sb\n", 3);
}

void	ft_ss(t_s *swap)
{
	ft_swap_a(swap);
	ft_swap_b(swap);
	write(1, "ss\n", 3);
}
