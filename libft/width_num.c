/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:41:31 by jdavis            #+#    #+#             */
/*   Updated: 2022/04/05 11:24:04 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_true_zero(t_flags *info, char *temp, char *str,
	long long int nb)
{
	int	i;

	i = 0;
	ft_apply_hash(info, nb, &temp, &i);
	if (info->_plus && nb >= 0 && info->_type != '%' && ft_if_type(info) == 1)
		temp[i++] = '+';
	else if (nb < 0 && info->_type != '%' && ft_if_type(info) == 1)
		temp[i++] = '-';
	else if (info->_space && nb >= 0 && info->_type != '%' && ft_if_type(info)
		== 1)
		temp[i++] = ' ';
	while (i < info->_width - (int)ft_strlen(str))
		temp[i++] = '0';
	if (nb < 0)
	{
		temp[i++] = '0';
		ft_strcpy(&temp[i], &(str[1]));
	}
	else
		ft_strcpy(&temp[i], str);
	return (temp);
}

static void	ft_width_else(t_flags *info, char **temp, int nb, char *str)
{
	int		i;

	i = 0;
	if ((((info->_width - (int)ft_strlen(str) - info->_h_sub)) < 0)
		&& info->_hash && ft_if_type(info) == 2)
	{
		ft_strdel(temp);
		*temp = ft_strnew(ft_strlen(info->_h_prfx) + ft_strlen(str));
	}
	while (((i < (info->_width - (int)ft_strlen(str) - info->_h_sub)) || (nb
				== 0 && i < info->_width - (int)ft_strlen(str)))
		&& ft_if_type(info) == 2)
		(*temp)[i++] = ' ';
	if (info->_type == 'o' && info->_hash && info->_p_true && \
			!info->_precision && nb == 0)
		--i;
	ft_apply_hash(info, nb, temp, &i);
	while ((i < (info->_width - (int)ft_strlen(str) - 1)))
		(*temp)[i++] = ' ';
	if (info->_plus && nb >= 0 && info->_type != '%' && ft_if_type_i(info) == 1)
		(*temp)[i++] = '+';
	while (i < (info->_width - (int)ft_strlen(str)))
		(*temp)[i++] = ' ';
	ft_strcpy(&((*temp)[i]), str);
}

static char	*ft_true_minus(t_flags *info, char *temp,
	char *str, long long int nb)
{
	int	i;

	i = 0;
	ft_apply_hash(info, nb, &temp, &i);
	if (info->_plus && nb >= 0 && info->_type != '%'
		&& ft_if_type_i(info) == 1)
		temp[i++] = '+';
	ft_strcpy(&temp[i], str);
	i += ft_strlen(str);
	while (i < info->_width)
		temp[i++] = ' ';
	return (temp);
}

char	*ft_true_width(t_flags *info, char **str, long long int nb)
{
	char	*temp;
	int		i;

	temp = NULL;
	i = 0;
	temp = ft_strnew(info->_width);
	if (!temp)
	{
		ft_strdel(str);
		return (NULL);
	}
	if (info->_minus)
		temp = ft_true_minus(info, temp, *str, nb);
	else if (info->_zero && (!info->_p_true
			|| info->_type == '%' || info->_type == 'f'
			|| (info->_p_true && info->_precision < 0 && !info->_p_check)))
		temp = ft_true_zero(info, temp, *str, nb);
	else
		ft_width_else(info, &temp, nb, *str);
	return (temp);
}
