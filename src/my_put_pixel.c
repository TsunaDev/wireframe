/*
** my_put_pixel.c for wireframe in /home/tsuna/Epitech/projects/Infograph/wireframe
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Mon Dec  5 23:04:57 2016 Martin Van Elslande
** Last update Thu Dec  8 14:02:24 2016 Martin Van Elslande
*/

#include                <SFML/Graphics/RenderWindow.h>
#include                <SFML/Graphics/Texture.h>
#include                <SFML/Graphics/Sprite.h>
#include		"infog.h"

void	my_put_pixel(t_my_framebuffer *framebuffer, int x, int y,
		     sfColor color)
{
  if (x >= 0 && y >= 0)
    {
      framebuffer->pixels[(640 * y + x) * 4] = color.r;
      framebuffer->pixels[(640 * y + x) * 4 + 1] = color.g;
      framebuffer->pixels[(640 * y + x) * 4 + 2] = color.b;
      framebuffer->pixels[(640 * y + x) * 4 + 3] = color.a;
    }
}
