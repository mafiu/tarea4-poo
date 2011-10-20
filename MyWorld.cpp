/* 
 * File:   MyWorld.cpp
 * Author: pancho
 * 
 * Created on 16 August 2011, 23:13
 */

#define forx(_type,_iter,_coll) for (_type::iterator _iter = _coll.begin(); _iter != _coll.end(); _iter++)
#include "MyWorld.h"

MyWorld::MyWorld() {
    b = 0;
    g = 0;
}

MyWorld::MyWorld(const MyWorld& orig) {
}

MyWorld::~MyWorld() {
}

void MyWorld::setGravity(float gravity) {
    g = gravity;
    cout << "Gravity set with value " << g << endl;
}

void MyWorld::setDumping(float dumping) {
    b = dumping;
    cout << "Dumping set  with value " << b << endl;
}
//void MyWorld::setOutputFile(PrintStream out){
//}

void MyWorld::addElement(PhysicsElement * e) {
    elements.push_back(e);
}

void MyWorld::printSystemHeaders() {
    cout << "Time";
    for (int i = 0; i < elements.size(); i++) // print header
        cout << ",," << elements[i]->getDescription();
    cout << endl;
}

void MyWorld::printSystemState(double t) {
    cout << t;
    for (int i = 0; i < elements.size(); i++)
        cout << ",," << elements[i]->getState(); // print each element state
    cout << endl;
}

void MyWorld::simulate(float delta_t, float samplingTime, float endTime) {

    printSystemHeaders();

    for (int i = 0; i < elements.size(); i++) {
        elements[i]->setInitialState(g, b);
    }
    
    for (double t = 0, nextStateTime = 0; t < endTime; t += delta_t) {
        if (t >= nextStateTime) { // decide if it is time to print state
            printSystemState(t);
            nextStateTime += samplingTime;
        }
        for (int i = 0; i < elements.size(); i++) { // for each element
            elements[i]->computeNextState(delta_t, g, b); // compute next state

        }
        for (int i = 0; i < elements.size(); i++) // for all elements
            elements[i]->updateState(); // update its state
    }
}

