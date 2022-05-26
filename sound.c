/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:28:13 by jdavis            #+#    #+#             */
/*   Updated: 2022/05/26 14:09:34 by jdavis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sound.h"
#include <fcntl.h>

int ft_notes(char c)
{
	if (c == 'a')
		return (1);
	if (c == 'b')
		return (2);
	if (c == 'c')
		return (3);
	if (c == 'd')
		return (4);
	if (c == 'e')
		return (5);
	if (c == 'f')
		return (6);
	if (c == 'g')
		return (7);
	if (c == 'r')
		return (8);
	return (-1);
}


int main(int argc, char *argv[])
{
	int fd;
	char *line;
	int	ret;
	t_instru *tracks[50];
	int j = 0;
	int i;
	t_instru *head = NULL;
	int	prev_oct;
	float prev_dur = 0;
	int f;

	if (argc == 1)
	{
		ft_printf("noo arguments dumbo\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd)
	{
		while ((ret = get_next_line(fd, &line)) == 1)
		{
			if (ft_strstr(line, "tempo"))
			{
				f = 0;
				while (line[f] < '0' || line[f] > '9')
					++f;
				f = ft_atoi(&line[f]);
			}
			if (line[0] >= '0' && line[0] <= '9')
			{
				tracks[j] = (t_instru *) malloc (sizeof(t_instru));
				if (!tracks[j])
				{
					ft_printf("tracks not true\n");
					return (-1);
				}
				tracks[j]->tempo = f;
				head = tracks[j];
				i = 0;
				prev_oct = 4;
				while (line[i] != '\0')
				{
					tracks[j]->tempo = f;
					while ((line[i] < 'a' ||  line[i] > 'g') && line[i] != 'r')
						++i;
					tracks[j]->pitch = ft_notes(line[i++]);
					if (line[i] == '#' || line[i] == 'b')
					{
						if (line[i] == '#')
							tracks[j]->flat_sharp = 1;
						else
							tracks[j]->flat_sharp = 2;
						++i;
					}
					else
						tracks[j]->flat_sharp = 0;
					if (line[i] >= '0' && line[i] <= '9')
					{
						tracks[j]->octa = ft_atoi(&line[i]);
						prev_oct = ft_atoi(&line[i]);
						++i;
					}
					else
						tracks[j]->octa = prev_oct;
					if (line[i] == '/')
					{
						++i;
						tracks[j]->duration = atof(&line[i]);
						prev_dur = atof(&line[i]);
					}
					else
						tracks[j]->duration = prev_dur;
					while ((line[i] >= '0' && line[i] <= '9') || line[i] == '.')
						++i;
					if (line[i] == '\0')
					{
						tracks[j]->next = NULL;
						break ;
					}
					tracks[j]->next = (t_instru *) malloc (sizeof(t_instru));
					if (!tracks[j]->next)
					{
						ft_printf("problem\n");
						return (0);
					}
					tracks[j] = tracks[j]->next;
					++i;
				}
				tracks[j] = NULL;
				tracks[j] = head;
				++j;
			}
		}
	}
	while (tracks[0])
	{
		ft_printf("pitch = %i    flats = %i    octa = %i     duration = %f\n", tracks[0]->pitch, tracks[0]->flat_sharp, tracks[0]->octa, tracks[0]->duration);
		tracks[0] = tracks[0]->next;
	}
	return (0);


}
