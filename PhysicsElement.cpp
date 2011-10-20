/* 
 * File:   PhysicsElement.cpp
 * Author: pancho
 * 
 * Created on 27 July 2011, 21:12
 */

#include "PhysicsElement.h"

PhysicsElement::PhysicsElement() {
}

PhysicsElement::PhysicsElement(int id) {
    myId = id;
}

int PhysicsElement::getId() {
    return myId;
}

PhysicsElement::PhysicsElement(const PhysicsElement& orig) {
}

void PhysicsElement::setInitialState(float g, float b) {
}

void PhysicsElement::computeNextState(double delta_t, float gravity, float viscocity) {
}

void PhysicsElement::updateState() {
}

