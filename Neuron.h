//
// Created by ua on 11/11/2026.
//

#ifndef FINALPROJECT_NEUROEVOLUTION_3D_SIMULATOR_NEURON_H
#define FINALPROJECT_NEUROEVOLUTION_3D_SIMULATOR_NEURON_H

class Neuron
{
    int NeuronID;
    float Bias;
public:
    static int NeuronIDCounter;
    enum class NeuronTypes { INPUT, OUTPUT, HIDDEN};
    Neuron(NeuronTypes Type);
    Neuron();
    void SetNeuronType(NeuronTypes Type){this->ThisNeuronType = Type;}
    [[nodiscard]] int GetNeuronID() const{return this->NeuronID;}
    [[nodiscard]] float GetBias() const{return this->Bias;}
    [[nodiscard]] NeuronTypes GetNeuronType() const { return this->ThisNeuronType; }
    void SetBias(float ThisBias){this->Bias = ThisBias;}
private:
    NeuronTypes ThisNeuronType;
};


#endif //FINALPROJECT_NEUROEVOLUTION_3D_SIMULATOR_NEURON_H