/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:00:00 by woosekim          #+#    #+#             */
/*   Updated: 2026/03/28 12:00:00 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	core_ra(t_stack *a)
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
}

void	core_rb(t_stack *b)
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
}

void	core_rr(t_stack *a, t_stack *b)
{
	core_ra(a);
	core_rb(b);
}
