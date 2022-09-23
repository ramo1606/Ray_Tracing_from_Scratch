#include "ray.h"

void Ray::SetOrigin(const Point3& origin)
{
    o = origin;
}

void Ray::SetDirection(const Vector3& direction)
{
    d = direction;
}