/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:40:19 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/27 19:47:16 by acamaras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sound.h"

int main(int argc, char *argv[]) 
{
	t_instru *tracks[50];
	ft_collect_strc(argc, argv, tracks);

    SDL_Init(SDL_INIT_AUDIO);

    // the representation of our audio device in SDL:
    SDL_AudioDeviceID audio_device;

    // opening an audio device:
    SDL_AudioSpec audio_spec;
    SDL_zero(audio_spec);
    audio_spec.freq = FREQ;
    audio_spec.format = AUDIO_S16SYS;
    audio_spec.channels = CHANNELS;
    audio_spec.samples = SAMPLE;
    audio_spec.callback = NULL;

    audio_device = SDL_OpenAudioDevice(
    NULL, 0, &audio_spec, NULL, 0);
    int i = 0;
	while (tracks[i])
	{	
		if (ft_strstr(tracks[i]->waves, "sine"))
			wave_sine(audio_device, tracks[i]);
		if (ft_strstr(tracks[i]->waves, "square"))
    		wave_square(audio_device, tracks[i]);
		if (ft_strstr(tracks[i]->waves, "saw"))
    		wave_saw(audio_device, tracks[i]);
		if (ft_strstr(tracks[i]->waves, "triangle"))
    		wave_triangle(audio_device, tracks[i]);
		tracks[i] = tracks[i]->next;
	}

    //unpausing the audio device (starts playing):
    SDL_PauseAudioDevice(audio_device, 0);
    SDL_Delay(60000);

    SDL_CloseAudioDevice(audio_device);
    SDL_Quit();

    return 0;
}
