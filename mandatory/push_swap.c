/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:40:45 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/15 16:56:52 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(t_s *swap)
{
	t_node	*node;

	node = swap->stack_a;
	while (node->next)
	{
		if (node->data > node->next->data)
			return (1);
		node = node->next;
	}
	return (0);
}

void	ft_sort(t_s *swap, t_data *dt)
{
	if (dt->count == 2)
		ft_sort_two(swap);
	if (dt->count == 3)
		ft_sort_three(swap);
	if (dt->count == 4)
		ft_sort_four(swap);
	if (dt->count == 5)
		ft_sort_five(swap);
	if (dt->count > 5 && dt->count <= 500)
	{
		ft_table(swap, dt);
		ft_sort_table(dt);
		ft_index_stack(swap, dt);
		ft_push_stack_b(swap, dt);
		ft_size(swap);
		ft_push_stack_a(swap, dt);
		free(dt->tab);
	}
}

void	ft_parsing(t_s *swap, t_data *dt)
{
	dt->count = 0;
	while (swap->table[dt->count])
		dt->count++;
	ft_check(swap->table);
	ft_number(swap->table);
	ft_duplicat(swap->table);
	ft_link(swap->table, swap);
	if (ft_check_sort(swap) != 0)
		ft_sort(swap, dt);
	free_tab(swap->table);
	free_stack(swap);
}

int	main(int ac, char **av)
{
	t_s		swap;
	t_data	dt;
	int		i;

	i = 1;
	swap.s = NULL;
	swap.str = NULL;
	if (ac > 1)
	{
		while (av[i])
		{
			swap.str = ft_strtrim(av[i], " ", &dt);
			if (swap.str[0] == '\0')
				ft_error("Error\n");
			free(swap.str);
			swap.s = ft_strjoin_space(swap.s, av[i], ' ');
			i++;
		}
		swap.table = ft_split(swap.s, ' ');
		free(swap.s);
		ft_parsing(&swap, &dt);
	}
	else
		exit(0);
}
