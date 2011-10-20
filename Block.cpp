/* 
 * File:   Block.cpp
 * Author: pancho
 * 
 * Created on 27 July 2011, 19:19
 */

#include "Block.h"
#include "Spring.h"

Block::Block(float m, Vector2D& position, Vector2D& speed) {
    this->mass = m;
    this->pos = position;
    this->speed_t = speed;

}

string Block::getDescription() {
    //  crear el string "Block #" + getId() + ": x,y";
    stringstream strDescription;
    strDescription << getId();
    return "Block_" + strDescription.str() + ":(x,y)";

}

string Block::getState() {
    return getPosition().printVector2D();
}

string Block::int2string(int n) {
    stringstream flujo;
    flujo << n;
    return (flujo.str());
}

/* Asociar a Resortes*/

void Block::attachSpring(Spring* s) {
    springs.push_back(s);
}

void Block::detachSpring(Spring* spring) {
    springs.pop_back();
}

/* Calcular Fuerzas y Estados */

Vector2D Block::getNetForce(float g, float roce) {

    Vector2D fuerza;
    Vector2D fuerzagravedad(0, -mass * g);
    Vector2D fuerzaroce(-roce * speed_t.getX(), -roce * speed_t.getY());

    // iterar obtener el resorte i del arreglo y calcular la fuerza asociada
    for (int i = 0; i < springs.size(); i++) {
        // sumar fuerza resortes a la fuerza total
        fuerza += springs[i]->getForce(this);
        //cout << fuerza.getX() << " " << fuerza.getY() << endl;
    }

    // fuerza = fuerzaresortes + roce + gravedad
    fuerza = fuerza + fuerzaroce + fuerzagravedad;
    cout << "Fuerza" << fuerza.printVector2D() << endl;
            
    return fuerza;
}

Vector2D Block::getPosition() {
    return pos;
}

void Block::setInitialState(float g, float b) {
    cout << "ALOOOOO" << accel_tMinusDelta.printVector2D() << endl;        
    accel_tMinusDelta = getNetForce(g, b) * (1 / mass);
    
}

void Block::computeNextState(double delta_t, float g, float b) {
    cout << "YEYY" << endl;
    accel_t = getNetForce(g, b) * (1 / mass);

    /* estas son las ecuaciones para calcular la velocidad y posicion en un 
     * delta posterior la fuente es el documento que pasó el profesor */

    speed_tPlusDelta = speed_t - (3.0 * accel_t - accel_tMinusDelta) * delta_t
            * (1 / 2);
    pos_tPlusDelta = pos + (speed_t * delta_t) + (4.0 * accel_t
            - accel_tMinusDelta) * delta_t * delta_t * (1 / 6);
}



void Block::updateState() {
    pos = pos_tPlusDelta;
    speed_t = speed_tPlusDelta;
    accel_tMinusDelta = accel_t;
}

