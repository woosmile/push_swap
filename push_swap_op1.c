/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:16:04 by woosekim          #+#    #+#             */
/*   Updated: 2023/03/30 16:34:15 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_stack *a, int ss)
{
	t_node	*temp;

	if (a->size > 1)
	{
		temp = a->top;
		a->top = a->top->next;
		a->top->prev = 0;
		if (a->size > 2)
			a->top->next->prev = temp;
		temp->next = a->top->next;
		temp->prev = a->top;
		a->top->next = temp;
		if (a->size == 2)
			a->bot = temp;
	}
	if (ss == 0)
		write(1, "sa\n", 3);
}

void	do_sb(t_stack *b, int ss)
{
	t_node	*temp;

	if (b->size > 1)
	{
		temp = b->top;
		b->top = b->top->next;
		b->top->prev = 0;
		if (b->size > 2)
			b->top->next->prev = temp;
		temp->next = b->top->next;
		temp->prev = b->top;
		b->top->next = temp;
		if (b->size == 2)
			b->bot = temp;
	}
	if (ss == 0)
		write(1, "sb\n", 3);
}

void	do_ss(t_stack *a, t_stack *b)
{
	do_sa(a, 1);
	do_sb(b, 1);
	write(1, "ss\n", 3);
}
