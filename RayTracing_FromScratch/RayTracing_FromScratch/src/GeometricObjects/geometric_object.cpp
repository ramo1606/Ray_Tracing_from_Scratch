#include "geometric_object.h"
//#include "constants.h"

GeometricObject::GeometricObject(const GeometricObject& object)
{
}

GeometricObject& GeometricObject::operator=(const GeometricObject& rhs)
{
	if (this == &rhs) {
		return (*this);
	}

	return (*this);
}

GeometricObject::~GeometricObject(void)
{
}

Normal GeometricObject::get_normal(const Point3& p)
{
	return Normal();
}

float GeometricObject::pdf(const ShadeRec& sr)
{
	return 0.0f;
}