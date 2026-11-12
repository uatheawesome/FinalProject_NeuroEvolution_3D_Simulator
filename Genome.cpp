//
// Created by ua on 11/11/2026.
//

#include "Genome.h"
#include "Random.h"
#include <iostream>
#include <algorithm>
#include <memory>


Genome::Genome(int InputCount)//default build
{
    this->Neurons = std::vector<Neuron>();
    this->Synapses = std::vector<Synapse>();
    this->Fitness = 0;
    for (size_t i = 0; i < InputCount; i++)
    {
        auto NewInputNeuron = Neuron(Neuron::NeuronTypes::INPUT);
        this->AddNeuron(NewInputNeuron);
    }
}
Genome::Genome()
{
    this->Neurons = std::vector<Neuron>();
    this->Synapses = std::vector<Synapse>();
    this->Fitness = 0;
}
void Genome::SortSynapsesByInnovation()
{
    std::sort(this->Synapses.begin(), this->Synapses.end(),
    [](const Synapse& a, const Synapse& b) {
        return a.GetSynapseInnovation() < b.GetSynapseInnovation();
    });
}

/*mutation types
addSynapse
rmSynapse
addNode
rmNode
change node's weight randomly
others
*/
std::unique_ptr<Genome> Genome::Mutation_Procreate(const Genome& Parent1,const Genome& Parent2)//main algorthm which stitches together two parents to make a new child with their genes (note child is most of the time worse than parents)
{
    const Genome* fitter = &Parent2;
    const Genome* other  = &Parent1;
    auto Child = std::make_unique<Genome>();
    bool equalFitness = (Parent1.GetFitness() == Parent2.GetFitness());
    if (Parent1.GetFitness() >= Parent2.GetFitness())
    {
        fitter = &Parent1;
        other  = &Parent2;
    }
    auto fitterSynapses = fitter->GetSynapses();
    auto otherSynapses = other->GetSynapses();
    //sort lambda id like to change and make a method
    std::sort(fitterSynapses.begin(), fitterSynapses.end(),
        [](const Synapse& a, const Synapse& b) {
            return a.GetSynapseInnovation() < b.GetSynapseInnovation();
        });
    std::sort(otherSynapses.begin(), otherSynapses.end(),
        [](const Synapse& a, const Synapse& b) {
            return a.GetSynapseInnovation() < b.GetSynapseInnovation();
        });
    size_t i = 0;
    size_t j = 0;
    while (i < fitterSynapses.size() && j < otherSynapses.size())
    {
        const auto& gene1 = fitterSynapses[i];
        const auto& gene2 = otherSynapses[j];
        if (gene1.GetSynapseInnovation()== gene2.GetSynapseInnovation())
        {
            Child->AddSynapse((Bernoulli(RandomGen) == 0) ? gene1 : gene2);
            ++i;
            ++j;
        }
        else if (gene1.GetSynapseInnovation()< gene2.GetSynapseInnovation())
        {
            Child->AddSynapse(gene1);//only the fitters genes survive
            ++i;
        }
        else
        {
            if (equalFitness)
            {
                Child->AddSynapse(gene2);
            }
            ++j;
        }
    }
    //if fitter parent has any genes left, append them
    while (i < fitterSynapses.size()) {
        Child->AddSynapse(fitterSynapses[i]);
        ++i;
    }
    // in case of equalFitness add the others fitness
    if (equalFitness)
    {
        while (j < otherSynapses.size()) {
            Child->AddSynapse(otherSynapses[j]);
            ++j;
        }
    }
    return Child;
}
void Genome::Mutation_SplittingTheWire(int InnovationID)//mutates the synapse at this ID
{
    size_t i = 0;
    while(i < this->Synapses.size() && this->Synapses.at(i).GetSynapseInnovation() != InnovationID)
        i++;
    if (i == this->Synapses.size())
    {
        return;//error
    }
    Synapse& ToMutate = this->Synapses.at(i);
    if(!ToMutate.IsEnabled())
        return;
    ToMutate.Disable();
    auto NewHidden = Neuron(Neuron::NeuronTypes::HIDDEN);
    AddNeuron(NewHidden);
    auto WireA = Synapse(ToMutate.GetInNeuronID(),NewHidden.GetNeuronID());
    auto WireB =  Synapse(NewHidden.GetNeuronID(),ToMutate.GetOutNeuronID());
    WireA.SetWeight(1.0);
    WireB.SetWeight(ToMutate.GetWeight());
    AddSynapse(WireA);
    AddSynapse(WireB);
}
void Genome::Mutation_WeightTuning()
{
    constexpr float WEIGHT_MIN = -4.0f;
    constexpr float WEIGHT_MAX =  4.0f;
    for (size_t i = 0; i < this->Synapses.size(); i++)
    {
        int RandomNumber = OneInTen(RandomGen);
        if (RandomNumber == 10)
        {
            this->Synapses.at(i).SetWeight(UniformFloat(RandomGen));
        }
        else
        {
            float ChangedWeight = this->Synapses.at(i).GetWeight();
            ChangedWeight += NudgeWeight(RandomGen);
            if (ChangedWeight > WEIGHT_MAX)
                ChangedWeight = WEIGHT_MAX;
            if (ChangedWeight < WEIGHT_MIN)
                ChangedWeight = WEIGHT_MIN;
            this->Synapses.at(i).SetWeight(ChangedWeight);
        }
    }
}
Neuron* Genome::FindNeuronByID(int id)
{
    for (size_t i = 0; i < this->Neurons.size(); i++)
    {
        if (this->Neurons.at(i).GetNeuronID() == id)
        {
            return &this->Neurons.at(i);
        }
    }
    return nullptr;
}
Neuron* Genome::ReturnRandNeuron()
{
    if (this->Neurons.empty()) return nullptr;
    return &this->Neurons[get_random_int(static_cast<int>(this->Neurons.size()) - 1)];
}
void Genome::Mutation_NewWire()
{
    constexpr int Mutation_NewWire_MAX_RETRIES = 100;
    constexpr int Inner_Mutation_NewWire_MAX_RETRIES = 100;
    int InnerMax = 0;
    for (int retry = 0; retry < Mutation_NewWire_MAX_RETRIES; retry++)
    {
        Neuron* one = this->ReturnRandNeuron();
        Neuron* two = this->ReturnRandNeuron();
        if (one == nullptr)
            continue;
        while (one == two || two == nullptr)
        {
            if (InnerMax == Inner_Mutation_NewWire_MAX_RETRIES)
                return;
            two = this->ReturnRandNeuron();
            InnerMax++;
        }
        InnerMax = 0;
        bool alreadyConnected = false;
        for (size_t i = 0; i < this->Synapses.size(); i++)
        {
            const Synapse& current = this->Synapses.at(i);
            if ((current.GetInNeuronID() == one->GetNeuronID() && current.GetOutNeuronID() == two->GetNeuronID()) ||
                (current.GetInNeuronID() == two->GetNeuronID() && current.GetOutNeuronID() == one->GetNeuronID())) {
                alreadyConnected = true;
                break;
                }
        }
        if (alreadyConnected) continue;
        //The two neurons are def not connected
        Synapse NewSynapse = Synapse(one->GetNeuronID(),two->GetNeuronID());
        AddSynapse(NewSynapse);
        return;
    }
}
