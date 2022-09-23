#ifndef RAY_H
#define RAY_H

#include "point3.h"
#include "vector3.h"

class Ray {
public:
    Ray(void) = default;

    explicit Ray(const Point3& origin, const Vector3& dir) : o(origin), d(dir) {}

    Point3 Origin() const { return o; }
    Vector3 Direction() const { return d; }

    void SetOrigin(const Point3& origin);
    void SetDirection(const Vector3& direction);

private:
    Point3 o = Point3(0.0);
    Vector3 d = Vector3(0.0, 0.0, 1.0);
};

#endif //RAY_H