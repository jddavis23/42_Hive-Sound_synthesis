/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:22:35 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/26 17:38:46 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOUND_H
#define SOUND_H

#include "libft/ft_printf.h"
#include <stdio.h>
# include <SDL.h>
# include <math.h>
# define SAMPLE 1024
# define FREQ 44100
# define CHANNELS 2
# define GAIN 5000

typedef struct s_instru
{
	int tempo;
	double pitch;
	int flat_sharp;
	int	octa;
	float duration;
	char waves[9];
	struct s_instru *next;
}				t_instru;


void wave_sine(SDL_AudioDeviceID audio_device, t_instru *s);
void wave_square(SDL_AudioDeviceID audio_device, t_instru *s);
void wave_triangle(SDL_AudioDeviceID audio_device, t_instru *s);
void wave_saw(SDL_AudioDeviceID audio_device, t_instru *s);
void ft_collect_strc(int argc, char *argv[], t_instru *tracks[]);
double ft_notes(char c);
int main(int argc, char *argv[]);


#endif
