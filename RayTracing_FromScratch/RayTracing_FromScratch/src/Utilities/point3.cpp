#include "point3.h"

#include <math.h>

Point3::Point3(const double a) : x(a), y(a), z(a)
{
}

Point3::Point3(const double a, const double b, const double c) : x(a), y(b), z(c)
{
}

double Point3::distance(const Point3& p) const
{
	return (sqrt((x - p.x) * (x - p.x)
		+ (y - p.y) * (y - p.y)
		+ (z - p.z) * (z - p.z)));
}

Point3 operator*(const Matrix& mat, const Point3& p)
{
	return (Point3(mat.m[0][0] * p.x + mat.m[0][1] * p.y + mat.m[0][2] * p.z + mat.m[0][3],
		mat.m[1][0] * p.x + mat.m[1][1] * p.y + mat.m[1][2] * p.z + mat.m[1][3],
		mat.m[2][0] * p.x + mat.m[2][1] * p.y + mat.m[2][2] * p.z + mat.m[2][3]));
}