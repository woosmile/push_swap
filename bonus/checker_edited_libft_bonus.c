/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_edited_libft_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:10:22 by woosekim          #+#    #+#             */
/*   Updated: 2023/03/20 15:47:01 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

char	*ft_strjoin(char *s1, char *s2)
{
	char				*str;
	size_t				len1;
	size_t				len2;
	unsigned long long	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2 != 0)
	{
		str[i++] = *s2;
		s2++;
	}
	str[i] = 0;
	free(s1);
	return (str);
}
