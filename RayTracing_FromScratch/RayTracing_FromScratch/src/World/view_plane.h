#ifndef VIEW_PLANE_H
#define VIEW_PLANE_H

class Sampler;

class ViewPlane
{
public:
	ViewPlane() = default;

	// For the sake of simplicity I prevent copy and move
	ViewPlane(const ViewPlane& vp) = delete;
	ViewPlane(ViewPlane&& rhs) = delete;
	ViewPlane& operator= (const ViewPlane& rhs) = delete;
	ViewPlane& operator= (ViewPlane&& rhs) = delete;

	~ViewPlane();

	//void set_samples(const int n);
	//void set_sampler(Sampler* sp);
	void set_hres(const int h_res);
	void set_vres(const int v_res);
	void set_pixel_size(const float size);
	void set_gamma(const float g);
	void set_gamut_display(const bool show);
	void set_max_depth(int depth);

	int get_hres() const { return hres; }
	int get_vres() const { return vres; }
	float get_pixel_size() const { return s; }

private:
	// sampler_ptr is null on constructions and will be set when set_samples is called
	// todo: Fix this, reference: C.41: A constructor should create a fully initialized object.

	int 			hres = 400;   					    // horizontal image resolution 
	int 			vres = 400;   					    // vertical image resolution
	float			s = 1.0f;							// pixel size
	int				num_samples = 1;				    // number of samples per pixel
	float			gamma = 1.0f;						// gamma correction factor
	float			inv_gamma = 1.0f;					// the inverse of the gamma correction factor
	bool			show_out_of_gamut = false;			// display red if RGBColor out of gamut
	//Sampler			*sampler_ptr = nullptr;
	int				max_depth = 0;
};

inline void ViewPlane::set_hres(const int h_res)
{
	hres = h_res;
}

inline void ViewPlane::set_vres(const int v_res)
{
	vres = v_res;
}

inline void ViewPlane::set_pixel_size(const float size)
{
	s = size;
}

inline void ViewPlane::set_gamma(const float g)
{
	gamma = g;
	inv_gamma = 1.0f / gamma;
}

inline void ViewPlane::set_gamut_display(const bool show)
{
	show_out_of_gamut = show;
}

inline void ViewPlane::set_max_depth(int depth)
{
	max_depth = depth;
}

#endif //VIEW_PLANE_H