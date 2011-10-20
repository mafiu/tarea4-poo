/* 
 * File:   AttachableElement.h
 * Author: pancho
 *
 * Created on 27 July 2011, 20:47
 */

#ifndef ATTACHABLEELEMENT_H
#define	ATTACHABLEELEMENT_H


/*
 *  forward declare B if: one or more functions has a B object/pointer/reference
 *  as a parementer, or as a return type: B MyFunction(B myb);
 */
class Spring;
class Vector2D;

// Include Parent Class
#include "PhysicsElement.h"

class AttachableElement : public PhysicsElement {
public:
    AttachableElement();
    virtual void attachSpring(Spring* s){};
    virtual void detachSpring(Spring* s){};
    virtual Vector2D getPosition() = 0;
    

private:
protected:

};

#endif	/* ATTACHABLEELEMENT_H */

