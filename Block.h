/* 
 * File:   Block.h
 * Author: pancho
 *
 * Created on 27 July 2011, 19:19
 */
#ifndef BLOCK_H
#define	BLOCK_H

//class Spring; // lo mismo

#include <vector>
#include <iostream>
#include "AttachableElement.h" // incluir la clase padre
#include "Vector2D.h"
#include "Spring.h"

using namespace std;

class Block:public AttachableElement {
public:
    Block();
    Block(float mass, Vector2D& position, Vector2D& speed);
    void attachSpring(Spring* spring);
    void detachSpring(Spring* spring);
    int size();
    void setInitialState(float g);
    void updateState();
    void computeNextState(double delta_t,float gravity);
    string getDescription();
    string getState();

    Vector2D getNetForce(float g);
    Vector2D getPosition();


private:

    // atributos
    static int id;
    int myid;
    float mass;
    Vector2D pos;
    Vector2D pos_tPlusDelta;
    Vector2D speed_t;
    Vector2D speed_tPlusDelta;
    Vector2D accel_t;
    Vector2D accel_tMinusDelta;

    vector<Spring *> springs;
};

#endif	/* BLOCK_H */

