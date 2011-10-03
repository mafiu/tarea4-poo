/* 
 * File:   MyWorld.cpp
 * Author: pancho
 * 
 * Created on 16 August 2011, 23:13
 */

#include "MyWorld.h"

MyWorld::MyWorld() {
}

MyWorld::MyWorld(const MyWorld& orig) {
}

MyWorld::~MyWorld() {
}

void MyWorld::setGravity(float gravity){
    g = gravity;
}
void MyWorld::setDumping(float dumping){
    b = dumping;
}
//void MyWorld::setOutputFile(PrintStream out){
//}
void MyWorld::addElement(PhysicsElement e){
    elements.push_back(e);
}
void MyWorld::simulate(float delta_t, float samplingTime, float endTime){

}

void MyWorld::printSystemHeaders(){

}
void MyWorld::printSystemState(double t){

}
