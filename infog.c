/*
** infog.c for wireframe in /home/tsuna/Epitech/projects/Infograph
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Wed Nov 23 13:55:01 2016 Martin Van Elslande
** Last update Thu Dec  8 15:28:37 2016 Martin Van Elslande
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
  angle = 3.1415926535897932 * 5 / 6;
  while (n < size[1])
    {
      while (x < size[0] * n)
	{
	  pose3d = create_3dvector(coordinates[x], x);
	  from = my_parallel_projection(pose3d, angle);
	  pose3d = create_3dvector(coordinates[x + size[1]], x + size[1]);
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
  angle = 3.1415926535897932 * 5 / 6;
  while (x < size[0] * size[1] - 1)
    {
      pose3d = create_3dvector(coordinates[x], x);
      tmp = pose3d;
      from = my_parallel_projection(pose3d, angle);
      pose3d = create_3dvector(coordinates[x + 1], x + 1);
      to = my_parallel_projection(pose3d, angle);
      if (pose3d.x > tmp.x)
	my_draw_line(framebuffer, from, to, color);
      x++;
    }
  create_wframe_verticals(framebuffer, coordinates, size, color);
}

void	test_lines(t_my_framebuffer *framebuffer)
{
  sfVector2i	from;
  sfVector2i	to;

  from = vector_creator(10, 10);
  to = vector_creator(90, 90);
  my_draw_line(framebuffer, from, to, sfRed);
}

void			all_tasks(int **coordinates, int *size, sfColor color)
{
  sfRenderWindow	*window;
  sfTexture		*texture;
  sfSprite		*sprite;
  t_my_framebuffer	*framebuffer;
  
  window = window_open(640, 480);
  sprite = sfSprite_create();
  texture = sfTexture_create(640, 480);
  framebuffer = my_framebuffer_create(640, 480);
  sfSprite_setTexture(sprite, texture, sfTrue);
  
  test_lines(framebuffer); 
  //  create_wireframe(framebuffer, coordinates, size, color);
  sfTexture_updateFromPixels(texture, framebuffer->pixels, 640, 480, 0, 0);
  window_loop(window, sprite);
  sfSprite_destroy(sprite);
  sfTexture_destroy(texture);
  free(framebuffer->pixels);
  sfRenderWindow_destroy(window);
}

int			main(int ac, char **av, char **env)
{
  int			**coordinates;
  int			*size;

  get_coordinates(av, &coordinates, &size);
  coordinates[0][0] = 0;
  all_tasks(coordinates, size, sfRed);
  return (0);
}
