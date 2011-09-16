/* 
 * File:   main.cpp
 * Author: pancho
 *
 * Created on 27 June 2011, 22:23
 */

#include <cstdlib>
#include <iostream>
#include "Vector2D.h"
#include "Block.h"

using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    
    Vector2D A(2,3);
    Vector2D B(1,1);
    Block *b = new Block(1.2,A,B);
    Block *c = new Block(1.2,A,B);
    Spring *s = new Spring(0.2,1.0);

    double tiempo = 1.1;
    A += B;
    Vector2D C = A*tiempo;

    // al resorte agregarle a sus extremos dos bloques
    s->attachAEnd(b);
    //s->attachBEnd(c);

    
    
    Vector2D temp  = b->getNetForce(9.8);
    

    cout << "Fuerza X " << temp.X << "Fuerza Y " << temp.Y << endl;
    

    return 0;
}

