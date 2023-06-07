/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:16:07 by woosekim          #+#    #+#             */
/*   Updated: 2023/03/18 13:51:00 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	do_ra(t_stack *a)
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

void	do_rb(t_stack *b)
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

void	do_rr(t_stack *a, t_stack *b)
{
	do_ra(a);
	do_rb(b);
}
