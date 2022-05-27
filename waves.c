/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acamaras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 19:51:50 by acamaras          #+#    #+#             */
/*   Updated: 2022/05/27 19:51:56 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sound.h"

void wave_sine(SDL_AudioDeviceID audio_device, t_instru *s)
{
    //printf("%f\n", ((float)FREQ * ((float)60 / (float)s->tempo) * s->duration));
    for (int i = 0; i < (float)FREQ * ((float)60 / (float)s->tempo) * s->duration; i++)
    {
        // SDL_QueueAudio expects a signed 16-bit value
        int16_t sample = sin((i / (float)FREQ) * 2.0f * M_PI * s->pitch * pow(2, s->octa)) * GAIN;
        const int sample_size = sizeof(int16_t) * 1;
        SDL_QueueAudio(audio_device, &sample, sample_size);
    }
}

void wave_square(SDL_AudioDeviceID audio_device, t_instru *s)
{
    float sine_value = 0.0f;

    for (int i = 0; i < (float)FREQ * ((float)60 / (float)s->tempo) * s->duration; i++)
    {
        sine_value = sin(((float)i / (float)FREQ) * 2.0f * M_PI * s->pitch * pow(2, s->octa)) * GAIN;
        sine_value += 1.0/3.0 * sin(((float)i*3 / (float)FREQ) * 2.0f * M_PI * s->pitch * pow(2, s->octa)) * GAIN;
        sine_value += 1.0/5.0 * sin(((float)i*5 / (float)FREQ) * 2.0f * M_PI * s->pitch * pow(2, s->octa)) * GAIN;
        sine_value += 1.0/7.0 * sin(((float)i*7 / (float)FREQ) * 2.0f * M_PI * s->pitch * pow(2, s->octa)) * GAIN;
        sine_value += 1.0/9.0 * sin(((float)i*9 / (float)FREQ) * 2.0f * M_PI * s->pitch * pow(2, s->octa)) * GAIN;
        sine_value += 1.0/11.0 * sin(((float)i*11 / (float)FREQ) * 2.0f * M_PI * s->pitch * pow(2, s->octa)) * GAIN;

        int16_t sample = sine_value;
        
        const int sample_size = sizeof(int16_t) * 1;
        SDL_QueueAudio(audio_device, &sample, sample_size);
    }
}

void wave_triangle(SDL_AudioDeviceID audio_device, t_instru *s)
{
    float sine_value = 0.0;
    for (int i = 0; i < (float)FREQ * ((float)60 / (float)s->tempo) * s->duration; i++)
    {
        sine_value = (sin(((float)i / (float)FREQ) * 2.0f * M_PI * s->pitch * pow(2, s->octa)) * GAIN) +  2;
		sine_value += pow(3, -2) * (-(sin(((float)i*3 / (float)FREQ) * 2.0f * M_PI * s->pitch * pow(2, s->octa)) * GAIN));
        sine_value += pow(5, -2) * (sin(((float)i*5 / (float)FREQ) * 2.0f * M_PI * s->pitch * pow(2, s->octa)) * GAIN) + pow(7, -2);
		int16_t sample = sine_value;

        const int sample_size = sizeof(int16_t) * 1;
        SDL_QueueAudio(audio_device, &sample, sample_size);
    }
}

void wave_saw(SDL_AudioDeviceID audio_device, t_instru *s)
{
    for (int i = 0; i < (float)FREQ * ((float)60 / (float)s->tempo) * s->duration; i++)
    {
        int16_t sample = (-((1.5f * GAIN)/ M_PI) * (tan(-(s->pitch *(pow(2, s->octa)) * (float)i / (float)FREQ))));

        const int sample_size = sizeof(int16_t) * 1;
        SDL_QueueAudio(audio_device, &sample, sample_size);
    }
}
