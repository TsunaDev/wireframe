/*
** EPITECH PROJECT, 2016
** wireframe
** File description:
** get 2D isometric pos from 3D point
*/

#include	"infog.h"

#define rad(angleDegrees) (angleDegrees * M_PI / 180.0)

sfVector2i	my_isometric_projection(sfVector3f pose3d)
{
	sfVector2i	vector;

	vector.x = cos(rad(45)) * pose3d.x - cos(rad(45)) * pose3d.y;
	vector.y = sin(rad(35)) * pose3d.y + sin(rad(35)) * pose3d.x -
		pose3d.z;
	return vector;
}
