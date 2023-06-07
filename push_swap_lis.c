/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:48:13 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/10 21:04:23 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	binary_search(int *lis, int left, int right, int target)
{
	int	mid;

	while (left < right)
	{
		mid = (left + right) / 2;
		if (lis[mid] < target)
			left = mid + 1;
		else
			right = mid;
	}
	return (right);
}

int	get_lis_temp(t_node *node, int *lis_temp, int *record)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	j = 1;
	while (node != 0)
	{
		if (lis_temp[i] < node->num)
		{
			lis_temp[i + 1] = node->num;
			record[j] = i + 2;
			i++;
		}
		else
		{
			pos = binary_search(lis_temp, 0, i, node->num);
			lis_temp[pos] = node->num;
			record[j] = pos + 1;
		}
		j++;
		node = node->next;
	}
	free(lis_temp);
	return (i);
}

void	get_lis_raw(t_node *node, t_lis *lis, int *record, int length)
{
	int		max;
	int		i;

	max = record[0];
	i = 1;
	while (i < length)
	{
		if (max < record[i])
			max = record[i];
		i++;
	}
	lis->length = max;
	lis->arr = (int *)malloc(max * sizeof(int));
	while (i - 1 >= 0)
	{
		if (max == record[i - 1])
		{
			lis->arr[record[i - 1] - 1] = node->num;
			max--;
		}
		node = node->prev;
		i--;
	}
}

t_lis	get_lis_main(t_stack *a)
{
	t_lis	lis;
	int		*record;
	int		desc;

	lis.arr = (int *)ft_calloc(a->size, sizeof(int));
	lis.arr[0] = a->top->num;
	record = (int *)ft_calloc(a->size, sizeof(int));
	record[0] = 1;
	desc = get_lis_temp(a->top->next, lis.arr, record);
	if (desc)
		get_lis_raw(a->bot, &lis, record, a->size);
	else
		lis.length = 0;
	if (lis.length == a->size)
		free(lis.arr);
	free(record);
	return (lis);
}
