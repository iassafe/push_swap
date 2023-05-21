/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:40:45 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/20 20:39:12 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_free(t_s *swap)
{
	free(swap->s);
	free_tab(swap->table);
	free_stack(swap->stack_a);
	free_stack(swap->stack_b);
}

int	ft_check_sort(t_s *swap)
{
	t_node	*node;

	node = swap->stack_a;
	while (node && node->next)
	{
		if (node->data > node->next->data)
			return (1);
		node = node->next;
	}
	return (0);
}

void	ft_check_oper(char *line, t_s *swap)
{
	if (ft_memcmp(line, "sa\n", 4) == 0)
		ft_sa(swap);
	else if (ft_memcmp(line, "sb\n", 3) == 0)
		ft_sb(swap);
	else if (ft_memcmp(line, "ss\n", 3) == 0)
		ft_ss(swap);
	else if (ft_memcmp(line, "pa\n", 3) == 0)
		ft_push_a(swap);
	else if (ft_memcmp(line, "pb\n", 3) == 0)
		ft_push_b(swap);
	else if (ft_memcmp(line, "ra\n", 3) == 0)
		ft_ra(swap);
	else if (ft_memcmp(line, "rb\n", 3) == 0)
		ft_rb(swap);
	else if (ft_memcmp(line, "rr\n", 3) == 0)
		ft_rr(swap);
	else if (ft_memcmp(line, "rrr\n", 4) == 0)
		ft_rrr(swap);
	else if (ft_memcmp(line, "rra\n", 4) == 0)
		ft_rra(swap);
	else if (ft_memcmp(line, "rrb\n", 4) == 0)
		ft_rrb(swap);
	else
		ft_error("Error\n");
}

void	ft_read_input(t_s *swap)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		ft_check_oper(line, swap);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (swap->stack_b == NULL && ft_check_sort(swap) == 0)
		write(1, "OK\n", 3);
	if (ft_check_sort(swap) != 0 || swap->stack_b != NULL)
		write(1, "KO\n", 3);
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
		ft_parsing(&swap);
		ft_read_input(&swap);
		ft_free(&swap);
	}
	else
		exit(0);
}
