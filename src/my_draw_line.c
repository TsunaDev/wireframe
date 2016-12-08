/*
** my_draw_line.c for wireframe in /home/tsuna/Epitech/projects/Infograph/wireframe
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Mon Dec  5 23:08:28 2016 Martin Van Elslande
** Last update Wed Dec  7 22:54:45 2016 Martin Van Elslande
*/

#include        <SFML/Graphics/RenderWindow.h>
#include        <SFML/Graphics/Texture.h>
#include        <SFML/Graphics/Sprite.h>
#include	"infog.h"

void	my_draw_line_2(t_my_framebuffer *framebuffer, int *arr)
{
  int	stock;
  int	i;

  i = 1;
  stock = arr[3] / 2;
  while (i <= arr[3])
    {
      arr[1] += arr[5];
      stock += arr[2];
      if (stock >= arr[3])
	{
	  stock -= arr[3];
	  arr[0] += arr[4];
	}
      my_put_pixel(framebuffer, arr[0], arr[1], sfRed);
      i++;
    }
}

void	my_draw_line_1(t_my_framebuffer *framebuffer, int *arr)
{
  int	i;
  int	stock;

  i = 1;
  stock = arr[2] / 2;
  while (i <= arr[2])
    {
      arr[0] += arr[4];
      stock += arr[3];
      if (stock >= arr[2])
	{
	  stock -= arr[2];
	  arr[1] += arr[5];
	}
      my_put_pixel(framebuffer, arr[0], arr[1], sfRed);
      i++;
    }
}

void	my_draw_line(t_my_framebuffer *framebuffer, sfVector2i from,
		     sfVector2i to, sfColor color)
{
  int   stock;
  int   arr[6];
  int   i;

  arr[0] = from.x;
  arr[1] = from.y;
  arr[2] = to.x - from.x;
  arr[3] = to.y - from.y;
  arr[4] = (arr[2] > 0) ? 1 : (-1);
  arr[5] = (arr[3] > 0) ? 1 : (-1);
  if (arr[2] < 0)
    arr[2] *= (-1);
  if (arr[3] < 0)
    arr[3] *= (-1);
  my_put_pixel(framebuffer, arr[0], arr[1], sfRed);
  i = 1;
  if (arr[2] > arr[3])
    my_draw_line_1(framebuffer, arr);
  else
    my_draw_line_2(framebuffer, arr);
}
