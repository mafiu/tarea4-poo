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

// TODO

string Block::getDescription() {
    return "Hola";
    //    return "Block #" + getId() + ": x,y";
}

string Block::getState() {
    return "Hola";
    //    return getPosition().getX() + "," + getPosition().getY() + "";
}

// ENDTODO

/* Asociar a Resortes*/

void Block::attachSpring(Spring* s) {
    springs.push_back(s);
}

void Block::detachSpring(Spring* spring) {

}

/* Calcular Fuerzas y Estados */

Vector2D Block::getNetForce(float g) {
    double roce = 1.0;
    Vector2D fuerza;
    Vector2D fuerzagravedad(0, -mass * g);


    Vector2D fuerzaroce(-roce * speed_t.getX(), -roce * speed_t.getY());

    // iterar obtener el resorte i del arreglo y calcular la fuerza asociada
    for (int i = 0; i < springs.size(); i++) {
        // sumar fuerza resortes a la fuerza total
        fuerza += springs.at(i)->getForce(this);
        //cout << fuerza.getX() << " " << fuerza.getY() << endl;
    }

    // fuerza = fuerzaresortes + roce + gravedad
    fuerza = fuerza + fuerzaroce + fuerzagravedad;

    return fuerza;
}

Vector2D Block::getPosition() {
    return pos;
}

void Block::setInitialState(float g) {
    accel_tMinusDelta = getNetForce(g)* (1 / mass);
}

void Block::computeNextState(double delta_t, float g) {
    accel_t = getNetForce(g)* (1 / mass);

    // speed_tPlusDelta = speed_t + (3*a_t - a_tMinusDelta)*delta_t/2;
    speed_tPlusDelta = speed_t - (3.0 * accel_t - accel_tMinusDelta) * delta_t * (1 / 2);

    // pos_tPlusDelta = pos_t   +  speed_t   *   delta_t    +   (a_t*4 - a_tMinusDelta)*delta_t*delta_t/6;
    pos_tPlusDelta = pos + (speed_t * delta_t) + (4.0 * accel_t - accel_tMinusDelta) * delta_t * delta_t * (1 / 6);
}

void Block::updateState() {
    pos = pos_tPlusDelta;
    speed_t = speed_tPlusDelta;
    accel_tMinusDelta = accel_t;

}

