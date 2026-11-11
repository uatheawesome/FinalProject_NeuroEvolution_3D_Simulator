//
// Created by ua on 11/11/2026.
//

#ifndef NEUROEVOLUTION3DSIMULATOR_GENOME_H
#define NEUROEVOLUTION3DSIMULATOR_GENOME_H
#include <vector>
#include "Synapse.h"
#include "Neuron.h"


class Genome {
    std::vector<Neuron> Neurons;
    std::vector<Synapse> Synapses;
    int HighestInnovation;
    public:
    Genome(int InputCount );
    std::vector<Synapse> GetSynapses()const;
    void AddSynapse(const Synapse &Synapse);
    Genome* ProCreate(const Genome Parent2);
};


#endif //NEUROEVOLUTION3DSIMULATOR_GENOME_H
