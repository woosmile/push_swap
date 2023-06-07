/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:35:21 by woosekim          #+#    #+#             */
/*   Updated: 2023/03/20 15:46:52 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_node	*ft_lstnew(int num, t_node *prev)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->num = num;
	node->next = 0;
	node->prev = prev;
	return (node);
}

void	free_av_arr(char **av_arr, int av_arr_idx)
{
	int	i;

	i = 0;
	while (i <= av_arr_idx)
	{
		free(av_arr[i]);
		i++;
	}
	free(av_arr);
}

int	argv_counter(int ac, char **av)
{
	int	x;
	int	y;
	int	count;

	x = 1;
	count = 0;
	while (x < ac)
	{
		y = 0;
		while (av[x][y] != 0)
		{
			if (av[x][y] != ' ' && (av[x][y + 1] == ' ' || av[x][y + 1] == 0))
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

int	*argv_to_number(int ac, char **av, int av_idx, int *num_arr_count)
{
	char	**av_arr;
	int		av_arr_idx;
	int		*num_arr;
	int		num_arr_idx;

	*num_arr_count = argv_counter(ac, av);
	num_arr = (int *)malloc(sizeof(int) * (*num_arr_count));
	num_arr_idx = 0;
	while (av_idx < ac)
	{
		av_arr = ft_split(av[av_idx], ' ');
		av_arr_idx = 0;
		while (av_arr[av_arr_idx] != 0)
		{
			num_arr[num_arr_idx] = ft_atol(av_arr[av_arr_idx]);
			num_arr_idx++;
			av_arr_idx++;
		}
		free_av_arr(av_arr, av_arr_idx);
		av_idx++;
	}
	return (num_arr);
}

t_node	*connect_arg_value(int ac, char **av, t_node *head, t_node *head_temp)
{
	t_node	*new;
	int		*num_arr;
	int		num_arr_idx;
	int		num_arr_count;

	num_arr_idx = 0;
	num_arr = argv_to_number(ac, av, 1, &num_arr_count);
	while (num_arr_idx < num_arr_count)
	{
		new = ft_lstnew(num_arr[num_arr_idx], head_temp);
		if (!head)
		{
			head = new;
			head_temp = head;
			head->next = 0;
		}
		else
		{
			head_temp->next = new;
			head_temp = head_temp->next;
		}
		num_arr_idx++;
	}
	free(num_arr);
	return (head);
}
