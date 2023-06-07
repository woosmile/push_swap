/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op_five_under.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:57:26 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/10 21:04:02 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra_sa(t_stack *a, int order)
{
	if (order == 0)
	{
		do_rra(a, 0);
		do_sa(a, 0);
	}
	else
	{
		do_sa(a, 0);
		do_rra(a, 0);
	}
}

void	op_three_under(t_stack *a)
{
	t_node	*node;

	node = a->top;
	if (a->size == 2 && node->num > node->next->num)
		do_sa(a, 0);
	else if (node->num < node->next->num && node->num < a->bot->num && \
		node->next->num > a->bot->num)
		do_rra_sa(a, 0);
	else if (node->num > node->next->num && node->num < a->bot->num && \
			node->next->num < a->bot->num)
		do_sa(a, 0);
	else if (node->num < node->next->num && node->num > a->bot->num && \
			node->next->num > a->bot->num)
		do_rra(a, 0);
	else if (node->num > node->next->num && node->num > a->bot->num && \
			node->next->num < a->bot->num)
		do_ra(a, 0);
	else if (node->num > node->next->num && node->num > a->bot->num && \
			node->next->num > a->bot->num)
		do_rra_sa(a, 1);
}

void	op_five_under(t_stack *a, t_stack *b)
{
	t_lis	lis;
	int		size_temp;

	lis = get_lis_main(a);
	if (lis.length == a->size)
		return ;
	if (lis.length != 0)
		free(lis.arr);
	size_temp = a->size;
	if (a->size <= 3)
		op_three_under(a);
	else
	{
		align_a(a, search_minimum(a));
		do_pb(a, b);
		if (size_temp == 5)
		{
			align_a(a, search_minimum(a));
			do_pb(a, b);
		}
		op_three_under(a);
		do_pa(a, b);
		if (size_temp == 5)
			do_pa(a, b);
	}
}
