#ifndef WORLD_H
#define WORLD_H

// The World class does not have a copy constructor or an assignment operator, for the followign reasons:

// 1 	There's no need to copy construct or assign the World
// 2 	We wouldn't want to do this anyway, because the world can contain an arbitray amount of data
// 3 	These operations wouldn't work because the world is self-referencing:
//	 	the Tracer base class contains a pointer to the world. If we wrote a correct copy constructor for the
// 	  	Tracer class, the World copy construtor would call itself recursively until we ran out of memory.

#include "view_plane.h"
#include "color.h"
#include "tracer.h"
#include "geometric_object.h"
#include "sphere.h"
#include "ray.h"
#include "single_sphere.h"


#include <vector>

using namespace std;

class World {
public:
	World(void) = default;

	// For the sake of simplicity I prevent copy and move
	World(const World& w) = delete;
	World(World&& w) = delete;
	World& operator= (const World& rhs) = delete;
	World& operator= (World&& rhs) = delete;

	~World();

	void add_object(GeometricObject* object_ptr);

	//void add_light(Light* light_ptr);
	//void set_ambient_light(Light* light_ptr);
	//void set_camera(Camera* c_ptr);
	Color max_to_one(const Color& c) const;
	Color clamp_to_color(const Color& c) const;

	void display_pixel(const int row, const int column, const Color& pixel_color) const;
	ShadeRec hit_objects(const Ray& ray);
	ShadeRec hit_bare_bones_objects(const Ray& ray);

	void save_to_ppm(void) const;
	void build(void);
	void render_scene(void) const;

public:
	// tracer_ptr is set to NULL because the build functions will always construct the appropriate tracer
	// ambient_ptr is set to a default ambient light because this will do for most scenes
	// camera_ptr is set to NULL because the build functions will always have to construct a camera
	// and set its parameters
	// todo: Fix this, reference: C.41: A constructor should create a fully initialized object.

	ViewPlane					vp = ViewPlane();
	Color					    background_color = Color::black;
	Tracer* tracer_ptr = nullptr;
	Sphere 						sphere;		// for Chapter 3 only
	//Light*   					ambient_ptr = nullptr;
	//Camera*					camera_ptr = nullptr;
	vector<GeometricObject*>	objects;
	//vector<Light*> 				lights;

private:
	mutable std::vector<int> pixels;

	void delete_objects(void);
	//void delete_lights(void);
};



inline void World::add_object(GeometricObject* object_ptr)
{
	objects.emplace_back(object_ptr);
}

#endif //WORLD_H