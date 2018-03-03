/*
** EPITECH PROJECT, 2016
** wireframe
** File description:
** function to put a pixel on a framebuffer
*/

#include		"infog.h"

void	my_put_pixel(t_my_framebuffer *fb, int x, int y,
		sfColor color)
{
	if (x >= 0 && y >= 0 && x < fb->width && y < fb->height) {
		fb->pixels[(fb->width * y + x) * 4] = color.r;
		fb->pixels[(fb->width * y + x) * 4 + 1] = color.g;
		fb->pixels[(fb->width * y + x) * 4 + 2] = color.b;
		fb->pixels[(fb->width * y + x) * 4 + 3] = color.a;
	}
}
