/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:17:46 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/06 16:08:03 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_rotate(t_s *swap)
{
	t_node	*node;

	node = swap->stack_a;
	while (node->next)
		node = node->next;
	node->next = swap->stack_a;
	swap->stack_a = swap->stack_a->next;
	node->next->next = NULL;
}
void	ft_ra(t_s *swap)
{
	ft_rotate(swap);
	write(1, "ra\n", 3);
}

void	ft_rb(t_s *swap)
{
	ft_rotate(swap);
	write(1, "rb\n", 3);
}

void	ft_rr(t_s *swap)
{
	ft_ra(swap);
	ft_rb(swap);
	write(1, "rr\n", 3);
}
