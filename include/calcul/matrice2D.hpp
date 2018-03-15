#ifndef MATRICE2D_H
#define MATRICE2D_H

namespace calcul {

class Matrice2D {

public:

	/**
	 * Renvoie une matrice de translation
	 * \param x : valeur en abscisse de la translation
	 * \param y : valeur en ordonnee de la translation
	 * \return une matrice de translation
	 */
	static Matrice2D translation(float x, float y);
	
	/**
	 * Renvoie une matrice de rotation centree sur l'origine
	 * \param theta : angle de rotation
	 * \return une matrice de rotation
	 */
	static Matrice2D rotation(float theta);
	
	/**
	 * Renvoie une matrice de rotation centree sur un point
	 * \param theta : angle de rotation
	 * \param x : valeur en abscisse du centre de rotation
	 * \param y : valeur en ordonnee du centre de rotation
	 * \return une matrice de rotation
	 */
	static Matrice2D rotation(float theta, float x, float y);
	
	/**
	 * Renvoie une matrice de rotation centree sur sur l'origine
	 * \param k : facteur de l'homothetie
	 * \return une matrice de homothetie
	 */
	static Matrice2D homothetie(float k);
	
	/**
	 * Renvoie une matrice de rotation centree sur un point
	 * \param k : facteur de l'homothetie
	 * \param x : valeur en abscisse du centre de l'homothetie
	 * \param y : valeur en ordonnee du centre de l'homothetie
	 * \return une matrice de homothetie
	 */
	static Matrice2D homothetie(float k, float x, float y);

	/**
	 * Renvoie le produit de matrice entre deux matrice de transformations
	 * \param a : premiere matrice
	 * \param b : deuxieme matrice
	 * \return le produit de matrice entre deux matrice de transformations
	 */
	friend Matrice2D operator* (const Matrice2D &a, const Matrice2D &b);
	
	/**
	 * Calcule le resultat de la transformation d'un point par rapport a une matrice,
	 * le resultat est stocker dans les references en argument
	 * \param x : valeur en abscisse du point
	 * \param y : valeur en ordonnee du point
	 */
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
