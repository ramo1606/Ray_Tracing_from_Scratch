#ifndef TRACER_H
#define TRACER_H

#include "constants.h"
#include "ray.h"
#include "color.h"

class World;

class Tracer
{
public:

	Tracer(void) : world_ptr(nullptr) {}
	explicit Tracer(World* _world_ptr) : world_ptr(_world_ptr) {}

	virtual Tracer* clone(void) const = 0;

	virtual ~Tracer(void);

	virtual Color trace_ray(const Ray& ray) const;
	virtual Color trace_ray(const Ray& ray, const int depth) const;

protected:

	World* world_ptr;
};

#endif //TRACER_H