/* 
 * File:   PhysicsElement.h
 * Author: pancho
 *
 * Created on 27 July 2011, 21:12
 */

#ifndef PHYSICSELEMENT_H
#define	PHYSICSELEMENT_H

#include <string>

using namespace std;

class PhysicsElement {
public:
    virtual void setInitialState(float g, float b);
    virtual void computeNextState(double delta_t, float gravity, float viscous);
    virtual void updateState();
    virtual string getDescription() = 0;
    virtual string getState() = 0;



private:
    int myId;
protected:
    PhysicsElement(int id);
    int getId();
};

#endif	/* PHYSICSELEMENT_H */

