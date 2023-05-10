/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:27:24 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/09 17:02:04 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_push_b(t_s *swap)
{
	t_node	*node;

	if (swap->stack_a == NULL)
		return ;
	node = swap->stack_a;
	swap->stack_a = swap->stack_a->next;
	node->next = swap->stack_b;
	swap->stack_b = node;
	write(1, "pb\n", 3);
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
	write(1, "pa\n", 3);
}

