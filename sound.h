/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:22:35 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/26 11:29:48 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOUND_H
#define SOUND_H

#include "libft/ft_printf.h"

typedef struct s_instru
{
	int tempo;
	int pitch;
	int flat_sharp;
	int	octa;
	float duration;
	struct s_instru *next;
}				t_instru;


#endif
