#ifndef POINT_H
#define POINT_H

#include <iostream>

namespace figure {

using namespace std;

class Matrice2D {

public:

	Matrice2D translation(int x, int y);
	Matrice2D rotation(float theta);
	Matrice2D homothetie(int k);

	Matrice2D operator* (const Matrice2D &other);

private:

	float _m11, _m12, _m13;
	float _m21, _m22, _m23;
	float _m31, _m32, _m33;

	Matrice2D(
		float m11, float m12, float m13,
		float m21, float m22, float m23,
		float m31, float m32, float m33
	);

};

}

#endif
