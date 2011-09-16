/* 
 * File:   FixedHook.cpp
 * Author: pancho
 * 
 * Created on 27 June 2011, 22:40
 */

#include "FixedHook.h"

FixedHook::FixedHook() {
}

FixedHook::FixedHook(const FixedHook& orig) {
}

FixedHook::FixedHook(Vector2D& position){
    pos = position;
}
FixedHook::~FixedHook() {
}

void FixedHook::attachSpring(Spring* spring){
    springs.push_back(spring);
}
void FixedHook::detachSpring(Spring* spring){

}

Vector2D FixedHook::getPosition(){

}
string FixedHook::getState(){

}
string FixedHook::getDescription(){

}