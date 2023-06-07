/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:00:24 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/10 21:26:31 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int				num;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bot;
}	t_stack;

typedef struct s_lis
{
	int	*arr;
	int	length;
}	t_lis;

typedef struct s_cycle
{
	int	rev;
	int	rot;
	int	rev_temp;
	int	rot_temp;
}	t_cycle;

long	ft_atol(const char *str);

void	check_argv(int ac, char **av);

void	free_av_arr(char **av_arr, int av_arr_idx);
int		*argv_to_number(int ac, char **av, int av_idx, int *num_arr_count);
t_node	*connect_arg_value(int ac, char **av, t_node *head, t_node *head_temp);

t_lis	get_lis_main(t_stack *a);
int		binary_search(int *lis, int left, int right, int target);

void	op_five_under(t_stack *a, t_stack *b);
void	op_main(t_stack *a, t_stack *b);

void	do_sa(t_stack *a, int ss);
void	do_sb(t_stack *b, int ss);
void	do_ss(t_stack *a, t_stack *b);

void	do_pa(t_stack *a, t_stack *b);
void	do_pb(t_stack *a, t_stack *b);

void	do_ra(t_stack *a, int rr);
void	do_rb(t_stack *b, int rr);
void	do_rr(t_stack *a, t_stack *b);

void	do_rra(t_stack *a, int rrr);
void	do_rrb(t_stack *b, int rrr);
void	do_rrr(t_stack *a, t_stack *b);

int		search_minimum(t_stack *a);
int		search_node(t_stack *a, int num);

int		rot_cycle(t_stack *common, int num, t_cycle *common_node);
void	find_min_rot(t_stack *a, t_stack *b, t_cycle *a_node, t_cycle *b_node);

void	rotate_both(t_stack *a, t_stack *b, t_cycle *a_node, t_cycle *b_node);
void	rotate_a(t_stack *a, t_cycle *a_node);
void	rotate_b(t_stack *b, t_cycle *b_node);
void	align_a(t_stack *a, int min_num);

#endif