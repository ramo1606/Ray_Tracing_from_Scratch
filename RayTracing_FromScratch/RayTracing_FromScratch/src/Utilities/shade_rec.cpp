#include "shade_rec.h"


ShadeRec::ShadeRec(World* wr)
	: hit_an_object(false),
	material_ptr(nullptr),
	hit_point(),
	local_hit_point(),
	normal(),
	ray(),
	depth(0),
	t(0.0),
	w(wr)
{
}