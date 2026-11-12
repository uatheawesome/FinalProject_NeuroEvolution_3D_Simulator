//
// Created by ua on 11/11/2026.
//

#ifndef FINALPROJECT_NEUROEVOLUTION_3D_SIMULATOR_SYNAPSE_H
#define FINALPROJECT_NEUROEVOLUTION_3D_SIMULATOR_SYNAPSE_H

class Synapse
{
    bool Enabled;
    static int GlobalInnovation;
    int SynapseInnovation;
    float Weight;
    int In_Neuron_ID;
    int Out_Neuron_ID;

public:
    Synapse( int In_Neuron_ID, int Out_Neuron_ID);
    void Disable(){this->Enabled=false;}
    void Enable(){this->Enabled=true;}
    [[nodiscard]] bool IsEnabled() const{return this->Enabled;}
    [[nodiscard]] int GetSynapseInnovation()const{return SynapseInnovation;}
    [[nodiscard]] int GetInNeuronID() const { return In_Neuron_ID; }
    [[nodiscard]] int GetOutNeuronID() const { return Out_Neuron_ID; }
    [[nodiscard]] float GetWeight() const { return Weight; }
    void SetWeight(const float NewWeight){this->Weight = NewWeight;}
    Synapse& operator=(const Synapse &);
};


#endif //FINALPROJECT_NEUROEVOLUTION_3D_SIMULATOR_SYNAPSE_H
