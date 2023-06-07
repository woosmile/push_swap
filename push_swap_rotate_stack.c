/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 13:49:18 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/07 18:23:03 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack *a, t_stack *b, t_cycle *a_node, t_cycle *b_node)
{
	if (a_node->rev == 0 && b_node->rev == 0)
	{
		while (a_node->rot > 0 && b_node->rot > 0)
		{
			do_rr(a, b);
			a_node->rot--;
			b_node->rot--;
		}
	}
	else if (a_node->rev == 1 && b_node->rev == 1)
	{
		while (a_node->rot > 0 && b_node->rot > 0)
		{
			do_rrr(a, b);
			a_node->rot--;
			b_node->rot--;
		}
	}
}

void	rotate_a(t_stack *a, t_cycle *a_node)
{
	if (a_node->rev == 0)
	{
		while (a_node->rot > 0)
		{
			do_ra(a, 0);
			a_node->rot--;
		}
	}
	else
	{
		while (a_node->rot > 0)
		{
			do_rra(a, 0);
			a_node->rot--;
		}
	}
}

void	rotate_b(t_stack *b, t_cycle *b_node)
{
	if (b_node->rev == 0)
	{
		while (b_node->rot > 0)
		{
			do_rb(b, 0);
			b_node->rot--;
		}
	}
	else
	{
		while (b_node->rot > 0)
		{
			do_rrb(b, 0);
			b_node->rot--;
		}
	}
}

void	align_a(t_stack *a, int min_num)
{
	t_cycle	a_min;

	rot_cycle(a, min_num, &a_min);
	while (a_min.rot_temp > 0)
	{
		if (a_min.rev_temp == 0)
			do_ra(a, 0);
		else
			do_rra(a, 0);
		(a_min.rot_temp)--;
	}
}
