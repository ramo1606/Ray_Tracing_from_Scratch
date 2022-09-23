#ifndef POINT3_H
#define POINT3_H

#include "matrix.h"
#include "vector3.h"

class Point3
{
public:
    Point3() = default;
    explicit Point3(const double a);
    explicit Point3(const double a, const double b, const double c);

    Point3 operator-(void) const;
    Vector3 operator-(const Point3& p) const;
    Point3 operator+(const Vector3& v) const;
    Point3 operator-(const Vector3& v) const;
    Point3 operator*(const double a) const;

    double d_squared(const Point3& p) const;
    double distance(const Point3& p) const;

public:
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

inline Point3 Point3::operator-(void) const
{
    return (Point3(-x, -y, -z));
}

inline Vector3 Point3::operator-(const Point3& p) const
{
    return (Vector3(x - p.x, y - p.y, z - p.z));
}

inline Point3 Point3::operator+(const Vector3& v) const
{
    return (Point3(x + v.x, y + v.y, z + v.z));
}

inline Point3 Point3::operator-(const Vector3& v) const
{
    return (Point3(x - v.x, y - v.y, z - v.z));
}

inline Point3 Point3::operator*(const double a) const
{
    return (Point3(x * a, y * a, z * a));
}

inline double Point3::d_squared(const Point3& p) const
{
    return ((x - p.x) * (x - p.x)
        + (y - p.y) * (y - p.y)
        + (z - p.z) * (z - p.z));
}

Point3 operator*(double a, const Point3& p);

inline Point3 operator*(double a, const Point3& p)
{
    return (Point3(a * p.x, a * p.y, a * p.z));
}

Point3 operator*(const Matrix& mat, const Point3& p);

#endif //POINT3_H