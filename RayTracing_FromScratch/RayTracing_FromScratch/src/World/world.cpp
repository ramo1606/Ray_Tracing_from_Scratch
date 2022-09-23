#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>

#include "world.h"

// geometric objects
#include "geometric_object.h"
#include "sphere.h"

// tracers
#include "single_sphere.h"

// utilities
#include "vector3.h"
#include "point3.h"
#include "normal.h"
#include "shade_rec.h"
#include "maths.h"

// TODO(fix): builder
//#include "build_function.cpp"


World::~World(void)
{

	if (tracer_ptr)
	{
		delete tracer_ptr;
		tracer_ptr = nullptr;
	}

	delete_objects();
}


Color World::max_to_one(const Color& c) const
{
	float max_value = max(c.r, max(c.g, c.b));

	if (max_value > 1.0)
	{
		return (c / max_value);
	}
	else
	{
		return (c);
	}
}


// Set color to red if any component is greater than one

Color World::clamp_to_color(const Color& raw_color) const
{
	Color c(raw_color);

	if (raw_color.r > 1.0 || raw_color.g > 1.0 || raw_color.b > 1.0)
	{
		c.r = 1.0; c.g = 0.0; c.b = 0.0;
	}

	return (c);
}


// raw_color is the pixel color computed by the ray tracer
// its RGB floating point components can be arbitrarily large
// mapped_color has all components in the range [0, 1], but still floating point
// display color has integer components for computer display
// the Mac's components are in the range [0, 65535]
// a PC's components will probably be in the range [0, 255]
// the system-dependent code is in the function convert_to_display_color
// the function SetCPixel is a Mac OS function


void World::display_pixel([[maybe_unused]] const int row, [[maybe_unused]] const int column, const Color& raw_color) const
{
	Color mapped_color;

	mapped_color = max_to_one(raw_color);

	pixels.push_back((int)(mapped_color.r * 255));
	pixels.push_back((int)(mapped_color.g * 255));
	pixels.push_back((int)(mapped_color.b * 255));
}


ShadeRec World::hit_objects(const Ray& ray)
{

	ShadeRec	sr(this);
	double		t;
	Normal      normal;
	Point3      local_hit_point;
	double		tmin = static_cast<double>(kHugeValue);
	size_t 		num_objects = objects.size();

	for (size_t j = 0; j < num_objects; j++)
	{
		if (objects[j]->hit(ray, t, sr) && (t < tmin))
		{
			sr.hit_an_object = true;
			tmin = t;
			//sr.material_ptr     = objects[j]->get_material();
			sr.hit_point = ray.Origin() + t * ray.Direction();
			normal = sr.normal;
			local_hit_point = sr.local_hit_point;
		}
	}

	if (sr.hit_an_object)
	{
		sr.t = tmin;
		sr.normal = normal;
		sr.local_hit_point = local_hit_point;
	}

	return(sr);
}

ShadeRec World::hit_bare_bones_objects(const Ray& ray)
{
	ShadeRec	sr(this);
	double		t;
	double		tmin = kHugeValue;
	size_t 		num_objects = objects.size();

	for (size_t j = 0; j < num_objects; j++)
	{
		if (objects[j]->hit(ray, t, sr) && (t < tmin))
		{
			sr.hit_an_object = true;
			tmin = t;
			sr.color = objects[j]->get_color();
		}
	}

	return(sr);
}

void World::save_to_ppm(void) const
{
	std::time_t t = std::time(nullptr);
	std::tm tm;
	localtime_s(&tm, &t);
	std::stringstream imageFile;
	imageFile << "./image_" << std::put_time(&tm, "%Y%m%e%H%M%S") << ".ppm";

	std::ofstream ofs;
	ofs.open(imageFile.str().c_str(), std::ios::out | std::ios::binary);
	ofs << "P6\n" << vp.get_hres() << " " << vp.get_vres() << "\n255\n";
	for (int i : pixels)
	{
		ofs << static_cast<unsigned char>(i);
	}
	ofs.close();
}

// This builds a scene that consists of 35 shaded spheres and a plane.
// The objects are illuminated by a directional light and rendered with
// ambient and diffuse shading.
// Perspective viewing is used with a pinhole camera.
// Jittered sampling for antialiasing is hardwired into the PinHole::render_scene function.
// There are no sampler classes in this project.
// These are in the Chapter 5 download file.
// The spheres are the same as those in the Chapter 14 page one image.

//void World::build(void) 
//{
//	int num_samples = 1;
//
//	// view plane
//
//	vp.set_hres(200);
//	vp.set_vres(200);
//	vp.set_pixel_size(1.0);
//
//	background_color = Color::black;
//	tracer_ptr = new SingleSphere(this);
//
//	sphere.set_center(Point3(0.0));
//	sphere.set_radius(85.0);
//
//	// spheres
//	Sphere *sphere_ptr1 = new Sphere(Point3(0.0), 85.0);
//	add_object(sphere_ptr1);
//}

void World::build(void)
{
	vp.set_hres(200);
	vp.set_vres(200);
	vp.set_pixel_size(1.0);

	background_color = Color::black;
	tracer_ptr = new SingleSphere(this);

	sphere.set_center(Point3(0.0));
	sphere.set_radius(85.0);
}

// This uses orthographic viewing along the zw axis

void World::render_scene(void) const
{

	Color	    pixel_color;
	Ray			ray;
	int 		hres = vp.get_hres();
	int 		vres = vp.get_vres();
	float		s = vp.get_pixel_size();
	float		zw = 100.0;				// hardwired in

	ray.SetDirection(Vector3(0, 0, -1));

	for (int r = 0; r < vres; r++)			// up
	{
		for (int c = 0; c < hres; c++)
		{	// across
			ray.SetOrigin(Point3(s * (c - hres / 2.0 + 0.5), s * (r - vres / 2.0 + 0.5), zw));
			pixel_color = tracer_ptr->trace_ray(ray);
			display_pixel(r, c, pixel_color);
		}
	}
}

// Deletes the objects in the objects array, and erases the array.
// The objects array still exists, because it's an automatic variable, but it's empty
void World::delete_objects(void)
{
	size_t num_objects = objects.size();

	for (size_t j = 0; j < num_objects; j++)
	{
		delete objects[j];
		objects[j] = NULL;
	}

	objects.erase(objects.begin(), objects.end());
}