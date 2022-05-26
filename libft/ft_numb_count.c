/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:32:33 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/16 10:38:10 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numb_count(char *str)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	count = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9' && flag)
		{
			++count;
			flag = 0;
		}
		if (str[i] == ' ' || str[i] == '\t')
			flag = 1;
		++i;
	}
	return (count);
}
