/* 
 * File:   FixedHook.cpp
 * Author: pancho
 * 
 * Created on 27 June 2011, 22:40
 */

#include "FixedHook.h"

/* Clase que permite definir el comportamiento del gancho
 */
FixedHook::FixedHook() {
}

FixedHook::FixedHook(const FixedHook& orig) {
}

FixedHook::FixedHook(Vector2D& position) {
    pos = position;
}

FixedHook::~FixedHook() {
}

void FixedHook::attachSpring(Spring* spring) {
    springs.push_back(spring);
}

void FixedHook::detachSpring(Spring* spring) {

}

Vector2D FixedHook::getPosition() {
    return pos;
}

string FixedHook::getDescription() {
    stringstream getid;
    getid << getId();
    return "FixedHook_" + getid.str() + ": y";
}

string FixedHook::getState() {
    return getPosition().printVector2D();
}