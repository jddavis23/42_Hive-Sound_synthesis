/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:36:00 by jdavis            #+#    #+#             */
/*   Updated: 2022/04/01 12:10:54 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_no_width_signed(t_flags *info, char **str, long long int nb)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	temp = ft_strnew(ft_strlen(*str) + 1);
	if (!temp)
	{
		ft_strdel(str);
		return (NULL);
	}
	if (info->_plus && nb >= 0)
		temp[i++] = '+';
	else if (info->_space && nb >= 0)
		temp[i++] = ' ';
	ft_strcpy(&temp[i], *str);
	ft_strdel(str);
	*str = temp;
	return (*str);
}

static char	*ft_no_width_unsigned(t_flags *info, char **str)
{
	char	*temp;
	int		i;

	temp = NULL;
	i = 0;
	temp = ft_strnew(ft_strlen(*str) + info->_h_sub);
	if (!temp)
	{
		ft_strdel(str);
		return (NULL);
	}
	ft_strcpy(&temp[i], info->_h_prfx);
	i += ft_strlen(info->_h_prfx);
	ft_strcpy(&temp[i], *str);
	ft_strdel(str);
	*str = temp;
	return (*str);
}

char	*ft_solve_signed(t_flags *info, char *str, long long int nb)
{
	int		i;
	char	*temp;

	i = 0;
	if ((info->_width > (int)ft_strlen(str)))
	{
		temp = ft_true_width(info, &str, nb);
		ft_strdel(&str);
		str = temp;
	}
	else if (ft_if_type(info) == 1)
	{
		if (info->_type != '%' && (info->_plus || info->_space))
			str = ft_no_width_signed(info, &str, nb);
	}
	else if (info->_type == 'X' || info->_type == 'x' || info->_type == 'o')
	{
		if (info->_hash && ((info->_gt > 0 && info->_type != 'o')
				|| (info->_type == 'o' && str[0] != '0')))
			str = ft_no_width_unsigned(info, &str);
	}
	return (str);
}
