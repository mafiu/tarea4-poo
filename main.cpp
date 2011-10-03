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

    float samplingTime, deltaTime, endTime;
    float gravity = -9.8f; // [m/s^2]
    float dumping = 1.0f;
    
    istringstream b(argv[0]);
    b >> samplingTime;
    istringstream c(argv[1]);
    c >> deltaTime;
    istringstream d(argv[2]);
    d >> endTime;
   
    ExperimentConfiguration * configuration = new ExperimentConfiguration();
    

    MyWorld * world = new MyWorld();
    world->setGravity(gravity);
    world->setDumping(dumping);
    //world.setOutputFile(System.out);
    configuration->addItselfTo(world);
    world->simulate(deltaTime, samplingTime, endTime); // delta time[s], total simulation time [s].

    return 0;
}

