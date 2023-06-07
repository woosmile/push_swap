/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_argv_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:09:54 by woosekim          #+#    #+#             */
/*   Updated: 2023/04/09 19:41:31 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_only_blank(char *av)
{
	int	len;
	int	y;
	int	result;

	len = ft_strlen(av);
	y = 0;
	result = 1;
	while (y < len)
	{
		if (av[y] == ' ')
			result = 0;
		else
			return (1);
		y++;
	}
	return (result);
}

int	check_duplication(int ac, char **av)
{
	int		*num_arr;
	int		num_arr_count;
	int		i;
	int		j;

	num_arr = argv_to_number(ac, av, 1, &num_arr_count);
	i = 0;
	while (i < num_arr_count)
	{
		j = i + 1;
		while (j < num_arr_count)
		{
			if (num_arr[i] == num_arr[j])
			{
				free(num_arr);
				return (0);
			}
			j++;
		}
		i++;
	}
	free(num_arr);
	return (1);
}

int	check_elements(char *av)
{
	int	y;

	y = 0;
	while (av[y] != 0)
	{
		if (!((av[y] >= '0' && av[y] <= '9') || \
			av[y] == ' ' || av[y] == '-' || av[y] == '+'))
			return (0);
		else if (av[y] == '-' || av[y] == '+')
		{
			if (y > 0 && av[y - 1] != ' ')
				return (0);
			if (!(av[y + 1] >= '0' && av[y + 1] <= '9'))
				return (0);
		}
		y++;
	}
	return (1);
}

int	check_min_max_len(int ac, char **av)
{
	int		i;
	char	**av_arr;
	int		arr_i;
	long	num;

	i = 1;
	while (i < ac)
	{
		av_arr = ft_split(av[i], ' ');
		arr_i = 0;
		while (av_arr[arr_i] != 0)
		{
			num = ft_atol(av_arr[arr_i]);
			if (num < INT_MIN || num > INT_MAX || ft_strlen(av_arr[arr_i]) > 11)
				return (0);
			arr_i++;
		}
		free_av_arr(av_arr, arr_i);
		i++;
	}
	return (1);
}

void	check_argv(int ac, char **av)
{
	int	x;
	int	result;

	x = 1;
	result = 1;
	while (x < ac)
	{
		if (!av[x][0] || !check_only_blank(av[x]) || !check_elements(av[x]))
		{
			result = 0;
			break ;
		}
		x++;
	}
	if (!check_min_max_len(ac, av))
		result = 0;
	else if (!check_duplication(ac, av))
		result = 0;
	if (!result)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
