/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:40:45 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/13 17:36:59 by iassafe          ###   ########.fr       */
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
	}
}

int	main(int ac, char **av)
{
	t_s		swap;
	t_data	dt;
	int		i;
	char	*s;
	char	*str;

	i = 1;
	s = NULL;
	str = NULL;
	if (ac > 1)
	{
		while (av[i])
		{	
			str = ft_strtrim(av[i], " ", &dt);
			if (str[0] == '\0')
				ft_error("Error\n");
			s = ft_strjoin_space(s, av[i], ' ');
			i++;
		}
		swap.str = ft_split(s, ' ');
		ft_parcing(&swap, &dt);
	}
	else
		exit(0);
}
