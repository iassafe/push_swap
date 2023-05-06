/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:40:45 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/06 18:06:32 by iassafe          ###   ########.fr       */
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

void	ft_table(t_s *swap, t_data *dt)
{
	t_node	*node;
	int		i;

	dt->tab = malloc((dt->count) * sizeof(int));
	node = swap->stack_a;
	i = 0;
	while (node)
	{
		dt->tab[i++] = node->data;
		node = node->next;
	}
	// i = 0;
	// while (i < 100)
	// {
	// 	printf("%d ", dt->tab[i++]);
	// }
}

void	ft_sort_table(t_data *dt)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (dt->tab[i])
	{
		j = i + 1;
		tmp = 0;
		while (dt->tab[j])
		{
			if ( dt->tab[i] > dt->tab[j])
			{
				tmp = dt->tab[i];
				dt->tab[i] = dt->tab[j];
				dt->tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	// i = 0;
	// while (i < 100)
	// {
	// 	printf("%d ", dt->tab[i++]);
	// }
}

void	ft_index_stack(t_s *swap, t_data *dt)
{
	int i;
	t_node *node;
	
	node = swap->stack_a;
	i = 0;
	while(i < 100)
	{
		while(node)
		{
			if (node->data == dt->tab[i])
			{
				node->index = i;
				node = swap->stack_a;
				break;
			}
			node = node->next;
		}
		i++;
	}
}


int	main(int ac, char **av)
{
	t_s swap;
	int i;
	char *s;
	t_data dt;

	i = 1;
	if (ac > 1)
	{
		while (av[i])
		{
			ft_check(&av[i]);
			s = ft_strjoin(s, av[i], ' ');
			i++;
		}
		swap.str = ft_split(s, ' ');
		dt.count = 0;
		while (swap.str[dt.count])
			dt.count++;
		ft_number(swap.str);
		ft_duplicat(swap.str);
		ft_link(swap.str, &swap);
		if (dt.count == 3)
			ft_sort_three(&swap);
		if (dt.count == 4)
			ft_sort_four(&swap);
		if (dt.count == 5)
			ft_sort_five(&swap);
		if (dt.count == 100)
			ft_table(&swap, &dt);
		ft_sort_table(&dt);
		ft_index_stack(&swap, &dt);
		while (swap.stack_a)
		{
			printf("%d ", swap.stack_a->index);
			swap.stack_a = swap.stack_a->next;
		}
		// while (swap.stack_b)
		// {
		// 	printf(">>>%d\n", swap.stack_b->data);
		// 	swap.stack_b = swap.stack_b->next;
		// }
	}
	else
		exit(0);
}
