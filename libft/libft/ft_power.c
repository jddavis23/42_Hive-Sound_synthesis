/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:32:23 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/22 16:53:59 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_power(double nb, int power)
{
	long double	result;

	result = 1;
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	if (power >= 0)
	{
		while (power >= 1)
		{
			result *= (long double)nb;
			--power;
		}
	}
	return (result);
}
