/* 
 * File:   FixedHook.cpp
 * Author: pancho
 * 
 * Created on 27 June 2011, 22:40
 */

#include "FixedHook.h"

/* Clase que permite definir el comportamiento del gancho
 */

int FixedHook::id=0;

FixedHook::FixedHook() : AttachableElement(id++) {
}

FixedHook::FixedHook(Vector2D &position) : AttachableElement(id++) {
    pos = position;
    
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

