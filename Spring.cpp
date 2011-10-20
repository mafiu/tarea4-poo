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
    id=0;
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

    cout << "Entre" << endl;
    // si uno de los lados esta vacio retorna un Vector2D vacio
    if (a_end == NULL || b_end == NULL) {
        cout << "Crap 1" << endl;
        return Vector2D(0, 0);
    }
    if ((ae != a_end) && (ae != b_end)) {
        cout << "Crap 2" << endl;
        return Vector2D(0, 0);
    }

    // calculo de la fuerza
    largo = getLength();
    stretch = abs(largo) - restLength;
    factor = stretch * stiffness;

    // Fuerza del resorte hay que calcular el vector direccion de esta
    fuerza = (a_end->getPosition() - b_end->getPosition()).getDirection();

    cout << "Vector" << fuerza.printVector2D() << endl;

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
    stringstream id;
    id << getId();
    return "Spring#" + id.str() + ":(x0,y0),(x1,y1)";
}

// TODO: Metodos toString del Vector son un cacho

string Spring::getState() {
    string s;
    if (a_end != NULL)
        s = a_end->getPosition().printVector2D() + ",";
    else if (b_end != NULL) {
        stringstream x, y;
        x << (b_end->getPosition().getX() - restLength);
        y << (b_end->getPosition().getY() - restLength);
        s = x.str() + "," + y.str() + ",";

    } else
        s = "0.0"; // up to here left end is determined 
    if (b_end != NULL)
        s += b_end->getPosition().printVector2D();
    else if (a_end != NULL) {
        stringstream x, y;
        x << (a_end->getPosition().getX() + restLength);
        y << (a_end->getPosition().getY() + restLength);
        s += x.str() + "," + y.str();
    } else {
        stringstream strLength;
        strLength << restLength;
        s += strLength.str();
    }
    return s;

}

