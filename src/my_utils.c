/*
** my_utils.c for wireframe in /home/tsuna/Epitech/projects/Infograph/wireframe
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Tue Dec  6 21:47:22 2016 Martin Van Elslande
** Last update Sun Dec 11 20:32:07 2016 Martin Van Elslande
*/

#include		"infog.h"

sfColor			coloration(float z)
{
  sfColor		color;
  int			i;

  i = round(z);
  if (i > 25)
    i = 25;
  if (i > 0)
    {
      color.r = 255 - 10 * i;
      color.g = 0;
      color.b = 0 + 10 * i;
    }
  else
    {
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

sfVector3f              create_3dvector(int *coordinates, int nb, int size)
{
  sfVector3f    pose3d;

  pose3d.x = (SCREEN_WIDTH / 2) + (nb % size) * (40 / (float) size * 24);
  pose3d.y = (coordinates[1]) * (40 / (float) size * 24);
  pose3d.z = SCREEN_HEIGHT / 2 - (coordinates[2]) * 20 / (float) size * 24;
  return (pose3d);
}

int			my_checkenv(char **env)
{
  int			i;
  int			n;

  i = 0;
  n = 0;
  while (env[i] != NULL)
    {
      if (match(env[i], "DISPLAY*") == 1)
	n++;
      else if (match(env[i], "LIBRARY_PATH=*") == 1)
	n++;
      else if (match(env[i], "LD_LIBRARY_PATH=*") == 1)
	n++;
      else if (match(env[i], "CPATH=*") == 1)
	n++;
      i++;
    }
  if (n != 4)
    return (84);
  else
    return (0);
}
