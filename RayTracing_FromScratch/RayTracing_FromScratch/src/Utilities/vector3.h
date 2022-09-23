#ifndef VECTOR3_H
#define VECTOR3_H

class Matrix;
class Normal;
class Point3;

class Vector3
{
public:
    // Constructors
    Vector3(void) = default;
    explicit Vector3(double a) : x(a), y(a), z(a) {};
    explicit Vector3(double a, double b, double c) : x(a), y(b), z(c) {};

    explicit Vector3(const Normal& n);
    explicit Vector3(const Point3& p);

    //Vector3 Operators
    Vector3& operator=(const Normal& rhs);
    Vector3& operator=(const Point3& rhs);

    Vector3 operator-(void) const;
    Vector3 operator*(const double a) const;
    Vector3 operator/(const double a) const;
    Vector3 operator+(const Vector3& v) const;
    Vector3 operator-(const Vector3& v) const;
    double operator*(const Vector3& v) const;
    Vector3 operator^(const Vector3& v) const;

    Vector3& operator+=(const Vector3& v);

    void normalize(void);
    Vector3& hat(void);

    double length(void);
    double len_squared(void);

public:
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};

inline Vector3 Vector3::operator-(void) const
{
    return (Vector3(-x, -y, -z));
}

inline Vector3 Vector3::operator*(const double a) const
{
    return (Vector3(x * a, y * a, z * a));
}

inline Vector3 Vector3::operator/(const double a) const
{
    return (Vector3(x / a, y / a, z / a));
}

inline Vector3 Vector3::operator+(const Vector3& v) const
{
    return (Vector3(x + v.x, y + v.y, z + v.z));
}

inline Vector3 Vector3::operator-(const Vector3& v) const
{
    return (Vector3(x - v.x, y - v.y, z - v.z));
}

inline double Vector3::operator*(const Vector3& v) const
{
    return (x * v.x + y * v.y + z * v.z);
}

inline Vector3 Vector3::operator^(const Vector3& v) const
{
    return (Vector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x));
}

inline Vector3& Vector3::operator+=(const Vector3& v)
{
    x += v.x; y += v.y; z += v.z;
    return (*this);
}

inline double Vector3::len_squared(void)
{
    return (x * x + y * y + z * z);
}

//Vector3 operator*(const double a, const Vector3& v);

inline Vector3 operator*(const double a, const Vector3& v)
{
    return (Vector3(a * v.x, a * v.y, a * v.z));
}

Vector3 operator*(const Matrix& mat, const Vector3& v);

#endif //VECTOR3_H