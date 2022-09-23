#include "normal.h"
#include "matrix.h"
#include "point3.h"

#include <math.h>

Normal& Normal::operator=(const Vector3& rhs)
{
	x = rhs.x; y = rhs.y; z = rhs.z;
	return (*this);
}

Normal& Normal::operator=(const Point3& rhs)
{
	x = rhs.x; y = rhs.y; z = rhs.z;
	return (*this);
}

void Normal::normalize(void)
{
	double length = sqrt(x * x + y * y + z * z);
	x /= length; y /= length; z /= length;
}

Normal operator*(const Matrix& mat, const Normal& n)
{
	return (Normal(mat.m[0][0] * n.x + mat.m[1][0] * n.y + mat.m[2][0] * n.z,
		mat.m[0][1] * n.x + mat.m[1][1] * n.y + mat.m[2][1] * n.z,
		mat.m[0][2] * n.x + mat.m[1][2] * n.y + mat.m[2][2] * n.z));
}