/* 
 * File:   ExperimentConfiguration.cpp
 * Author: pancho
 * 
 * Created on 16 August 2011, 23:14
 */

#include "ExperimentConfiguration.h"

/*
 * Funcion/Metodo que permite configurar el ambiente del escenario de
 * experimentacion
 * @param none
 */
ExperimentConfiguration::ExperimentConfiguration() {
    /**
     * Condiciones iniciales:
     * restlength: 1.5m sobre el suelo
     * posy_hook: 3.0m sobre el suelo
     * posx_hook: 0.0m esta en el centro de un eje coordenado
     * mass: 1.0 kg
     * stiffnes: 10 [N/m]
     */
    double restLength = 1.0;
    float stiffness = 10.0;
    float mass = 2.0;
    double posx_hook = 0.0;
    double posy_hook = 3.0;

    // Configuracion de vectores
    Vector2D pos_hook(posx_hook, posy_hook);
    Vector2D pos_block(1.0, 2);
    Vector2D speed_block(0.0, 0.0);
    Vector2D pos_block2(-0.3, 0.2);
    Vector2D speed_block2(0.0, 0.0);

    // Configuracion de PhysicsElements : fixedhook, block & spring
    FixedHook * hook = new FixedHook(pos_hook);
    Block * block = new Block(mass, pos_block, speed_block);
    Spring * spring = new Spring(stiffness, restLength);
    Block * block2 = new Block(mass, pos_block2, speed_block2);
    Spring * spring2 = new Spring(stiffness, restLength);

    // Enganchar
    spring->attachAEnd(hook);
    spring->attachBEnd(block);
    spring2->attachAEnd(block);
    spring2->attachBEnd(block2);
    
    // add to elements array
    elements.push_back(hook);
    elements.push_back(spring);
    elements.push_back(block);

}

ExperimentConfiguration::ExperimentConfiguration(const ExperimentConfiguration& orig) {
}

ExperimentConfiguration::~ExperimentConfiguration() {
}

void ExperimentConfiguration::addItselfTo(MyWorld* world) {
    for (int i = 0; i < elements.size(); i++)
        world->addElement(elements[i]);
}