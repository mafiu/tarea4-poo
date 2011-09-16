/* 
 * File:   Spring.h
 * Author: pancho
 *
 * Created on 27 June 2011, 22:40
 */

#ifndef SPRING_H
#define	SPRING_H

class AttachableElement;
class Vector2D;

#include "PhysicsElement.h"
#include <cmath>
#include <iostream>


using namespace std;

class Spring : public PhysicsElement{
public:
    // constructores
    //Spring(const Spring& orig);
    Spring();
    Spring(float restLength, float stiffness);

    // metodos para (des)anclar
    void detachAEnd();
    void detachBEnd();
    void attachAEnd(AttachableElement* ae);
    void attachBEnd(AttachableElement* ae);

    // calculo de la fuerza
    Vector2D getForce(AttachableElement* ae);

    // displayers
    string getDescription();
    string getState();
    
    

private:
    static int id;
    float stiffness;
    double getLength();
protected:
    float restLength;

    // referencias a dos bloques 
    AttachableElement * a_end;
    AttachableElement * b_end;
    
};

#endif	/* SPRING_H */

