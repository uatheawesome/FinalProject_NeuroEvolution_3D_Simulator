//
// Created by ua on 13/11/2026.
//

#ifndef NEUROEVOLUTION3DSIMULATOR_SPECIES_H
#define NEUROEVOLUTION3DSIMULATOR_SPECIES_H
#include "Genome.h"

class Species
{
    std::vector<Genome> Members;
    int MemberCount;
    public:
    Species();
    float BestFitness();
    int GenerationsSinceImprovement();
    //add when to mutate etc
};


#endif //NEUROEVOLUTION3DSIMULATOR_SPECIES_H
