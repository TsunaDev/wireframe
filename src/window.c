/*
** window.c for wireframe in /home/tsuna/Epitech/projects/Infograph/wireframe
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Tue Dec  6 21:45:51 2016 Martin Van Elslande
** Last update Fri Dec  9 21:06:22 2016 Martin Van Elslande
*/

#include                "infog.h"

t_my_framebuffer        *my_framebuffer_create(int width, int height)
{
  int                   i;
  t_my_framebuffer      *framebuffer;

  if ((framebuffer = malloc(sizeof(t_my_framebuffer))) == NULL)
    return (NULL);
  framebuffer->width = width;
  framebuffer->height = height;
  if ((framebuffer->pixels = malloc
       (width * height * 4 * sizeof(framebuffer->pixels))) == NULL)
    return (NULL);
  while (i < width * height * 4)
    {
      framebuffer->pixels[i] = 0;
      i++;
    }
  return (framebuffer);
}

sfRenderWindow          *window_open(int width, int height)
{
  sfVideoMode           mode;
  sfRenderWindow*       window;

  mode.width = width;
  mode.height = height;
  mode.bitsPerPixel = 32;
  window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose, NULL);
  if (window == NULL)
    return (NULL);
  return (window);
}

void                    window_loop(sfRenderWindow *window, sfSprite *sprite)
{
  while (sfRenderWindow_isOpen(window))
    {
      sfRenderWindow_clear(window, sfBlack);
      sfRenderWindow_drawSprite(window, sprite, NULL);
      sfRenderWindow_display(window);
      if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
        sfRenderWindow_close(window);
    }
}
