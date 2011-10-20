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
#include <sstream>
#include "AttachableElement.h" // incluir la clase padre
#include "Vector2D.h"
#include "Spring.h"

using namespace std;

class Block : public AttachableElement {
public:
    Block();
    Block(float mass, Vector2D& position, Vector2D& speed);
    void attachSpring(Spring* spring);
    void detachSpring(Spring* spring);
    int size();
    void setInitialState(float g, float b);
    void updateState();
    void computeNextState(double delta_t, float gravity, float b);
    string getDescription();
    string getState();
    string int2string(int n);
    Vector2D getNetForce(float g, float roce);
    Vector2D getPosition();


private:

    // atributos
    int id;
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

