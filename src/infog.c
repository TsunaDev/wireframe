/*
** EPITECH PROJECT, 2016
** wireframe
** File description:
** main display functions
*/

#include		"infog.h"

void			create_wframe_verticals(t_my_framebuffer *framebuffer,
						int **coordinates, int *size,
						sfColor color)
{
	sfVector3f	pose3d;
	sfVector2i	from;
	sfVector2i	to;
	float		angle = M_PI * 5.0f / 6.0f;

	for (int n = 0; n < size[0]; n++) {
		for (int x = 0; x < size[1] * n; x++) {
			pose3d = create_3dvector(coordinates[x], x, size[1]);
			from = my_parallel_projection(pose3d, angle);
			color = coloration(coordinates[x][2]);
			pose3d = create_3dvector(coordinates[x + size[1]],
						x + size[1], size[1]);
			to = my_parallel_projection(pose3d, angle);
			my_draw_line(framebuffer, from, to, color);
		}
	}
}

void			create_wireframe(t_my_framebuffer *framebuffer,
					int **coordinates, int *size,
					sfColor color)
{
	sfVector3f	pose3d;
	sfVector2i	from;
	sfVector2i	to;
	float		angle = M_PI * 5 / 6;
	sfVector3f	tmp;

	for (int x = 0; x < size[0] * size[1] - 1; x++) {
		pose3d = create_3dvector(coordinates[x], x, size[1]);
		tmp = pose3d;
		from = my_parallel_projection(pose3d, angle);
		color = coloration(coordinates[x][2]);
		pose3d = create_3dvector(coordinates[x + 1], x + 1, size[1]);
		to = my_parallel_projection(pose3d, angle);
		if (pose3d.x >= tmp.x)
			my_draw_line(framebuffer, from, to, color);
	}
	create_wframe_verticals(framebuffer, coordinates, size, color);
}

void			all_tasks(int **coordinates, int *size, sfColor color)
{
	sfRenderWindow		*window;
	sfTexture		*texture;
	sfSprite		*sprite;
	t_my_framebuffer	*framebuffer;

	window = window_open(SCREEN_WIDTH, SCREEN_HEIGHT);
	sprite = sfSprite_create();
	texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
	framebuffer = my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT);
	sfSprite_setTexture(sprite, texture, sfTrue);
	create_wireframe(framebuffer, coordinates, size, color);
	sfTexture_updateFromPixels(texture, framebuffer->pixels,
				SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
	window_loop(window, sprite);
	sfSprite_destroy(sprite);
	sfTexture_destroy(texture);
	free(framebuffer->pixels);
	sfRenderWindow_destroy(window);
}

int			main(int ac, char **av, char **env)
{
	int		**coordinates;
	int		*size;
	int		error_test;

	if (my_checkenv(env) == 84)
		return (84);
	if (ac == 2) {
		error_test = get_coordinates(av, &coordinates, &size);
		if (error_test == -1)
			return (84);
		coordinates[0][0] = 0;
		all_tasks(coordinates, size, sfRed);
		free(size);
	}
	return (0);
}
