/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:16:07 by woosekim          #+#    #+#             */
/*   Updated: 2023/03/20 14:10:47 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_stack *a, int rr)
{
	t_node	*temp;

	if (a->size > 1)
	{
		temp = a->top;
		a->top = a->top->next;
		a->top->prev = 0;
		a->bot->next = temp;
		temp->prev = a->bot;
		a->bot = temp;
		a->bot->next = 0;
	}
	if (rr == 0)
		write(1, "ra\n", 3);
}

void	do_rb(t_stack *b, int rr)
{
	t_node	*temp;

	if (b->size > 1)
	{
		temp = b->top;
		b->top = b->top->next;
		b->top->prev = 0;
		b->bot->next = temp;
		temp->prev = b->bot;
		b->bot = temp;
		b->bot->next = 0;
	}
	if (rr == 0)
		write(1, "rb\n", 3);
}

void	do_rr(t_stack *a, t_stack *b)
{
	do_ra(a, 1);
	do_rb(b, 1);
	write(1, "rr\n", 3);
}
