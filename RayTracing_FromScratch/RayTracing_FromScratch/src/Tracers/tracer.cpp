#include "tracer.h"

Tracer::~Tracer(void)
{
	if (world_ptr)
	{
		world_ptr = nullptr;
	}
}

Color Tracer::trace_ray([[maybe_unused]] const Ray& ray) const
{
	return (Color::black);
}

Color Tracer::trace_ray([[maybe_unused]] const Ray& ray, [[maybe_unused]] const int depth) const
{
	return (Color::black);
}