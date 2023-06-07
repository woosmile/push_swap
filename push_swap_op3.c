/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:16:10 by woosekim          #+#    #+#             */
/*   Updated: 2023/03/20 14:11:27 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra(t_stack *a, int rrr)
{
	t_node	*temp;

	if (a->size > 1)
	{
		temp = a->bot;
		a->bot = a->bot->prev;
		a->bot->next = 0;
		temp->next = a->top;
		a->top->prev = temp;
		a->top = temp;
		a->top->prev = 0;
	}
	if (rrr == 0)
		write(1, "rra\n", 4);
}

void	do_rrb(t_stack *b, int rrr)
{
	t_node	*temp;

	if (b->size > 1)
	{
		temp = b->bot;
		b->bot = b->bot->prev;
		b->bot->next = 0;
		temp->next = b->top;
		b->top->prev = temp;
		b->top = temp;
		b->top->prev = 0;
	}
	if (rrr == 0)
		write(1, "rrb\n", 4);
}

void	do_rrr(t_stack *a, t_stack *b)
{
	do_rra(a, 1);
	do_rrb(b, 1);
	write(1, "rrr\n", 4);
}
