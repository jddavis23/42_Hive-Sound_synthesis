/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:41:52 by jdavis            #+#    #+#             */
/*   Updated: 2022/04/04 12:10:05 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_up_down(char **str, int i, int carry)
{
	if ((*str)[i] < '9')
	{
		carry = 0;
		(*str)[i] += 1;
	}
	else
	{
		(*str)[i] = '0';
		carry = 1;
	}
	return (carry);
}

static void	ft_carry(int i, char **str, int carry)
{
	char	*temp;

	temp = NULL;
	while (--i >= 0 && carry)
	{
		if (carry && (*str)[i] != '.')
			carry = ft_up_down(str, i, carry);
	}
	if (carry)
	{
		temp = ft_strnew(ft_strlen(*str) + 1);
		if (!temp)
			ft_strdel(str);
		ft_strcat(ft_strcat(temp, "1"), *str);
		ft_strdel(str);
		*str = temp;
	}
}

void	ft_rounder(char **str, t_flags *info, int option)
{
	int	i;
	int	carry;

	carry = 0;
	i = ft_strlen_stop(*str, '.') + info->_precision;
	if (info->_p_true && !info->_precision)
		--i;
	if ((((*str)[i] - '0') % 2 != 0 && option == 1) || option == 2)
		carry = ft_up_down(str, i, carry);
	ft_carry(i, str, carry);
}
