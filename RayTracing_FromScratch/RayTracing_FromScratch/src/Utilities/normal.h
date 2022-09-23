#ifndef NORMAL_H
#define NORMAL_H

#include "vector3.h"

class Matrix;
class Point3;


class Normal
{
public:
	Normal(void) = default;
	explicit Normal(double a) : x(a), y(a), z(a) {}
	explicit Normal(double a, double b, double c) : x(a), y(b), z(c) {}
	explicit Normal(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}

	Normal& operator=(const Vector3& rhs);
	Normal& operator=(const Point3& rhs);

	Normal operator-(void) const;
	Normal operator+(const Normal& n) const;
	Normal& operator+=(const Normal& n);
	double operator*(const Vector3& v) const;
	Normal operator*(const double a) const;

	void normalize(void);

public:
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
};

inline Normal Normal::operator-(void) const
{
	return (Normal(-x, -y, -z));
}

inline Normal Normal::operator+(const Normal& n) const
{
	return (Normal(x + n.x, y + n.y, z + n.z));
}

inline Normal& Normal::operator+=(const Normal& n)
{
	x += n.x; y += n.y; z += n.z;
	return (*this);
}

inline double Normal::operator*(const Vector3& v) const
{
	return (x * v.x + y * v.y + z * v.z);
}

inline Normal Normal::operator*(const double a) const
{
	return (Normal(x * a, y * a, z * a));
}

//Normal operator* (const double a, const Normal& n);
inline Normal operator*(const double f, const Normal& n)
{
	return (Normal(f * n.x, f * n.y, f * n.z));
}

//Vector3 operator+(const Vector3& v, const Normal& n);
inline Vector3 operator+(const Vector3& v, const Normal& n)
{
	return (Vector3(v.x + n.x, v.y + n.y, v.z + n.z));
}

//Vector3 operator-(const Vector3&, const Normal& n);
inline Vector3 operator-(const Vector3& v, const Normal& n)
{
	return (Vector3(v.x - n.x, v.y - n.y, v.z - n.z));
}

//double operator*(const Vector3& v, const Normal& n);
inline double operator*(const Vector3& v, const Normal& n)
{
	return (v.x * n.x + v.y * n.y + v.z * n.z);
}

Normal operator*(const Matrix& mat, const Normal& n);

#endif //NORMAL_H