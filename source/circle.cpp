#include "circle.hpp"
#include "vec2.hpp"
#include <cmath>
#include "mat2.hpp"
#include "window.hpp"
#include "color.hpp"


Circle::Circle():
	m_center{Vec2()},
	m_radius{3.0f}, 
	m_c{1.0f, 1.0f, 1.0f} {}


Circle::Circle(Vec2 const& mp, float r, Color const& c):
	m_center{mp},
	m_radius{r},
	m_c{c} {}


//Getter
Vec2 Circle::center() const {
	return m_center;
}
float Circle::radius() const {
	return m_radius;
}
Color Circle::color() const {
	return m_c; 
}


//Setter
void Circle::center(Vec2 const& mp){
	m_center = mp;
}
void Circle::radius(float r){
	m_radius = r;
}
void Circle::color(Color const& c){
	m_c = c;
}


//Kreisumfang
float Circle::circumference() const{
	float r= radius();
	return(2*M_PI*r);
}

//Kreisfläche
float Circle::area() const{
	float r= radius();
	return(M_PI*r*r);
}

//Draw Circle
// void Circle::draw(Window const& win)const{
// 	draw(win, colo());
// }

void Circle::draw(Window const& win, Color const& c)const{
	
	Vec2 begin = make_rotation_mat2(0)*Vec2(radius(),0)+center();
	Vec2 end;
	for (int i = 0; i <= 360 ; ++i)
	{
		
		//Vec2 begin = make_rotation_mat2((2*M_PI)*(i/360))*Vec2(radius(),0)+center();
		//Vec2 end = make_rotation_mat2((2*M_PI)*(i+1)/360)*Vec2(radius(),0)+center();
		//win.draw_line(begin.x, begin.y, end.x, end.y, c.m_r, c.m_g, c.m_b);
		end = make_rotation_mat2((2*M_PI)*(i+1)/360)*Vec2(radius(),0)+center();
		win.draw_line(begin.x, begin.y, end.x, end.y, c.m_r, c.m_g, c.m_b);
		begin.x = end.x;
		begin.y = end.y;
	}
}

void Circle::moire(Window const& win, Color const& c)const{
	
	for (int i = 0; i <= 360 ; ++i)
	{
		
		Vec2 begin = make_rotation_mat2((2*M_PI)*(i/360))*Vec2(radius(),0)+center();
		Vec2 end = make_rotation_mat2((2*M_PI)*(i+1)/360)*Vec2(radius(),0)+center();
		win.draw_line(begin.x, begin.y, end.x, end.y, c.m_r, c.m_g, c.m_b);
	}
}

//is_inside
bool Circle::is_inside(Vec2 const& p)const{
	if (abst(center(), p)<=radius()){
		return true;
	}
	return false;
}