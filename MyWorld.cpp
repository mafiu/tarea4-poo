/* 
 * File:   MyWorld.cpp
 * Author: pancho
 * 
 * Created on 16 August 2011, 23:13
 */

#define forx(_type,_iter,_coll) for (_type::iterator _iter = _coll.begin(); _iter != _coll.end(); _iter++)
#include "MyWorld.h"

MyWorld::MyWorld() {
}

MyWorld::MyWorld(const MyWorld& orig) {
}

MyWorld::~MyWorld() {
}

void MyWorld::setGravity(float gravity) {
    g = gravity;
}

void MyWorld::setDumping(float dumping) {
    b = dumping;
}
//void MyWorld::setOutputFile(PrintStream out){
//}

void MyWorld::addElement(PhysicsElement * e) {
    elements.push_back(e);
}

void MyWorld::simulate(float delta_t, float samplingTime, float endTime) {

    // initialize elements

    //forx(vector<PhysicsElement *>,e,elements) {
    //    e->setInitialState(g);
    //}


    for (double t = 0, nextStateTime = 0; t < endTime; t += delta_t) {
        if (t >= nextStateTime) { // decide if it is time to print state
            printSystemState();
            nextStateTime += samplingTime;
        }
        // foreach elements calculate nextstate then update

    }


}

void MyWorld::printSystemHeaders() {

}

void MyWorld::printSystemState(double t) {

}
