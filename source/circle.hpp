#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include <cmath>
#include "mat2.hpp"


class Circle
{
public:
	Circle();
	Circle(Vec2 const& mp, float r, Color const& c);
	float circumference() const;
	float area() const;
	void draw(Window const& win, Color const& c)const;
	void moire(Window const& win, Color const& c)const;
	bool is_inside(Vec2 const& p)const;

	//Getter
	Vec2 center() const;
	float radius() const;
	Color color() const;

	//Setter
	void center(Vec2 const& mp);
	void radius(float r);
	void color(Color const& c);

private:
	Vec2 m_center;
	float m_radius;	
	Color m_c;
};
#endif