#ifndef MATRICE2D_H
#define MATRICE2D_H

namespace transformation {

class Matrice2D {

public:

	static Matrice2D translation(float x, float y);
	
	static Matrice2D rotation(float theta);
	static Matrice2D rotation(float theta, float x, float y);
	
	static Matrice2D homothetie(float k);
	static Matrice2D homothetie(float k, float x, float y);

	friend Matrice2D operator* (const Matrice2D &a, const Matrice2D &b);
	
	void transformePoint(float &x, float &y) const;

private:

	float _m11, _m12, _m13;
	float _m21, _m22, _m23;
	float _m31, _m32, _m33;

	explicit Matrice2D(
		float m11, float m12, float m13,
		float m21, float m22, float m23,
		float m31, float m32, float m33
	);

};

}

#endif