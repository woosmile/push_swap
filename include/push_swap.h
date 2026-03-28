/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:00:00 by woosekim          #+#    #+#             */
/*   Updated: 2026/03/28 12:00:00 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "utils.h"

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

/* Algorithm - LIS */
t_lis	get_lis_main(t_stack *a);
int		binary_search(int *lis, int left, int right, int target);

/* Sorting */
void	op_five_under(t_stack *a, t_stack *b);
void	op_main(t_stack *a, t_stack *b);

/* Operation Wrappers (with printing) */
void	ps_sa(t_stack *a);
void	ps_sb(t_stack *b);
void	ps_ss(t_stack *a, t_stack *b);
void	ps_pa(t_stack *a, t_stack *b);
void	ps_pb(t_stack *a, t_stack *b);
void	ps_ra(t_stack *a);
void	ps_rb(t_stack *b);
void	ps_rr(t_stack *a, t_stack *b);
void	ps_rra(t_stack *a);
void	ps_rrb(t_stack *b);
void	ps_rrr(t_stack *a, t_stack *b);

/* Search & Rotation Utils */
int		search_minimum(t_stack *a);
int		search_node(t_stack *a, int num);
int		rot_cycle(t_stack *common, int num, t_cycle *common_node);
void	find_min_rot(t_stack *a, t_stack *b, t_cycle *a_node, t_cycle *b_node);
void	rotate_both(t_stack *a, t_stack *b, t_cycle *a_node, t_cycle *b_node);
void	rotate_a(t_stack *a, t_cycle *a_node);
void	rotate_b(t_stack *b, t_cycle *b_node);
void	align_a(t_stack *a, int min_num);

#endif
