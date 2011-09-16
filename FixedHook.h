/* 
 * File:   FixedHook.h
 * Author: pancho
 *
 * Created on 27 June 2011, 22:40
 */

#ifndef FIXEDHOOK_H
#define	FIXEDHOOK_H

class Spring;

#include <string>
#include "Vector2D.h"

using namespace std;

class FixedHook {
public:
    FixedHook();
    FixedHook(const FixedHook& orig);
    FixedHook(Vector2D& position);
    virtual ~FixedHook();


    void attachSpring(Spring* spring);
    void detachSpring(Spring* spring);

    Vector2D getPosition();
    string getState();
    string getDescription();

private:
    Vector2D pos;
    static int id = 0;
    vector<Spring *> springs;

};

#endif	/* FIXEDHOOK_H */

