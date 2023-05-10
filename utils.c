/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:08:29 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/10 10:17:50 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	init_data(t_data *dt)
// {
// 	if (dt->len_tab <= 100)
// 		dt->offset = (dt->len_tab / 8);
// 	dt->mid = (dt->len_tab / 2);
// 	dt->start = dt->mid - dt->offset;
// 	dt->end = dt->mid + dt->offset;
// 	// printf("*%d +%d %d \n", dt->start, dt->end, dt->mid);
// }

// void	ft_size(t_s *swap)
// {
// 	t_node	*node;

// 	swap->size_stack_a = 0;
// 	node = swap->stack_a;
// 	while (node)
// 	{
// 		swap->size_stack_a++;
// 		node = node->next;
// 	}
// }

// void	ft_push_stack_a(t_s *swap, t_data *dt)
// {
// 	int	chunk;

// 	chunk = dt->count - 1;
// 	while (swap->stack_b)
// 	{
// 		while (swap->stack_b->index != chunk)
// 			ft_rb(swap);
// 		ft_push_a(swap);
// 		chunk--;
// 	}
// }

// void	ft_push_stack_b(t_s *swap, t_data *dt)
// {
// 	int	chunk;
// 	int	new_chunk;
// 	int	index_chunk;
// 	int	mid_chunk;

// 	chunk = (dt->count / 5);
// 	new_chunk = chunk;
// 	index_chunk = 1;
// 	mid_chunk = ((chunk * index_chunk) - (chunk / 2));
// 	printf("+++%d\n", mid_chunk);
// 	while (swap->stack_a)
// 	{
// 		if (swap->stack_a->index < chunk)
// 		{
// 			if (swap->stack_a->index < mid_chunk)
// 			{
// 				ft_push_b(swap);
// 			}
// 			else
// 			{
// 				ft_push_b(swap);
// 				ft_rb(swap);
// 			}
// 		}
// 		else
// 		{
// 			while (swap->stack_a->index >= chunk)
// 				ft_ra(swap);
// 			if (swap->stack_a->index < chunk)
// 			{
// 				if (swap->stack_a->index < mid_chunk)
// 				{
// 					ft_push_b(swap);
// 				}
// 				else
// 					ft_push_b(swap);
// 					ft_rb(swap);
// 			}
// 		}
// 		if (!ft_check_index(swap, chunk))
// 		{
// 			chunk += new_chunk;
// 			index_chunk++;
// 		}
// 	}
// }