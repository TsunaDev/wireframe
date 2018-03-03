/*
** EPITECH PROJECT, 2016
** wireframe
** File description:
** get 2D parallel projection from 3D point
*/

#include		"infog.h"

sfVector2i              my_parallel_projection(sfVector3f pose3d, float angle)
{
	sfVector2i            vector;

	vector.x = round(pose3d.x + 1 * cos(angle) * pose3d.y);
	vector.y = round(pose3d.z + 1 * sin(angle) * pose3d.y);
	return (vector);
}

