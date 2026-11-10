//
// Created by ua on 10/11/2026.
//

#ifndef TMPTILFIXED_NEURALNETWORK_H
#define TMPTILFIXED_NEURALNETWORK_H
#include "Node.h"
class HiddenLayer;

class NeuralNetwork
{
    std::vector<Node> InputNodes;
    std::vector<HiddenLayer> HiddenNodes;
    std::vector<Node> OutputNodes;
    public:
    NeuralNetwork();
    void AddHiddenNode(HiddenLayer hiddenNode);
};


#endif //TMPTILFIXED_NEURALNETWORK_H
