/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 12:00:00 by woosekim          #+#    #+#             */
/*   Updated: 2026/03/28 12:00:00 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

long	ft_atol(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_av_arr(char **av_arr, int av_arr_idx)
{
	int	i;

	i = 0;
	while (i < av_arr_idx)
	{
		free(av_arr[i]);
		i++;
	}
	free(av_arr);
}

static int	argv_counter(int ac, char **av)
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
	if (!num_arr)
		return (NULL);
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = 0;
	free(s1);
	return (str);
}
