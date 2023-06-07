/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:16:10 by woosekim          #+#    #+#             */
/*   Updated: 2023/03/18 13:52:23 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	do_rra(t_stack *a)
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

void	do_rrb(t_stack *b)
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

void	do_rrr(t_stack *a, t_stack *b)
{
	do_rra(a);
	do_rrb(b);
}
