/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate_cycle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:26:45 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/07 18:23:57 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	forward(int *rot, t_stack *common, int num, t_cycle *common_node)
{
	int		mid;
	t_node	*node;

	mid = common->size / 2;
	node = common->top;
	common_node->rev_temp = 0;
	while (*rot <= mid)
	{
		if (node->num == num)
			return (1);
		else
		{
			node = node->next;
			(*rot)++;
		}
	}
	return (0);
}

int	backward(int *rot, t_stack *common, int num, t_cycle *common_node)
{
	int		mid;
	t_node	*node;

	mid = common->size / 2;
	node = common->bot;
	common_node->rev_temp = 1;
	while (*rot < mid)
	{
		if (node->num == num)
			return (1);
		else
		{
			node = node->prev;
			(*rot)++;
		}
	}
	return (0);
}

int	rot_cycle(t_stack *common, int num, t_cycle *common_node)
{
	int	rot;
	int	find;

	rot = 0;
	find = forward(&rot, common, num, common_node);
	if (find)
	{
		common_node->rot_temp = rot;
		return (rot);
	}
	else
	{
		rot = 0;
		find = backward(&rot, common, num, common_node);
		if (find)
		{
			rot++;
			common_node->rot_temp = rot;
			return (rot);
		}
	}
	return (0);
}

void	find_min_rot(t_stack *a, t_stack *b, t_cycle *a_node, t_cycle *b_node)
{
	int		min;
	int		min_new;
	t_node	*node;

	min = rot_cycle(a, search_node(a, b->top->num), a_node);
	a_node->rev = a_node->rev_temp;
	a_node->rot = a_node->rot_temp;
	b_node->rev = 0;
	b_node->rot = 0;
	node = b->top->next;
	while (node != 0)
	{
		min_new = rot_cycle(b, node->num, b_node) + \
				rot_cycle(a, search_node(a, node->num), a_node);
		if (min > min_new)
		{
			min = min_new;
			a_node->rev = a_node->rev_temp;
			a_node->rot = a_node->rot_temp;
			b_node->rev = b_node->rev_temp;
			b_node->rot = b_node->rot_temp;
		}
		node = node->next;
	}
}
