#include "rectangle.hpp"
#include "vec2.hpp"
#include <cmath>
#include "mat2.hpp"
#include "window.hpp"
#include "color.hpp"


Rectangle::Rectangle():
	m_h{3.0f},
	m_b{2.0f},
	m_c{1.0f, 1.0f, 1.0f},
	m_pul{Vec2()} {}

Rectangle::Rectangle(float h, float b, Color const& c, Vec2 const& pul):
	m_h{h},
	m_b{b},
	m_c{c},
	m_pul{pul} {}


//Getter
float Rectangle::hight() const{
	return m_h;
}
float Rectangle::breite() const{
	return m_b;
}
Color Rectangle::color() const{
	return m_c;
}
Vec2 Rectangle::startpunkt() const{
	return m_pul;
}

//Setter
void Rectangle::hight(float h){
	m_h = h;
}
void Rectangle::breite(float b){
	m_b = b;
}
void Rectangle::color(Color const& c){
	m_c = c;
}
void Rectangle::startpunkt(Vec2 const& pul){
	m_pul = pul;
}


//Rechteck Umfang
float Rectangle::circumference() const{
	return  2*(hight()+breite());
}

//Rechteckfläche
float Rectangle::area() const{
	return hight()*breite();
}

//Draw Rectangle
void Rectangle::draw(Window const& win, Color const& c)const{
	win.draw_line(startpunkt().x, startpunkt().y, startpunkt().x, startpunkt().y + hight(), c.m_r,c.m_g,c.m_b);
	win.draw_line(startpunkt().x, startpunkt().y, startpunkt().x + breite(), startpunkt().y, c.m_r,c.m_g,c.m_b);
	win.draw_line(startpunkt().x, startpunkt().y + hight(), startpunkt().x + breite(), startpunkt().y + hight(), c.m_r,c.m_g,c.m_b);
	win.draw_line(startpunkt().x + breite(), startpunkt().y, startpunkt().x + breite(), startpunkt().y + hight(), c.m_r,c.m_g,c.m_b);
}

//is_inside
bool Rectangle::is_inside(Vec2 const& p)const{
	if(startpunkt().x<=p.x && startpunkt().y<=p.y && startpunkt().x + breite()>=p.x && startpunkt().y+hight()>=p.y){
		return true;
	}
		return false;
	
}