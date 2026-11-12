//
// Created by ua on 11/11/2026.
//

#ifndef NEUROEVOLUTION3DSIMULATOR_GENOME_H
#define NEUROEVOLUTION3DSIMULATOR_GENOME_H
#include <memory>
#include <vector>
#include "Synapse.h"
#include "Neuron.h"


class Genome {
    std::vector<Neuron> Neurons;
    std::vector<Synapse> Synapses;
    float Fitness;
    public:
    static int OutNeuronCount;
    Genome(int InputCount,int OutputCount);
    Genome();

    void Mutation_WeightTuning();//Change weights slightly
    void Mutation_NewWire();//pick two unconnected nodes adds synapse with random weight
    void Mutation_SplittingTheWire(int InnovationID);//pics existing synapse Turns it to false, then adds hidden weight and adds synapses to bridge the gap
   [[nodiscard]] std::unique_ptr<Genome>  Mutation_Procreate(const Genome& Parent1, const Genome& Parent2);

    Neuron* FindNeuronByID(int id);
    Neuron* ReturnRandNeuron();

    std::vector<float> ForwardPass(const std::vector<float>& inputs);
    std::vector<Synapse> ReturnInSynapsesOfNeuron(int Neuron_ID)const;

    void AddNeuron(const Neuron& Neuron){this->Neurons.push_back(Neuron);}
    void AddSynapse(const Synapse &Synapse){this->Synapses.push_back(Synapse);}
    void SortSynapsesByInnovation();
    [[nodiscard]] std::vector<Synapse> GetSynapses()const{return this->Synapses;}
    [[nodiscard]] std::vector<Neuron> GetNeurons()const{return this->Neurons;}
    [[nodiscard]] float GetFitness()const{return this->Fitness;}
    void SetFitness(float Fitness){this->Fitness = Fitness;}
    void SetNeurons(const std::vector<Neuron>& NewNeurons) { this->Neurons = NewNeurons; }
    void SetSynapses(const std::vector<Synapse>& NewSynapse) { this->Synapses = NewSynapse; }
   };


#endif //NEUROEVOLUTION3DSIMULATOR_GENOME_H
