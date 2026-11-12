//
// Created by ua on 11/11/2026.
//

#include "Synapse.h"
#include "Random.h"
#include <random>
int Synapse::GlobalInnovation = 0;

Synapse::Synapse( int In_Neuron_ID, int Out_Neuron_ID)
{
    this->Enabled = true;
    this->SynapseInnovation = ++GlobalInnovation;
    this->Weight = UniformFloat(RandomGen);
    this->In_Neuron_ID = In_Neuron_ID;
    this->Out_Neuron_ID = Out_Neuron_ID;
}
Synapse& Synapse::operator=(const Synapse& ESynapse) {
    if (this != &ESynapse) {
        this->In_Neuron_ID = ESynapse.In_Neuron_ID;
        this->Out_Neuron_ID = ESynapse.Out_Neuron_ID;
        this->Weight = ESynapse.Weight;
        this->Enabled = ESynapse.Enabled;
        this->SynapseInnovation = ESynapse.SynapseInnovation;
    }
    return *this;
}
