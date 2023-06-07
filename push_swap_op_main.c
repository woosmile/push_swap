/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 15:23:06 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/10 21:04:05 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ascending_order(t_stack *a, t_stack *b)
{
	int	i;
	int	cycle;

	i = 0;
	cycle = a->size;
	while (i < cycle - 1)
	{
		do_rra(a, 0);
		do_pb(a, b);
		i++;
	}
	while (i > 0)
	{
		do_pa(a, b);
		i--;
	}
}

int	average_a(t_stack *a)
{
	int		num;
	t_node	*node;

	num = 0;
	node = a->top;
	while (node != 0)
	{
		num = num + node->num;
		node = node->next;
	}
	return (num / a->size);
}

void	a_to_b(t_stack *a, t_stack *b, t_lis lis)
{
	t_node	*node;
	int		pos;
	int		avg;

	node = a->top;
	avg = average_a(a);
	while (lis.length != a->size)
	{
		pos = binary_search(lis.arr, 0, lis.length - 1, node->num);
		if (lis.arr[pos] != node->num)
		{
			do_pb(a, b);
			if (node->num > avg)
				do_rb(b, 0);
		}	
		else
			do_ra(a, 0);
		node = a->top;
	}
	align_a(a, lis.arr[0]);
	free(lis.arr);
}

void	b_to_a(t_stack *a, t_stack *b)
{
	int		min_num;
	t_cycle	a_node;
	t_cycle	b_node;

	min_num = a->top->num;
	while (b->size != 0)
	{
		find_min_rot(a, b, &a_node, &b_node);
		rotate_both(a, b, &a_node, &b_node);
		rotate_a(a, &a_node);
		rotate_b(b, &b_node);
		do_pa(a, b);
		if (min_num > a->top->num)
			min_num = a->top->num;
	}
	align_a(a, min_num);
}

void	op_main(t_stack *a, t_stack *b)
{
	t_lis	lis;

	lis = get_lis_main(a);
	if (lis.length == a->size)
		return ;
	else if (lis.length == 0)
		ascending_order(a, b);
	else
	{
		a_to_b(a, b, lis);
		b_to_a(a, b);
	}
}
