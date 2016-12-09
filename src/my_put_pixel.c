/*
** my_put_pixel.c for wireframe in /home/tsuna/Epitech/projects/Infograph/wireframe
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Mon Dec  5 23:04:57 2016 Martin Van Elslande
** Last update Fri Dec  9 18:18:53 2016 Martin Van Elslande
*/

#include		"infog.h"

void	my_put_pixel(t_my_framebuffer *framebuffer, int x, int y,
		     sfColor color)
{
  if (x >= 0 && y >= 0 && x < framebuffer->width && y < framebuffer->height)
    {
      framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
      framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
    }
}
