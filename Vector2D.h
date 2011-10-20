/* 
 * File:   Vector2D.h
 * Author: pancho
 *
 * Created on 27 June 2011, 22:46
 */

#ifndef VECTOR2D_H
#define	VECTOR2D_H

#include <string>
using namespace std;

class Vector2D {
    
    
public:
    
    // Atributos
    double X, Y;

    // constructores y destructores
    Vector2D();
    Vector2D(double x, double y);

    // Overload operadores + - * /
    Vector2D operator+(const Vector2D & rhs);
    void operator+=(const Vector2D& rhs);
    Vector2D operator-(const Vector2D & rhs);
    void operator-=(const Vector2D& rhs);
    Vector2D operator*(const double rhs);
    Vector2D operator*(const Vector2D &rhs);

    double distancia(const Vector2D& vec1);
    Vector2D getDirection();
    // getters y setters
    double getX();
    double getY();
    void Set(double x, double y);

    // Display
    std::string getDescription();
    string printVector2D();
    void salidaVector2D();
};

// con el overloading de arriba se puede hacer Vector*escalar y con este
// se da la opcion escalar*vector

inline Vector2D operator *(double t, const Vector2D& v)
{
    return (Vector2D(t * v.X, t * v.Y));
}


#endif	/* VECTOR2D_H */

