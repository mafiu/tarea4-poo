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

    virtual void attachSpring(Spring* s) = 0;
    virtual void detachSpring(Spring* s) = 0;
    virtual Vector2D getPosition() = 0;


private:
protected:
    AttachableElement(int id);
    
};

#endif	/* ATTACHABLEELEMENT_H */

