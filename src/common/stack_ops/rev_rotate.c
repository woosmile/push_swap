/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:00:00 by woosekim          #+#    #+#             */
/*   Updated: 2026/03/28 12:00:00 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	core_rra(t_stack *a)
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
}

void	core_rrb(t_stack *b)
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
}

void	core_rrr(t_stack *a, t_stack *b)
{
	core_rra(a);
	core_rrb(b);
}
