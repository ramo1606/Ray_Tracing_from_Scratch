#ifndef SHADE_REC_H
#define SHADE_REC_H

#include "point3.h"
#include "normal.h"
#include "ray.h"
#include "color.h"

class Material;
class World;

class ShadeRec {
public:
    ShadeRec() = default;
    explicit ShadeRec(World* wr);

public:
    bool	      hit_an_object;
    Material* material_ptr = nullptr;		// Pointer to the nearest object's material
    Point3 		  hit_point;			          // World coordinates of intersection
    Point3	    local_hit_point;	        // World coordinates of hit point on generic object (used for texture transformations)
    Normal	    normal;				            // Normal at hit point
    Ray		      ray;
    int		      depth;				            // recursion depth
    double	    t;					              // ray parameter
    World* w = nullptr;
    Color       color;
};

#endif //SHADE_REC_H