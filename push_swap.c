/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:40:45 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/04 20:17:47 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_link(char **str, t_s *swap)
{
	t_node	*node;
	t_node	*p;
	int		i;

	i = 0;
	p = NULL;
	while (str[i])
	{
		node = malloc(sizeof(t_node));
		node->data = ft_atoi(str[i]);
		node->next = NULL;
		if (p == NULL)
		{
			p = node;
			swap->stack_a = p;
		}
		else
		{
			p->next = node;
			p = node;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_s swap;
	// t_node *point;
	int i;
	char *s;
	int k;

	k = 0;
	i = 1;
	if (ac > 1)
	{
		ft_check(&av[i]);
		while (av[i])
		{
			s = ft_strjoin(s, av[i], ' ');
			i++;
		}
		swap.str = ft_split(s, ' ');
		if (swap.str[k] == NULL)
			ft_error("lllll\n");
		ft_number(swap.str);
		ft_duplicat(swap.str);
		ft_link(swap.str, &swap);
		// ft_push_b(&swap);
		// ft_push_a(&swap);
		ft_sort_three(&swap);
		while (swap.stack_a)
		{
			printf("---%d\n", swap.stack_a->data);
			swap.stack_a = swap.stack_a->next;
		}
		while (swap.stack_b)
		{
			printf(">>>%d\n", swap.stack_b->data);
			swap.stack_b = swap.stack_b->next;
		}
	}
	else
		exit(0);
}
