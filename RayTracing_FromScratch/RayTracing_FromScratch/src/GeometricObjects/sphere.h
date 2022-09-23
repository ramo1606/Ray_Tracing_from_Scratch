#ifndef SPHERE_H
#define SPHERE_H

#include "geometric_object.h"


class Sphere : public GeometricObject
{
public:

	Sphere(void) : GeometricObject(), center(0.0), radius(1.0) {} 				                            // Default constructor
	Sphere(const Point3& c, double r) : GeometricObject(), center(c), radius(r) {}                         // Constructor 	
	Sphere(const Sphere& sphere) : GeometricObject(sphere), center(sphere.center), radius(sphere.radius) {} // Copy constructor

	virtual Sphere* clone(void) const override;			                                                    // Virtual copy constructor

	virtual	~Sphere(void) {} 								                                                // Destructor  									

	Sphere& operator= (const Sphere& sphere);   		                                                    // assignment operator				

	void set_center(const Point3& c);
	void set_center(const double x, const double y, const double z);
	void set_radius(const double r);
	virtual bool hit(const Ray& ray, double& t, ShadeRec& s) const override;
	//bool shadow_hit(const Ray &ray, float &tmin) const;

private:

	Point3   	center;   			// center coordinates as a point  
	double 		radius;				// the radius

	static const double kEpsilon;   // for shadows and secondary rays
};



inline void Sphere::set_center(const Point3& c)
{
	center = c;
}

inline void Sphere::set_center(const double x, const double y, const double z)
{
	center.x = x;
	center.y = y;
	center.z = z;
}

inline void Sphere::set_radius(const double r)
{
	radius = r;
}

#endif  //SPHERE_H