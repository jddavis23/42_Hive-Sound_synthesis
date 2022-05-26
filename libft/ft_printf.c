/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:34:24 by jdavis            #+#    #+#             */
/*   Updated: 2022/04/01 10:38:38 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_c_or_s(t_flags *info, va_list *ap, char *c_zero)
{
	char	*c_pass;
	char	*str;

	c_pass = NULL;
	str = NULL;
	if (info->_type == 's')
		str = ft_solve_c_s(info, va_arg(*ap, char *));
	else
	{
		c_pass = ft_strnew(1);
		if (!c_pass)
			return (NULL);
		c_pass[0] = (char)va_arg(*ap, int);
		if (c_pass[0] == '\0' && (info->_minus || info->_width <= 1))
			info->_ret += write(1, &c_pass[0], 1);
		else if (c_pass[0] == '\0' && info->_width > 1)
			*c_zero = 'b';
		str = ft_solve_c_s(info, c_pass);
	}
	if (!str)
		return (NULL);
	return (str);
}

static int	ft_solve(va_list *ap, t_flags *info)
{
	char	*str;
	char	c_zero;

	str = NULL;
	c_zero = 'a';
	if (info->_type == 'c' || info->_type == 's' || info->_type == 'p')
		str = ft_choice_c_s_p(info, ap, &c_zero);
	else if (info->_type == 'u' || info->_type == 'x'
		|| info->_type == 'X' || info->_type == 'o')
		str = ft_choice_unsigned(info, ap);
	else if (info->_type == 'f' || info->_type == '%' || info->_type == 'd'
		|| info->_type == 'i')
		str = ft_choice_signed(info, ap);
	if (!str)
		return (-1);
	info->_ret += write(1, str, ft_strlen(str));
	if (c_zero == 'b')
	{
		c_zero = '\0';
		info->_ret += write(1, &c_zero, 1);
	}
	ft_strdel(&str);
	return (1);
}

static int	ft_prnt_type(t_flags *info, const char *format, va_list *ap, int *a)
{
	++(*a);
	info = ft_true_struct(info, format, a, ap);
	if (!info)
		return (-1);
	if (ft_solve(ap, info) == -1)
	{
		free(info);
		return (-1);
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		a;
	t_flags	*info;

	a = 0;
	info = ft_create_struct(NULL);
	if (!info)
		return (-1);
	va_start(ap, format);
	while (format[a] != '\0')
	{
		if (format[a] == '%')
		{
			if (ft_prnt_type(info, format, &ap, &a) == -1)
				return (-1);
		}
		else
		{
			info->_ret += write(1, &format[a], ft_strlen_stop(&format[a], '%'));
			a += ft_strlen_stop(&format[a], '%');
		}
	}
	va_end(ap);
	free(info);
	return (info->_ret);
}
