//
// Created by ua on 11/11/2026.
//

#ifndef FINALPROJECT_NEUROEVOLUTION_3D_SIMULATOR_SYNAPSE_H
#define FINALPROJECT_NEUROEVOLUTION_3D_SIMULATOR_SYNAPSE_H
#include "Neuron.h"


class Synapse
{
    bool Enabled;
    static int GlobalInnovation;
    int SynapseInnovation;
    float Weight;
    Neuron * In_Neuron;
    Neuron * Out_Neuron;

public:
    int GetSynapseInnovation();
};


#endif //FINALPROJECT_NEUROEVOLUTION_3D_SIMULATOR_SYNAPSE_H
