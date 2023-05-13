/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:27:24 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/13 14:15:38 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap_bonus.h"

void	ft_push_b(t_s *swap)
{
	t_node	*node;

	if (swap->stack_a == NULL)
		return ;
	node = swap->stack_a;
	swap->stack_a = swap->stack_a->next;
	node->next = swap->stack_b;
	swap->stack_b = node;
}

void	ft_push_a(t_s *swap)
{
	t_node	*node;

	if (swap->stack_b == NULL)
		return ;
	node = swap->stack_a;
	swap->stack_a = swap->stack_b;
	swap->stack_b = swap->stack_b->next;
	swap->stack_a->next = node;
}
