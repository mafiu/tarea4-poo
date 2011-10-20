/* 
 * File:   main.cpp
 * Author: pancho
 *
 * Created on 27 June 2011, 22:23
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include "MyWorld.h"
#include "ExperimentConfiguration.h"

using namespace std;

/**
 * Main: Clase que contiene el programa principal (main) de la tarea.
 * Se configura con condiciones iniciales y se fijan ciertos parametros del
 * experimento.
 * @param args : se utilizan los 3 primeros argumentos para definir el
 *  problema
 */

int main(int argc, char** argv) {
    
    // get argv data
    
    
    // set environment constants
    float gravity = -9.8f; // [m/s^2]
    float dumping = 1.0f;

    
    // set new experiment situation
    MyWorld * world = new MyWorld();
    world->setDumping(dumping);
    world->setGravity(gravity);
    
    // add the world situation to the experiment
    ExperimentConfiguration * exp = new ExperimentConfiguration();
    exp->addItselfTo(world);
    
    world->simulate(0.001,0,10); // delta time[s], total simulation time [s].
    
    return 0;
}

