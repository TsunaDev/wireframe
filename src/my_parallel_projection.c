/*
** my_parallel_projection.c for wireframe in /home/tsuna/Epitech/projects/Infograph/wireframe
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Mon Dec  5 23:47:28 2016 Martin Van Elslande
** Last update Thu Dec  8 15:06:11 2016 Martin Van Elslande
*/

#include		"infog.h"

sfVector2i              my_parallel_projection(sfVector3f pose3d, float angle)
{
  sfVector2i            vector;

  vector.x = round(pose3d.x + 1 * cos(angle) * pose3d.y);
  vector.y = round(pose3d.z + 1 * sin(angle) * pose3d.y);
  return (vector);
}

