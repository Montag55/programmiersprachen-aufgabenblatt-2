#include "mat2.hpp"
#include "vec2.hpp"
#include <cmath>
#include <iostream>

Mat2::Mat2():
	x1{1},
	x2{0}, 
	x3{0},
	x4{1} {}

Mat2::Mat2(float a, float b, float c, float d):
	x1{a},
	x2{b},
	x3{c},
	x4{d} {}

Mat2& Mat2::operator*=(Mat2 const& m){
	float a= x1 * m.x1 + x2 * m.x3;
	float b= x1 * m.x2 + x2 * m.x4;
	float c= x3 * m.x1 + x4 * m.x3;
	float d= x3 * m.x2 + x4 * m.x4;
	x1= a;
	x2= b;
	x3= c;
	x4= d;  
	return *this;
}

Mat2 operator*(Mat2 const& m1, Mat2 const& m2){
	return Mat2{(m1.x1 * m2.x1 + m1.x2 * m2.x3),
				(m1.x1 * m2.x2 + m1.x2 * m2.x4),
				(m1.x3 * m2.x1 + m1.x4 * m2.x3),
				(m1.x3 * m2.x2 + m1.x4 * m2.x4)};
}

Vec2 operator*(Mat2 const& m, Vec2 const& v){
	return Vec2{(m.x1*v.x + m.x2*v.y), (m.x3*v.x + m.x4*v.y)};
}

//Vec2 operator*(Vec2 const& m, Mat2 const& m)
// BULLSHITT!! HÖCHSTENS NOCHMAL MAT*VEC

Mat2 operator/(Mat2 const& m, float s){         //Nur wegen berechnung des Inversen"/"
	return Mat2(m.x1/s, m.x2/s, m.x3/s, m.x4/s);
}

float det(Mat2 const& m){
	return float(m.x1*m.x4-m.x3*m.x2);
}

Mat2 inverse(Mat2 const& m){
	return Mat2 (m.x4, -m.x2, -m.x3, m.x3)/(m.x1*m.x4-m.x2*m.x3);
}

Mat2 transpose(Mat2 const& m){
	return Mat2(m.x1, m.x3, m.x2, m.x4);
}

Mat2 make_rotation_mat2(float rot){
	float x1 = std::cos(rot);
	float x3 = std::sin(rot);

	return Mat2(x1, -x3, x3, x1);
}

float abst(Vec2 const& u, Vec2 const& v){
	Vec2 a = Vec2(v-u);
	return sqrt(a.x*a.x + a.y*a.y);
	//return sqrt(Vec2(u.x-v.x)*Vec2(u.x-v.x)+Vec2(u.y-v.y)*Vec2(u.y-v.y));
}



