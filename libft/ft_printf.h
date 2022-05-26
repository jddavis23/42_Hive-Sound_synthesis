/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:36:17 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/16 10:38:42 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_flags
{
	int		_space;
	int		_zero;
	int		_plus;
	int		_hash;
	int		_h_sub;
	char	_h_prfx[3];
	int		_minus;
	int		_div;
	char	_type;
	int		_width;
	int		_precision;
	int		_dup_preci;
	int		_p_true;
	int		_p_check;
	int		_hh;
	int		_h;
	int		_ll;
	int		_l;
	int		_el;
	int		_ret;
	int		_gt;
}				t_flags;

char	*ft_solve_c_s(t_flags *info, char *str);
int		ft_printf(const char *format, ...);
int		ft_precision_nb(t_flags *info, char **str, long long int nb);
char	ft_char_digit(unsigned int v, char c);
char	*ft_num_toa(long long int nb, t_flags *info, int choice, int minus);
void	ft_apply_hash(t_flags *info, unsigned int nb, char **temp, int *i);
char	*ft_solve_signed(t_flags *info, char *str, long long int nb);
char	*ft_solve_p(t_flags *info, uintptr_t addi);
char	*ft_c_or_s(t_flags *info, va_list *ap, char *c_zero);
t_flags	*ft_true_struct(t_flags *info, const char *str, int *i, va_list *ap);
t_flags	*ft_create_struct(t_flags *info);
int		ft_is_type(char c);
char	*ft_llu_toa(unsigned long long int nb, t_flags **info);
char	*ft_choice_unsigned(t_flags *info, va_list *ap);
char	*ft_choice_signed(t_flags *info, va_list *ap);
char	*ft_choice_f(t_flags *info, va_list *ap);
char	*ft_choice_c_s_p(t_flags *info, va_list *ap, char *c_zero);
void	ft_rounder(char **str, t_flags *info, int option);
char	*ft_ftoa(t_flags *info, long double nb);
int		ft_if_type(t_flags *info);
int		ft_if_type_i(t_flags *info);
char	*ft_true_width(t_flags *info, char **str, long long int nb);
int		ft_minus(long double nb);
void	ft_option(long double nb, int *option);
long long int ft_atolli(const char *str);
int		ft_numb_count(char *str);

#endif
