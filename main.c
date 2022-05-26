/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:40:19 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/26 19:00:57 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sound.h"

int main(int argc, char *argv[]) 
{
	t_instru *tracks[50];
	ft_collect_strc(argc, argv, tracks);

	/*while (tracks[16])
	{
		ft_printf("%s\n", tracks[16]->waves);
		tracks[16] = tracks[16]->next;
	}*/
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
		//ft_printf("%s\n", tracks[0]->waves);
	while (tracks[0])
	{	
		if (ft_strstr(tracks[0]->waves, "sine"))
			wave_sine(audio_device, tracks[0]);
		if (ft_strstr(tracks[0]->waves, "square"))
    		wave_square(audio_device, tracks[16]);
		if (ft_strstr(tracks[0]->waves, "saw"))
    		wave_saw(audio_device, tracks[0]);
		if (ft_strstr(tracks[0]->waves, "triangle"))
    		wave_triangle(audio_device, tracks[0]);
		tracks[0] = tracks[0]->next;
	}


    //unpausing the audio device (starts playing):
    SDL_PauseAudioDevice(audio_device, 0);

    SDL_Delay(3000);

    SDL_CloseAudioDevice(audio_device);
    SDL_Quit();

    return 0;
}
