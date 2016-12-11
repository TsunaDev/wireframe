/*
** my_draw_line.c for wireframe in /home/tsuna/Epitech/projects/Infograph/wireframe
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Mon Dec  5 23:08:28 2016 Martin Van Elslande
** Last update Sun Dec 11 19:19:39 2016 Martin Van Elslande
*/

#include	"infog.h"

void	my_draw_line_2(t_my_framebuffer *framebuffer, int *arr, sfColor color)
{
  int	stock;
  int	i;

  i = 1;
  stock = arr[3] / 2;
  while (i <= arr[3])
    {
      arr[1] += arr[5];
      stock += arr[2];
      if (stock > arr[3])
	{
	  stock -= arr[3];
	  arr[0] += arr[4];
	}
      my_put_pixel(framebuffer, arr[0], arr[1], color);
      i++;
    }
}

void	my_draw_line_1(t_my_framebuffer *framebuffer, int *arr, sfColor color)
{
  int	i;
  int	stock;

  i = 1;
  stock = arr[2] / 2;
  while (i <= arr[2])
    {
      arr[0] += arr[4];
      stock += arr[3];
      if (stock > arr[2])
	{
	  stock -= arr[2];
	  arr[1] += arr[5];
	}
      my_put_pixel(framebuffer, arr[0], arr[1], color);
      i++;
    }
}

void	my_draw_line(t_my_framebuffer *framebuffer, sfVector2i from,
		     sfVector2i to, sfColor color)
{
  int   arr[6];

  if (from.x < framebuffer->width && from.y < framebuffer-> height &&
      to.x < framebuffer->width && to.y < framebuffer-> height)
    {
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
      my_put_pixel(framebuffer, arr[0], arr[1], color);
      if (arr[2] > arr[3])
	my_draw_line_1(framebuffer, arr, color);
      else
	my_draw_line_2(framebuffer, arr, color);
    }
}
