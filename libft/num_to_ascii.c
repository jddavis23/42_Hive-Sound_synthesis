/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_ascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:31:41 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/30 11:42:48 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long int	ft_nb_lt(long long int nb, int *sign, int *count,
		int in)
{
	if (nb < 0)
	{
		*sign = -1;
		if (in == 1)
			++(*count);
		return (nb * -1);
	}
	else
		return (nb);
}

static char	*ft_extr_rtrn(long long int nb, char c, char **str, int minus)
{
	if (c == '%')
	{
		*str = ft_strdup("%");
		if (!*str)
			return (NULL);
		return (*str);
	}
	if (nb == 0)
	{
		if (minus == 1)
			*str = ft_strdup("-0");
		else
			*str = ft_strdup("0");
		if (!*str)
			return (NULL);
	}
	return (NULL);
}

static char	*ft_helper(long long int nb, t_flags *info, int count, int choice)
{
	char					*str;
	int						sign;
	unsigned long long int	dup_nb;

	str = NULL;
	sign = 1;
	str = ft_strnew(count);
	if (!str)
		return (NULL);
	dup_nb = ft_nb_lt(nb, &sign, &count, 0);
	while (dup_nb > 0)
	{
		str[--count] = ft_char_digit((char)(dup_nb % choice),
				info->_type);
		dup_nb /= choice;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

static void	ft_struct_nb(t_flags *info, long long int nb, int minus)
{
	if (nb > 0)
		info->_gt = 1;
	else if (nb < 0 || minus == 1)
		info->_gt = -1;
	else
		info->_gt = 0;
}

char	*ft_num_toa(long long int nb, t_flags *info, int choice, int minus)
{
	int							count;
	char						*str;
	unsigned long long int		dup_nb;
	int							sign;

	sign = 1;
	str = NULL;
	count = 0;
	ft_struct_nb(info, nb, minus);
	if (ft_extr_rtrn(nb, info->_type, &str, minus) || info->_type == '%')
		return (str);
	else if (!str && (info->_type == '%' || nb == 0))
		return (NULL);
	dup_nb = ft_nb_lt(nb, &sign, &count, 1);
	while (dup_nb > 0)
	{
		dup_nb /= choice;
		count++;
	}
	if (nb != 0)
		str = ft_helper(nb, info, count, choice);
	if (info->_type != 'f' && str)
		info->_p_check = ft_precision_nb(info, &str, nb);
	return (str);
}
