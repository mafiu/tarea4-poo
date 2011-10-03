/*
 * File:   MyWorld.h
 * Author: pancho
 *
 * Created on 16 August 2011, 23:13
 */

#ifndef MYWORLD_H
#define	MYWORLD_H

#include "Vector2D.h"
#include "Block.h"
#include "FixedHook.h"

using namespace std;

class MyWorld {
public:
    MyWorld();
    MyWorld(const MyWorld& orig);
    virtual ~MyWorld();

    void setGravity(float gravity);
    void setDumping(float dumping);
    //void setOutputFile(PrintStream out);
    void addElement(PhysicsElement e);
    void simulate(float delta_t, float samplingTime, float endTime);
    
private:
    void printSystemHeaders();
    void printSystemState(double t);

    float g,b;
    vector<PhysicsElement *> elements;
};

#endif	/* MYWORLD_H */

