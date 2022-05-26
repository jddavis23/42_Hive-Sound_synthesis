/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:51:30 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/29 11:06:25 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	*ft_prfx_sub_div(t_flags *info, char type, int *i)
{
	ft_bzero(info->_h_prfx, 3);
	if (type == 'x' || type == 'X' || type == 'p')
	{
		info->_div = 16;
		info->_h_sub = 2;
		info->_h_prfx[0] = '0';
		if (type == 'p')
			info->_h_prfx[1] = 'x';
		else
			info->_h_prfx[1] = type;
	}
	else if (type == 'o')
	{
		info->_div = 8;
		info->_h_sub = 1;
		info->_h_prfx[0] = '0';
	}
	else
		info->_div = 10;
	++*i;
	return (info);
}

static t_flags	*ft_length_flags(t_flags *info, const char *str, int *i)
{
	if (str[*i] == 'h' && ft_is_type(str[*i + 1]) == -1)
		info->_h = 1;
	else if (str[*i] == 'l' && ft_is_type(str[*i + 1]) == -1)
		info->_l = 1;
	else if (str[*i] == 'h' && str[*i + 1] == 'h')
		info->_hh = 1;
	else if (str[*i] == 'l' && str[*i + 1] == 'l')
		info->_ll = 1;
	else if (str[*i] == 'L' && str[*i + 1] == 'f')
		info->_el = 1;
	if (info->_h == 1 || info->_l == 1 || info->_el == 1)
		(*i)++;
	else if (info->_hh == 1 || info->_ll == 1)
		*i += 2;
	if (ft_is_type(str[*i]) == 1)
	{
		free(info);
		return (NULL);
	}
	return (info);
}

static t_flags	*ft_first_flags(t_flags *info, const char *str, int *i)
{
	if (str[*i] == '0' && info->_minus == 0)
		info->_zero = 1;
	if (str[*i] == '#')
		info->_hash = 1;
	if (str[*i] == ' ' && info->_plus == 0)
		info->_space = 1;
	if (str[*i] == '-')
	{
		info->_zero = 0;
		info->_minus = 1;
	}
	if (str[*i] == '+')
	{
		info->_space = 0;
		info->_plus = 1;
	}
	++*i;
	return (info);
}

static t_flags	*ft_true_struct_ii(t_flags *info,
	const char *str, int *i, va_list *ap)
{
	if (str[*i] == '.')
	{
		info->_p_true = 1;
		++*i;
		if (str[*i] == '*')
		{
			info->_precision = va_arg(*ap, int);
			++*i;
		}
		else
		{
			info->_precision = ft_atoi(&str[*i]);
			while (str[*i] >= '0' && str[*i] <= '9')
				++*i;
		}
	}
	info = ft_length_flags(info, str, i);
	if (!info)
		return (NULL);
	info->_type = str[*i];
	if (info->_type == 'f' && !info->_p_true)
		info->_precision = 6;
	info = ft_prfx_sub_div(info, str[*i], i);
	return (info);
}

t_flags	*ft_true_struct(t_flags *info, const char *str, int *i, va_list *ap)
{
	info = ft_create_struct(info);
	while (str[*i] == '0' || str[*i] == ' ' || str[*i] == '+' || str[*i] == '-'
		|| str[*i] == '#')
		info = ft_first_flags(info, str, i);
	if ((str[*i] >= '0' && str[*i] <= '9') || str[*i] == '*')
	{
		if (str[*i] == '*')
		{
			++*i;
			info->_width = va_arg(*ap, int);
			if (info->_width < 0)
			{
				info->_width = ft_abs(info->_width);
				info->_minus = 1;
			}
		}
		else
		{
			info->_width = ft_atoi(&str[*i]);
			while (str[*i] >= '0' && str[*i] <= '9')
				++*i;
		}
	}
	return (ft_true_struct_ii(info, str, i, ap));
}
