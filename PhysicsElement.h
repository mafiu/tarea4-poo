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
    PhysicsElement(){};
    PhysicsElement(const PhysicsElement& orig);
    void setInitialState(float g);
    void computeNextState(double delta_t, float gravity);
    void updateState();
    virtual string getDescription() = 0 ;
    virtual string getState() = 0 ;
    
private:

};

#endif	/* PHYSICSELEMENT_H */

