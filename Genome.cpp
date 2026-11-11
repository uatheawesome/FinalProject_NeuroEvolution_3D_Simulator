//
// Created by ua on 11/11/2026.
//

#include "Genome.h"
using namespace std;
#include <random>
#include <iostream>

std::random_device rd;
std::mt19937 gen(rd());
std::bernoulli_distribution distribution(0.5);
Genome::Genome(int InputCount)
{
    this->Neurons = std::vector<Neuron>(InputCount);
    this->Synapses = std::vector<Synapse>();
    //connect Synapses to Neurons and update ino int
}
std::vector<Synapse> Genome::GetSynapses() const
{
    return this->Synapses;
}
void Genome::AddSynapse(const Synapse &Synapse)
{
    this->Synapses.push_back(Synapse);
}
Genome* Genome::ProCreate(const Genome Parent2)
{
    auto Child = new Genome(1);
    //DOESNT WORK
    //check who is larger
    if (this->HighestInnovation >= Parent2.HighestInnovation)
    {
        for (size_t i = 0; i < Parent2.HighestInnovation; i++)
        {
            if (i == this->Synapses.at(i).GetSynapseInnovation() && i == Parent2.GetSynapses().at(i).GetSynapseInnovation())
            {
                if (distribution(gen) == 1)
                    Child->AddSynapse(Parent2.GetSynapses().at(i));
                else
                    Child->AddSynapse(this->Synapses.at(i));
            }
            else if (true)
            {

            }
        }
    }
    else
    {
        for (size_t i = 0; i < this->HighestInnovation; i++)
        {

        }
    }
    return Child;
}
