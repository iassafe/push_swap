/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassafe <iassafe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:22:30 by iassafe           #+#    #+#             */
/*   Updated: 2023/05/13 16:42:35 by iassafe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	3
# endif

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
	int		size_stack_b;

}			t_s;
typedef struct s_data
{
	int		count;
	int		*tab;
	size_t	i;
	size_t	j;
	size_t	k;

}			t_data;

int		ft_check_sort(t_s *swap);
void	ft_push_a(t_s *swap);
void	ft_push_b(t_s *swap);
void	ft_rra(t_s *swap);
void	ft_rrb(t_s *swap);
void	ft_rrr(t_s *swap);
void	ft_rr(t_s *swap);
void	ft_ra(t_s *swap);
void	ft_rb(t_s *swap);
void	ft_sa(t_s *swap);
void	ft_sb(t_s *swap);
void	ft_ss(t_s *swap);
void	ft_parcing(t_s *swap);
void	ft_link(char **str, t_s *swap);
void	ft_table(t_s *swap, t_data *dt);
void	ft_index_stack(t_s *swap, t_data *dt);
void	ft_sort_table(t_data *dt);
void	ft_check(char **str);
void	ft_number(char **str);
void	ft_duplicat(char **str);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	ft_error(char *str);
void	ft_putstr(char *str);
size_t	ft_strlen(const char *str);
char	*ft_strjoin_space(char *left_str, char *buff, char s);
char	*ft_strtrim(char const *s1, char const *set, t_data	*dt);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		ft_memcmp( const void *pointer1, const void *pointer2, size_t size);
char	*get_next_line(int fd);
char	*ft_strchr(const char *str, char c);
char	*ft_strjoin(char *left_str, char *buff);
#endif
