#include "single_sphere.h"
#include "world.h"
#include "shade_rec.h"

SingleSphere* SingleSphere::clone(void) const
{
	return (new SingleSphere(*this));
}


Color SingleSphere::trace_ray(const Ray& ray) const
{
	ShadeRec	sr(world_ptr); 	// not used
	double    	t;  			// not used

	if (world_ptr->sphere.hit(ray, t, sr))
	{
		return (Color::red);
	}
	else
	{
		return (Color::black);
	}
}