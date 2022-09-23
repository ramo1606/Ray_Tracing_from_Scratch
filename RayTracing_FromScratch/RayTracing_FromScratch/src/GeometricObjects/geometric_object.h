#ifndef GEOMETRIC_OBJECT_H
#define GEOMETRIC_OBJECT_H

#include "point3.h"
#include "ray.h"
#include "shade_rec.h"

class Material;
class Sampler;

class GeometricObject
{
public:
	GeometricObject(void) {}
	GeometricObject(const GeometricObject& object);
	virtual GeometricObject* clone(void) const = 0;
	virtual	~GeometricObject(void);

	virtual bool hit(const Ray& ray, double& t, ShadeRec& s) const = 0;

	void set_color(const Color& c);
	void set_color(const float r, const float g, const float b);
	Color get_color(void);

	virtual Normal get_normal(const Point3& p);

	virtual float pdf(const ShadeRec& sr);

protected:
	GeometricObject& operator= (const GeometricObject& rhs);

	Color color;
};

inline void GeometricObject::set_color(const Color& c)
{
	color = c;
}

inline void GeometricObject::set_color(const float r, const float g, const float b)
{
	color.r = r;
	color.b = b;
	color.g = g;
}

inline Color GeometricObject::get_color(void)
{
	return (color);
}

#endif //GEOMETRIC_OBJECT_H