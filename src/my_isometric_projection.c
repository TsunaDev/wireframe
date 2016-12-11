/*
** my_isometric_projection.c for wireframe in /home/tsuna/Epitech/projects/Infograph/wireframe
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Thu Dec  8 18:09:50 2016 Martin Van Elslande
** Last update Sun Dec 11 20:38:06 2016 Martin Van Elslande
*/

#include	"infog.h"

sfVector2i	my_isometric_projection(sfVector3f pose3d)
{
  sfVector2i	vector;

  vector.x = pose3d.x * cos(M_PI * 5 / 6) +
    pose3d.y * cos((M_PI * 5 / 6) / M_PI / 6) +
    pose3d.z * cos((M_PI * 5 / 6) / M_PI / 6);
  vector.y = pose3d.x * sin(M_PI * 5 / 6) +
    pose3d.y * sin((M_PI * 5 / 6) / M_PI / 6) +
    pose3d.z * sin((M_PI * 5 / 6) / M_PI / 6);
  return (vector);
}
