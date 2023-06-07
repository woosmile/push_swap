/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 17:40:59 by woosekim          #+#    #+#             */
/*   Updated: 2023/03/13 15:39:43 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char		*arr;
	size_t		len;
	size_t		i;

	len = ft_strlen(s1);
	i = 0;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	while (i < len)
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}
