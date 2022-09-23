#include "vector3.h"
#include "normal.h"
#include "matrix.h"
#include "point3.h"

#include <math.h>

Vector3::Vector3(const Normal& n) : x(n.x), y(n.y), z(n.z)
{
}

// this is used in the ConcaveHemisphere hit functions
Vector3::Vector3(const Point3& p) : x(p.x), y(p.y), z(p.z)
{
}

Vector3& Vector3::operator=(const Normal& rhs)
{
	x = rhs.x; y = rhs.y; z = rhs.z;
	return (*this);
}

Vector3& Vector3::operator=(const Point3& rhs)
{
	x = rhs.x; y = rhs.y; z = rhs.z;
	return (*this);
}

void Vector3::normalize(void)
{
	double length = sqrt(x * x + y * y + z * z);
	x /= length; y /= length; z /= length;
}

Vector3& Vector3::hat(void)
{
	double length = sqrt(x * x + y * y + z * z);
	x /= length; y /= length; z /= length;
	return (*this);
}

double Vector3::length(void)
{
	return (sqrt(x * x + y * y + z * z));
}

Vector3 operator*(const Matrix& mat, const Vector3& v)
{
	return (Vector3(mat.m[0][0] * v.x + mat.m[0][1] * v.y + mat.m[0][2] * v.z,
		mat.m[1][0] * v.x + mat.m[1][1] * v.y + mat.m[1][2] * v.z,
		mat.m[2][0] * v.x + mat.m[2][1] * v.y + mat.m[2][2] * v.z));
}