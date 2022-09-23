#ifndef COLOR_H
#define COLOR_H

class Color {

public:
	Color(void) = default;
	explicit Color(float a) : r(a), g(a), b(a) {}
	explicit Color(float a, float b, float c) : r(a), g(b), b(c) {}

	Color operator+(const Color& c) const;
	Color& operator+=(const Color& c);
	Color operator*(const float a) const;
	Color& operator*=(const float a);
	Color operator/(const float a) const;
	Color& operator/=(const float a);
	Color operator*(const Color& c) const;
	bool operator==(const Color& c) const;

	Color powc(float p) const;
	float average(void) const;

public:
	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;

	/*static*/ static const Color black;
	/*static*/ static const Color white;
	/*static*/ static const Color red;
	/*static*/ static const Color yellow;
	/*static*/ static const Color brown;
	/*static*/ static const Color darkGreen;
	/*static*/ static const Color orange;
	/*static*/ static const Color green;
	/*static*/ static const Color lightGreen;
	/*static*/ static const Color darkYellow;
	/*static*/ static const Color lightPurple;
	/*static*/ static const Color darkPurple;
	/*static*/ static const Color grey;
};

inline Color Color::operator+(const Color& c) const
{
	return (Color(r + c.r, g + c.g, b + c.b));
}

inline Color& Color::operator+=(const Color& c)
{
	r += c.r; g += c.g; b += c.b;
	return (*this);
}

inline Color Color::operator*(const float a) const
{
	return (Color(r * a, g * a, b * a));
}

inline Color& Color::operator*=(const float a)
{
	r *= a; g *= a; b *= a;
	return (*this);
}

inline Color Color::operator/(const float a) const
{
	return (Color(r / a, g / a, b / a));
}

inline Color& Color::operator/=(const float a)
{
	r /= a; g /= a; b /= a;
	return (*this);
}

inline Color Color::operator*(const Color& c) const
{
	return (Color(r * c.r, g * c.g, b * c.b));
}

inline bool Color::operator==(const Color& c) const
{
	return (r == c.r && g == c.g && b == c.b);
}

inline float Color::average(void) const
{
	return (0.333333333333f * (r + g + b));
}

//Color operator* (const float a, const Color& c);
inline Color operator* (const float a, const Color& c)
{
	return (Color(a * c.r, a * c.g, a * c.b));
}


#endif //COLOR_H
