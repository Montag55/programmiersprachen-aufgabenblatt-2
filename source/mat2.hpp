#ifndef MAT2_HPP
#define MAT2_HPP
#include "vec2.hpp"


class Mat2{

public:
	Mat2 ();
	Mat2 (float x1, float x2, float x3, float x4);
	Mat2& operator*=(Mat2 const& m);
	float x1, x2, x3, x4;
	float det() const;
};



Mat2 operator* (Mat2 const& m1, Mat2 const& m2);
Vec2 operator* (Mat2 const& m, Vec2 const& v);
Vec2 operator* (Vec2 const& v, Mat2 const& m); // BULLSHIT! GEHT KEIN VEC*MAT 
Mat2 operator/(Mat2 const& m, float s); //nur eingefügt für die Berechnung des Inversen
Mat2 inverse(Mat2 const& m);
Mat2 transpose(Mat2 const& m);
Mat2 make_rotation_mat2(float rot);
float abst(Vec2 const& u, Vec2 const& v); //nur eingefügt zur ermitttleung is_inside circle



#endif