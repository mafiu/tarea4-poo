/* 
 * File:   ExperimentConfiguration.h
 * Author: pancho
 *
 * Created on 16 August 2011, 23:14
 */

#ifndef EXPERIMENTCONFIGURATION_H
#define	EXPERIMENTCONFIGURATION_H

#include "AttachableElement.h"
#include "MyWorld.h"


class ExperimentConfiguration {
public:
    ExperimentConfiguration();
    ExperimentConfiguration(const ExperimentConfiguration& orig);
    virtual ~ExperimentConfiguration();

    void addItselfTo(MyWorld * world);
    
private:
    vector<PhysicsElement *> elements;

};

#endif	/* EXPERIMENTCONFIGURATION_H */

