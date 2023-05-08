/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:22:30 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/08 17:31:34 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	int				index;

}t_node;

typedef struct s_swap
{
	char	**str;
	t_node	*stack_a;
	t_node	*stack_b;
	int		size_stack_a;
	int		first_chunk;

}			t_s;
typedef struct s_data
{
	int	count;
	int	*tab;
	int	len_tab;
	int	offset;
	int	mid;
	int	start;
	int	end;

}			t_data;

void	ft_push_stack_a(t_s *swap, t_data *dt);
void	ft_push_stack_b(t_s *swap, t_data *dt);
void	ft_size(t_s *swap);
void	ft_sort_five(t_s *swap);
void	ft_sort_four(t_s *swap);
void	ft_sort_three(t_s *swap);
void	ft_sort_two(t_s	*swap);
void	ft_push_a(t_s *swap);
void	ft_push_b(t_s *swap);
void	ft_rra(t_s *swap);
void	ft_ra(t_s *swap);
void	ft_rb(t_s *swap);
void	ft_sa(t_s *swap);
void	ft_sb(t_s *swap);
void	ft_link(char **str, t_s *swap);
void	ft_table(t_s *swap, t_data *dt);
void	ft_index_stack(t_s *swap, t_data *dt);
void	ft_sort_table(t_data *dt);
void	ft_parcing(t_s *swap);
void	ft_check(char **str);
void	ft_number(char **str);
void	ft_duplicat(char **str);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	ft_error(char *str);
void	ft_putstr(char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *left_str, char *buff, char s);
#endif
