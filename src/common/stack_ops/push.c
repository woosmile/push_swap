/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:00:00 by woosekim          #+#    #+#             */
/*   Updated: 2026/03/28 12:00:00 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	move_element(t_stack *src, t_stack *dest, t_node *temp)
{
	if (src->size > 1)
	{
		src->top->next->prev = 0;
		src->top = src->top->next;
	}
	else
	{
		src->top = 0;
		src->bot = 0;
	}
	if (dest->size > 0)
	{
		dest->top->prev = temp;
		temp->next = dest->top;
	}
	else
	{
		temp->next = 0;
		dest->bot = temp;
	}
}

void	core_pa(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (b->size > 0)
	{
		temp = b->top;
		move_element(b, a, temp);
		temp->prev = 0;
		a->top = temp;
		b->size--;
		a->size++;
	}
}

void	core_pb(t_stack *a, t_stack *b)
{
	t_node	*temp;

	if (a->size > 0)
	{
		temp = a->top;
		move_element(a, b, temp);
		temp->prev = 0;
		b->top = temp;
		a->size--;
		b->size++;
	}
}
