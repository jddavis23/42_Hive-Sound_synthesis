/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_ascii_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:38:33 by jdavis            #+#    #+#             */
/*   Updated: 2022/04/04 12:38:46 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_minus(long double nb)
{
	if (nb < (long double)0 || 1 / nb < 0)
		return (1);
	return (0);
}

void	ft_option(long double nb, int *option)
{
	if (nb < 0)
		nb *= -1;
	if (nb - (long long unsigned int)nb == 0.5)
		*option = 1;
	else if (nb - (long long unsigned int)nb > 0.5)
		*option = 2;
}
