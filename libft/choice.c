/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:28:12 by jdavis            #+#    #+#             */
/*   Updated: 2022/04/05 12:04:54 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_choice_unsigned(t_flags *info, va_list *ap)
{
	char	*str;

	str = NULL;
	if (info->_h)
		str = ft_llu_toa((unsigned short)va_arg(*ap, long long unsigned int),
				&info);
	else if (info->_hh)
		str = ft_llu_toa((unsigned char)va_arg(*ap, long long unsigned int),
				&info);
	else if (info->_l)
		str = ft_llu_toa((unsigned long)va_arg(*ap, long long unsigned int),
				&info);
	else if (info->_ll)
		str = ft_llu_toa(va_arg(*ap, long long unsigned int), &info);
	else
		str = ft_llu_toa((unsigned)va_arg(*ap, long long unsigned int), &info);
	if (str)
		return (ft_solve_signed(info, str, info->_gt));
	else
		return (NULL);
}

static char	*ft_int_choice(t_flags *info, va_list *ap)
{
	char	*str;

	str = NULL;
	if (info->_h)
		str = ft_num_toa((short int)va_arg(*ap, long long int), info, 10, 0);
	else if (info->_ll)
		str = ft_num_toa(va_arg(*ap, long long int), info, 10, 0);
	else if (info->_hh)
		str = ft_num_toa((char)va_arg(*ap, long long int), info, 10, 0);
	else if (info->_l)
		str = ft_num_toa((long)va_arg(*ap, long long int), info, 10, 0);
	else
		str = ft_num_toa((int)va_arg(*ap, long long int), info, 10, 0);
	return (str);
}

char	*ft_choice_signed(t_flags *info, va_list *ap)
{
	char	*str;

	str = NULL;
	if (info->_type != '%' && info->_type != 'f')
		str = ft_int_choice(info, ap);
	else if (info->_type == 'f')
	{
		if (info->_el)
			str = ft_ftoa(info, (long double)va_arg(*ap, long double));
		else
			str = ft_ftoa(info, va_arg(*ap, double));
	}
	else
		str = ft_num_toa(0, info, 0, 0);
	if (str)
		return (ft_solve_signed(info, str, info->_gt));
	else
		return (NULL);
}

char	*ft_choice_c_s_p(t_flags *info, va_list *ap, char *c_zero)
{
	char	*str;

	str = NULL;
	if (info->_type == 'c' || info->_type == 's')
		str = ft_c_or_s(info, ap, c_zero);
	else
		str = ft_solve_c_s(info, ft_solve_p(info, \
		(unsigned long long int)va_arg(*ap, uintptr_t)));
	if (!str)
		return (NULL);
	return (str);
}
