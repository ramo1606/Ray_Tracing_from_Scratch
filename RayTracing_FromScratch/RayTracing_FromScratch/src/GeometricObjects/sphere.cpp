#include "sphere.h"
//#include "constants.h"

#include <cmath>

const double Sphere::kEpsilon = 0.001;

Sphere* Sphere::clone(void) const
{
	return (new Sphere(*this));
}

Sphere& Sphere::operator=(const Sphere& rhs)
{
	if (this == &rhs)
	{
		return (*this);
	}

	GeometricObject::operator=(rhs);

	center = rhs.center;
	radius = rhs.radius;

	return (*this);
}

bool Sphere::hit(const Ray& ray, double& tmin, ShadeRec& sr) const
{
	Vector3 	temp = ray.Origin() - center;
	double 		a = ray.Direction() * ray.Direction();
	double 		b = 2.0 * temp * ray.Direction();
	double 		c = temp * temp - radius * radius;
	double 		disc = b * b - 4.0 * a * c;

	if (disc < 0.0) {
		return(false);
	}
	else {
		double t;
		double e = sqrt(disc);
		double denom = 2.0 * a;
		t = (-b - e) / denom;    // smaller root

		if (t > kEpsilon) {
			tmin = t;
			sr.normal = (temp + t * ray.Direction()) / radius;
			sr.local_hit_point = ray.Origin() + t * ray.Direction();
			return (true);
		}

		t = (-b + e) / denom;    // larger root

		if (t > kEpsilon) {
			tmin = t;
			sr.normal = (temp + t * ray.Direction()) / radius;
			sr.local_hit_point = ray.Origin() + t * ray.Direction();
			return (true);
		}
	}

	return (false);
}