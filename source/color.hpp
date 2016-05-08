#ifndef COLOR_HPP
#define COLOR_HPP
#include <algorithm>


//deffinitionsberech
//min/max aus algorithm Lib.
inline float defb(float x){
	return std::min(1.0f,std::max(0.0f, x));
}

struct Color{
	Color():
	m_r{0.0f},
	m_g{0.0f},
	m_b{0.0f} {}

	Color(float a):
	m_r{defb(a)},
	m_g{defb(a)},
	m_b{defb(a)} {}

	Color(float r, float g, float b):
	m_r{defb(r)},
	m_g{defb(g)},
	m_b{defb(b)} {}

	float m_r;
	float m_g;
	float m_b;

};
#endif