/* 
 * File:   FixedHook.h
 * Author: pancho
 *
 * Created on 27 June 2011, 22:40
 */

#ifndef FIXEDHOOK_H
#define	FIXEDHOOK_H

class Spring;

#include <vector>
#include <string>
#include <sstream>
#include "Vector2D.h"
#include "AttachableElement.h" // incluir la clase padre
#include "Spring.h"

using namespace std;

class FixedHook : public AttachableElement {
public:
    FixedHook(Vector2D& position);



    void attachSpring(Spring* spring);
    void detachSpring(Spring* spring);

    Vector2D getPosition();
    string getState();
    string getDescription();



private:
    FixedHook();
    Vector2D pos;
    static int id;
    vector<Spring *> springs;

};

#endif	/* FIXEDHOOK_H */

