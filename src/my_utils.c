/*
** EPITECH PROJECT, 2016
** wireframe
** File description:
** util functions
*/

#include		"infog.h"

sfColor			coloration(float z)
{
	sfColor		color;
	int		i = round(z);

	if (i > 25)
		i = 25;
	if (i > 0) {
		color.r = 255 - 10 * i;
		color.g = 0;
		color.b = 0 + 10 * i;
	} else {
		color.r = 255 - 10 * i * (-1);
		color.g = 0 + 10 * i * (-1);
		color.b = 0;
	}
	if (i != 0)
		color.a = 255;
	else
		color.a = 120;
	return (color);
}

sfVector2i              vector_creator(int x, int y)
{
	sfVector2i            vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

sfVector3f              create_3dvector(int *coords, int nb, int size)
{
	sfVector3f    pose3d;

	pose3d.x = (SCREEN_WIDTH / 2) + (nb % size) * (40 / (float) size * 24);
	pose3d.y = (coords[1]) * (40 / (float) size * 24);
	pose3d.z = SCREEN_HEIGHT / 2 - (coords[2]) * 20 / (float) size * 24;
	return (pose3d);
}

int			my_checkenv(char **env)
{
	int			i = 0;

	i = 0;
	while (env && env[i]) {
		if (match(env[i], "DISPLAY*") == 1)
			return 0;
		i++;
	}
	return 84;
}
