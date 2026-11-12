//
// Created by ua on 11/11/2026.
//

#include "Neuron.h"
#include "Random.h"
#include <random>

int Neuron::NeuronIDCounter = 0;

Neuron::Neuron(NeuronTypes Type)
{
    this->NeuronID = ++NeuronIDCounter;
    this->ThisNeuronType = Type;
    this->Bias = UniformFloat(RandomGen);
    this->ActivationValue = 0;
}
Neuron::Neuron()
{
    this->NeuronID = ++NeuronIDCounter;
    this->ThisNeuronType = NeuronTypes::HIDDEN;
    this->Bias = UniformFloat(RandomGen);
    this->ActivationValue = 0;
}