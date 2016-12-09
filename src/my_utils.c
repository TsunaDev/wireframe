/*
** my_utils.c for wireframe in /home/tsuna/Epitech/projects/Infograph/wireframe
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Tue Dec  6 21:47:22 2016 Martin Van Elslande
** Last update Fri Dec  9 19:13:38 2016 Martin Van Elslande
*/

#include                <SFML/Graphics/RenderWindow.h>
#include		"infog.h"

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

  pose3d.x = (SCREEN_WIDTH / 2) + (nb % size) * 40;
  pose3d.y = (coordinates[1]) * 40;
  pose3d.z = SCREEN_HEIGHT / 2 - (coordinates[2]) * 10;
  return (pose3d);
}
