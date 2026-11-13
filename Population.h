//
// Created by ua on 13/11/2026.
//

#ifndef FINALPROJECT_NEUROEVOLUTION_3D_SIMULATOR_POPULATION_H
#define FINALPROJECT_NEUROEVOLUTION_3D_SIMULATOR_POPULATION_H
#include "Species.h"

class Population
{
    std::vector<Species> AllSpecies;
    Genome* BestGenome = nullptr;
    int PopulationGenerationCount;
    public:
    Population();
    [[nodiscard]] Genome* FindBestGenome()const;
};


#endif //FINALPROJECT_NEUROEVOLUTION_3D_SIMULATOR_POPULATION_H
