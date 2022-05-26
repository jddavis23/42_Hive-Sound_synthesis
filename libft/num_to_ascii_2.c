/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_ascii_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:20:01 by jdavis            #+#    #+#             */
/*   Updated: 2022/03/28 16:59:17 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_struct_nb(t_flags **info, unsigned long long int nb)
{
	if (nb > 0)
		(*info)->_gt = 1;
	else if (nb < 0)
		(*info)->_gt = -1;
	else
		(*info)->_gt = 0;
}

static char	*ft_nb_zero(t_flags **info, char **str)
{
	*str = ft_strdup("0");
	if (!*str)
		return (NULL);
	(*info)->_p_check = ft_precision_nb((*info), str, (*info)->_gt);
	return (*str);
}

char	*ft_llu_toa(unsigned long long int nb, t_flags **info)
{
	int							count;
	char						*str;
	unsigned long long int		dup_nb;

	count = 0;
	str = NULL;
	ft_struct_nb(info, nb);
	if (nb == 0)
		return (ft_nb_zero(info, &str));
	dup_nb = nb;
	while (nb > 0)
	{
		nb /= (*info)->_div;
		count++;
	}
	str = ft_strnew(count);
	if (!str)
		return (NULL);
	while (dup_nb > 0)
	{
		str[--count] = ft_char_digit((dup_nb % (*info)->_div), (*info)->_type);
		dup_nb /= (*info)->_div;
	}
	(*info)->_p_check = ft_precision_nb((*info), &str, (*info)->_gt);
	return (str);
}
