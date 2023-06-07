/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_search_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:18:22 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/06 17:52:14 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_minimum(t_stack *a)
{
	int		i;
	int		min;
	t_node	*node;

	i = 0;
	min = a->top->num;
	node = a->top->next;
	while (i < a->size - 1)
	{
		if (min > node->num)
			min = node->num;
		node = node->next;
		i++;
	}
	return (min);
}

int	initial_over_min(t_node **node, int num)
{
	int	over_min;

	over_min = 0;
	while (*node != 0)
	{
		if ((*node)->num > num)
		{
			over_min = (*node)->num;
			return (over_min);
		}
		(*node) = (*node)->next;
	}
	return (over_min);
}

int	search_node(t_stack *a, int num)
{
	t_node	*node;
	int		over_min;
	int		over_min_new;

	node = a->top;
	over_min = initial_over_min(&node, num);
	if (over_min == 0)
		return (search_minimum(a));
	while (node != 0)
	{
		if (node->num > num)
		{
			over_min_new = node->num;
			if (over_min > over_min_new)
				over_min = over_min_new;
		}
		node = node->next;
	}
	return (over_min);
}
