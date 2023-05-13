/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:40:45 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/13 17:14:20 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
		ft_sa(swap);
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
		line = get_next_line(0);
	}
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
		ft_parcing(&swap);
		ft_read_input(&swap);
	}
	else
		exit(0);
}
