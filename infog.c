/*
** infog.c for wireframe in /home/tsuna/Epitech/projects/Infograph
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Wed Nov 23 13:55:01 2016 Martin Van Elslande
** Last update Fri Dec  9 20:31:52 2016 Martin Van Elslande
*/

#include		"infog.h"

void			create_wframe_verticals(t_my_framebuffer *framebuffer,
						int **coordinates, int *size,
						sfColor color)
{
  sfVector3f	pose3d;
  sfVector2i	from;
  sfVector2i	to;
  float		angle;
  int		n;
  int		x;

  n = 0;
  x = 0;
  angle = M_PI * 5 / 6;
  while (n < size[0])
    {
      while (x < size[1] * n)
	{
	  pose3d = create_3dvector(coordinates[x], x, size[1]);
	  from = my_parallel_projection(pose3d, angle);
	  pose3d = create_3dvector(coordinates[x + size[1]], x + size[1], size[1]);
	  to = my_parallel_projection(pose3d, angle);
	  my_draw_line(framebuffer, from, to, color);
	  x++;
	}
      n++;
    }
}

void			create_wireframe(t_my_framebuffer *framebuffer,
					 int **coordinates, int *size, sfColor color)
{
  sfVector3f	pose3d;
  sfVector2i	from;
  sfVector2i	to;
  float		angle;
  int		x;
  sfVector3f	tmp;

  x = 0;
  angle = M_PI * 5 / 6;
  while (x < size[0] * size[1] - 1)
    {
      pose3d = create_3dvector(coordinates[x], x, size[1]);
      tmp = pose3d;
      from = my_parallel_projection(pose3d, angle);
      pose3d = create_3dvector(coordinates[x + 1], x + 1, size[1]);
      to = my_parallel_projection(pose3d, angle);
      if (pose3d.x >= tmp.x)
	my_draw_line(framebuffer, from, to, color);
      x++;
    }
  create_wframe_verticals(framebuffer, coordinates, size, color);
}

void			all_tasks(int **coordinates, int *size, sfColor color)
{
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
  t_my_framebuffer	*framebuffer;
  
  window = window_open(SCREEN_WIDTH, SCREEN_HEIGHT);
  sprite = sfSprite_create();
  texture = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  framebuffer = my_framebuffer_create(SCREEN_WIDTH, SCREEN_HEIGHT);
  sfSprite_setTexture(sprite, texture, sfTrue);
  create_wireframe(framebuffer, coordinates, size, color);
  sfTexture_updateFromPixels(texture, framebuffer->pixels, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
  window_loop(window, sprite);
  sfSprite_destroy(sprite);
  sfTexture_destroy(texture);
  free(framebuffer->pixels);
  sfRenderWindow_destroy(window);
}

/* int			main(int ac, char **av, char **env) */
/* { */
/*   int			**coordinates; */
/*   int			*size; */

/*   get_coordinates(av, &coordinates, &size); */
/*   coordinates[0][0] = 0; */
/*   all_tasks(coordinates, size, sfRed); */
/*   return (0); */
/* } */
