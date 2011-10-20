/* 
 * File:   Vector2D.cpp
 * Author: pancho
 * 
 * Created on 27 June 2011, 22:46
 */

#include <unistd.h>

#include "Vector2D.h"
#include "math.h"
#include "Spring.h"
#include <iostream>

Vector2D::Vector2D() {

}

Vector2D::Vector2D(double x, double y) {
    X = x;
    Y = y;
}

void Vector2D::Set(double x, double y) {
    this->X = x;
    this->Y = y;
}


// la version simple a + b

Vector2D Vector2D::operator +(const Vector2D& rhs) {

    Vector2D result;

    result.X = X + rhs.X; // 'X' is the same as 'this->X'.
    result.Y = Y + rhs.Y;
    return result;

}

// la version a += b

void Vector2D::operator+=(const Vector2D& right) {
    Set(X + right.X, Y + right.Y);
}

Vector2D Vector2D::operator -(const Vector2D& rhs) {

    Vector2D result;

    result.X = X - rhs.X; // 'X' is the same as 'this->X'.
    result.Y = Y - rhs.Y;
    return result;

}

void Vector2D::operator-=(const Vector2D& right) {
    Set(X - right.X, Y - right.Y);
}

// la version vector * escalar

Vector2D Vector2D::operator*(const Vector2D& left) {
    X *= left.X;
    Y *= left.Y;
    return *this; //asi no ocupo un Vector2D auxiliar
}

Vector2D Vector2D::operator *(const double rhs) {
    X *= rhs;
    Y *= rhs;
    return *this;
}

double Vector2D::distancia(const Vector2D& vec1) {
    double distancia_x = vec1.X - X;
    double distancia_y = vec1.Y - Y;
    return (double) sqrt((distancia_x * distancia_x)+(distancia_y * distancia_y));
};

Vector2D Vector2D::getDirection() {
    return *this*(1 / sqrt(X * X + Y * Y));
}

double Vector2D::getX() {
    return this->X;
}

double Vector2D::getY() {
    return this->Y;
}

string Vector2D::printVector2D() {
    string tostr;
    stringstream x, y; //trabaja con libreria sstream
    x << this->X;
    y << this->Y;
    tostr = x.str() + "," + y.str();

    return tostr;
}

void Vector2D::salidaVector2D() {
    cout << "(" << this->X << "," << this->Y << ")" << endl;
}