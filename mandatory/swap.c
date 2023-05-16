/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:56:17 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/16 15:47:21 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_swap_a(t_s *swap)
{
	t_node	tmp;

	if (swap->stack_a == NULL || swap->stack_a->next == NULL)
		return ;
	tmp.data = swap->stack_a->data;
	swap->stack_a->data = swap->stack_a->next->data;
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

	if (swap->stack_b == NULL || swap->stack_b->next == NULL)
		return ;
	tmp.data = swap->stack_b->data;
	swap->stack_b->data = swap->stack_b->next->data;
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
