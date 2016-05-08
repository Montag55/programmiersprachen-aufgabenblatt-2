#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include <cmath>


class Rectangle
{
public:
	Rectangle();
	Rectangle(float h, float b, Color const& c, Vec2 const& pul);
	float circumference() const;
	float area() const;
	void draw(Window const& win, Color const& c)const;
	bool is_inside(Vec2 const& p) const;

	//Getter
	float hight() const;
	float breite() const;
	Color color() const;
	Vec2 startpunkt() const;


	//Setter
	void hight(float h);
	void breite(float b);
	void color(Color const& c);
	void startpunkt(Vec2 const& pul);
	

private:
	float m_h;
	float m_b;
	Color m_c;
	Vec2 m_pul;

};
#endif