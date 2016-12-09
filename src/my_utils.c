/*
** my_utils.c for wireframe in /home/tsuna/Epitech/projects/Infograph/wireframe
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Tue Dec  6 21:47:22 2016 Martin Van Elslande
** Last update Fri Dec  9 09:57:59 2016 Martin Van Elslande
*/

#include                <SFML/Graphics/RenderWindow.h>

sfVector2i              vector_creator(int x, int y)
{
  sfVector2i            vector;

  vector.x = x;
  vector.y = y;
  return (vector);
}

sfVector3f              create_3dvector(int *coordinates, int nb)
{
  sfVector3f    pose3d;

  pose3d.x = 300 + ((nb) % 6) * 40;
  pose3d.y = (coordinates[1]) * 40;
  pose3d.z = 300 - (coordinates[2]) * 10;
  return (pose3d);
}
