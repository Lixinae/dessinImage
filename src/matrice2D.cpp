#include "matrice2D.hpp"

#include <cmath>

namespace figure {

Matrice2D::Matrice2D(
	float m11, float m12, float m13,
	float m21, float m22, float m23,
	float m31, float m32, float m33
) : _m11(m11), _m12(m12), _m13(m13),
    _m21(m21), _m22(m22), _m23(m23),
    _m31(m31), _m32(m32), _m33(m33) {
		
}

Matrice2D Matrice2D::translation(float x, float y) {
	return Matrice2D(
		1, 0, x,
		0, 1, y,
		0, 0, 1
	);
}

Matrice2D Matrice2D::rotation(float theta, float x, float y) {
	float cos_theta = cos(theta);
	float sin_theta = sin(theta);
	return Matrice2D(
		cos_theta, -sin_theta, 0,
		sin_theta,  cos_theta, 0,
		    0    ,      0    , 1
	);
}

Matrice2D Matrice2D::homothetie(float k, float x, float y) {
	return Matrice2D(
		k, 0, 0,
		0, k, 0,
		0, 0, 1
	);
}

Matrice2D operator* (const Matrice2D &a, const Matrice2D &b) {
	float m11 = a._m11*b._m11 + a._m12*b._m21 + a._m13*b._m31;
	float m12 = a._m11*b._m12 + a._m12*b._m22 + a._m13*b._m32;
	float m13 = a._m11*b._m13 + a._m12*b._m23 + a._m13*b._m33;
	float m21 = a._m21*b._m11 + a._m22*b._m21 + a._m23*b._m31;
	float m22 = a._m21*b._m12 + a._m22*b._m22 + a._m23*b._m32;
	float m23 = a._m21*b._m13 + a._m22*b._m23 + a._m23*b._m33;
	float m31 = a._m31*b._m11 + a._m32*b._m21 + a._m33*b._m31;
	float m32 = a._m31*b._m12 + a._m32*b._m22 + a._m33*b._m32;
	float m33 = a._m31*b._m13 + a._m32*b._m23 + a._m33*b._m33;
	return Matrice2D(
		m11, m12, m13,
		m21, m22, m23,
		m31, m32, m33
	);
}

Point operator* (const Matrice2D &a, const Point &b) {
	float x = a._m11*b.getX() + a._m12*b.getY() + a._m13;
	float y = a._m21*b.getX() + a._m22*b.getY() + a._m23;
	return Point(x,y);
}

}
