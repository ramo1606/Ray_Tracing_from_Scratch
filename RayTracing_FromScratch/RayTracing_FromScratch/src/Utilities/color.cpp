#include "color.h"

#include <math.h> 

// used for color filtering in Chapter 28
Color Color::powc(float p) const
{
	return (Color(powf(r, p), powf(g, p), powf(b, p)));
}

const Color Color::black = Color(0.0f);
const Color Color::white = Color(1.0f);
const Color Color::red = Color(1.0f, 0.0f, 0.0f);
const Color Color::yellow = Color(1.0f, 1.0f, 0.0f);
const Color Color::brown = Color(0.71f, 0.4f, 0.16f);
const Color Color::darkGreen = Color(0.0f, 0.41f, 0.0f);
const Color Color::orange = Color(1.0f, 0.75, 0.0f);
const Color Color::green = Color(0.0f, 0.6f, 0.3f);
const Color Color::lightGreen = Color(0.65f, 1.0f, 0.3f);
const Color Color::darkYellow = Color(0.61f, 0.61f, 0.0f);
const Color Color::lightPurple = Color(0.65f, 0.3f, 1.0f);
const Color Color::darkPurple = Color(0.5f, 0.0f, 1.0f);
const Color Color::grey = Color(0.25f);