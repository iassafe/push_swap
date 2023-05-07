/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:40:45 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/07 14:10:02 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_s swap, t_data dt)
{

	if (dt.count == 2)
		ft_sort_two(&swap);
	if (dt.count == 3)
		ft_sort_three(&swap);
	if (dt.count == 4)
		ft_sort_four(&swap);
	if (dt.count == 5)
		ft_sort_five(&swap);
	if (dt.count > 5 && dt.count <= 500)
	{
		ft_table(&swap, &dt);
		ft_sort_table(&dt);
		ft_index_stack(&swap, &dt);
		// while (swap.stack_a)
		// {
		// 	printf(">>>%d ", swap.stack_a->index);
		// 	swap.stack_a = swap.stack_a->next;
		// }
	}
	// while (swap.stack_a)
	// 	{
	// 		printf(">>>%d\n", swap.stack_a->data);
	// 		swap.stack_a = swap.stack_a->next;
	// 	}
}

int	main(int ac, char **av)
{
	t_s		swap;
	t_data	dt;
	int		i;
	char	*s;

	i = 1;
	s = NULL;
	if (ac > 1)
	{
		while (av[i])
		{
			ft_check(&av[i]);
			s = ft_strjoin(s, av[i], ' ');
			i++;
		}
		swap.str = ft_split(s, ' ');
		i = 0;
		// while(swap.str[i])
		// {
		// 	printf("%s\n", swap.str[i++]);
		// }
		dt.count = 0;
		while (swap.str[dt.count])
			dt.count++;
		ft_number(swap.str);
		ft_duplicat(swap.str);
		ft_link(swap.str, &swap);
		ft_sort(swap, dt);
	}
	else
		exit(0);
}
