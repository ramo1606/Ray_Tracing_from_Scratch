#ifndef SINGLE_SPHERE_H
#define SINGLE_SPHERE_H

#include "tracer.h"

class SingleSphere : public Tracer
{
public:

	SingleSphere(void) : Tracer() {}

	explicit SingleSphere(World* _worldPtr) : Tracer(_worldPtr) {}

	virtual SingleSphere* clone(void) const override;

	virtual ~SingleSphere(void) {}

	virtual Color trace_ray(const Ray& ray) const override;
};

#endif //SINGLE_SPHERE_H
