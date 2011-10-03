/* 
 * File:   Spring.cpp
 * Author: pancho
 * 
 * Created on 27 June 2011, 22:40
 */

#include <vector>

#include "Spring.h"
#include "AttachableElement.h"
#include "Vector2D.h"

using namespace std;

Spring::Spring(float restLength, float stiffness) {
    this->restLength = restLength;
    this->stiffness = stiffness;
    a_end = b_end = NULL;
}

void Spring::attachAEnd(AttachableElement* ae) {
    a_end = ae;
    ae->attachSpring(this);
}

void Spring::attachBEnd(AttachableElement* ae) {
    b_end = ae;
    ae->attachSpring(this);
}

void Spring::detachAEnd() {
    if (a_end == NULL) return;
    a_end->attachSpring(this);
    a_end = NULL;
}

void Spring::detachBEnd() {
    if (b_end == NULL) return;
    b_end->attachSpring(this);
    b_end = NULL;
}

double Spring::getLength() {
    if (a_end == NULL || b_end == NULL) return restLength;
    else {
        // distancia entre posiciones de a_end y b_end
        double length = a_end->getPosition().distancia(b_end->getPosition());
        return length;
    }
}

Vector2D Spring::getForce(AttachableElement* ae) {

    Vector2D fuerza;
    double factor, largo, stretch = 0;

    // si uno de los lados esta vacio retorna un Vector2D vacio
    if (a_end == NULL || b_end == NULL) return Vector2D(0, 0);
    if ((ae != a_end) && (ae != b_end)) return Vector2D(0, 0);

    // calculo de la fuerza
    largo = getLength();
    stretch = abs(largo) - restLength;
    factor = stretch * stiffness;

    // Fuerza del resorte hay que calcular el vector direccion de esta
    fuerza = (a_end->getPosition() - b_end->getPosition()).getDirection();

    if (largo < 0) factor *= (-1);
    if (ae == b_end) return fuerza * factor;
    return fuerza * factor * (-1);

}

string Spring::int2string(int n) {
    stringstream flujo;
    flujo << n;
    return (flujo.str());
}

string Spring::getDescription() {
    string msg;
    msg.append("Spring #").append(int2string(this->id)).append(": x,y");
    return msg;
}

string Spring::getState() {
    string s;
    if (a_end != NULL) {


    } else if (b_end != NULL) {

    } else {

    }

    if (b_end != NULL) {


    } else if (b_end != NULL) {


    } else {

    }


}

