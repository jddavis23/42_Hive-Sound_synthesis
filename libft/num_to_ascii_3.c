/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_ascii_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 16:57:28 by jdavis            #+#    #+#             */
/*   Updated: 2022/04/04 13:11:02 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_temp_prec(t_flags *info, int *tp, char **str, char **temp)
{
	if (info->_dup_preci - 18 > 0)
		*tp = 18;
	else
		*tp = info->_dup_preci;
	*str = ft_strnew(*tp);
	if (!*str)
	{
		ft_strdel(temp);
		return (NULL);
	}
	return (*str);
}

static char	*ft_prcsion_round(long long unsigned int x,
	char **temp, t_flags *info, int option)
{
	int		i;
	char	*str;
	int		tp;

	i = 0;
	str = NULL;
	if (!ft_temp_prec(info, &tp, &str, temp))
		return (NULL);
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x /= 10;
	}
	while (i < tp)
		str[i++] = '0';
	ft_strrev(str, i);
	ft_strcat(*temp, str);
	ft_strdel(&str);
	if (option != 3)
		ft_rounder(temp, info, option);
	return (*temp);
}

static char	*ft_option_plus(long double nb, char **str, t_flags *info)
{
	int	option;

	option = 0;
	ft_option(nb, &option);
	if (info->_precision)
	{
		if (!ft_prcsion_round((long long unsigned int)nb, str, info, option))
			return (NULL);
	}
	else if (info->_p_true && !info->_precision)
		ft_rounder(str, info, option);
	return (*str);
}

static char	*ft_large_prec(t_flags *info, long double *nb, char **str)
{
	while (info->_dup_preci - 18 > 0 && info->_precision > 18)
	{
		*nb = (*nb - (long long unsigned int)*nb) * ft_power(10, 18);
		if (!ft_prcsion_round((long long unsigned int)*nb, str, info, 3))
			return (NULL);
		info->_dup_preci -= 18;
	}
	*nb = (*nb - (long long unsigned int)*nb) * ft_power(10, info->_dup_preci);
	return (*str);
}

char	*ft_ftoa(t_flags *info, long double nb)
{
	char		*str;
	char		*temp;

	info->_dup_preci = info->_precision;
	str = NULL;
	temp = ft_num_toa((long long unsigned int)nb, info, 10, ft_minus(nb));
	if (!temp)
		return (NULL);
	if (info->_p_true && !info->_precision && !info->_hash)
		return (ft_option_plus(nb, &temp, info));
	if (info->_hash && info->_p_true && !info->_precision)
		str = ft_strcat(ft_strcat(ft_strnew(ft_strlen(temp) + 1), temp), ".");
	else
	{
		str = ft_strnew(ft_strlen(temp) + info->_precision + 1);
		ft_strcat(ft_strcat(str, temp), ".");
	}
	ft_strdel(&temp);
	if (!str)
		return (NULL);
	if (nb < 0)
		nb *= -1;
	if (!ft_large_prec(info, &nb, &str))
		return (NULL);
	return (ft_option_plus(nb, &str, info));
}
