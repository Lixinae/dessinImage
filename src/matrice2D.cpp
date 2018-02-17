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

Matrice2D Matrice2D::translation(int x, int y) {
	return Matrice2D(
		0, 0, x,
		0, 0, y,
		0, 0, 1
	);
}

Matrice2D Matrice2D::rotation(float theta) {
	float cos_theta = cos(theta);
	float sin_theta = sin(theta);
	return Matrice2D(
		cos_theta, -sin_theta, 0,
		sin_theta,  cos_theta, 0,
		    0    ,      0    , 1
	);
}

Matrice2D Matrice2D::homothetie(int k) {
	return Matrice2D(
		k, 0, 0,
		0, k, 0,
		0, 0, 1
	);
}

Matrice2D Matrice2D::operator* (const Matrice2D &other) {
	float m11 = _m11*other._m11 + _m12*other._m21 + _m13*other._m31;
	float m12 = _m11*other._m12 + _m12*other._m22 + _m13*other._m32;
	float m13 = _m11*other._m13 + _m12*other._m23 + _m13*other._m33;
	float m21 = _m21*other._m11 + _m22*other._m21 + _m23*other._m31;
	float m22 = _m21*other._m12 + _m22*other._m22 + _m23*other._m32;
	float m23 = _m21*other._m13 + _m22*other._m23 + _m23*other._m33;
	float m31 = _m31*other._m11 + _m32*other._m21 + _m33*other._m31;
	float m32 = _m31*other._m12 + _m32*other._m22 + _m33*other._m32;
	float m33 = _m31*other._m13 + _m32*other._m23 + _m33*other._m33;
	return Matrice2D(
		m11, m12, m13,
		m21, m22, m23,
		m31, m32, m33
	);
}

}
