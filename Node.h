//
// Created by ua on 10/11/2026.
//

#ifndef TMPTILFIXED_NODE_H
#define TMPTILFIXED_NODE_H
#include <vector>
#include "Weight.h"
#include <cmath>

class Node {
    float NValue;
    //bool isOutput;
    float Bias;
    std::vector<Weight> InputWeights;
    public:
    Node();
    Node(float NValue, std::vector<Weight>& Weights,float Bias);
    Node(float NValue, std::vector<Weight>& InputWeights);
    void SetNValue(float NValue);
    float GetNValue();
    void ForwardPass();//calc NValue
};


#endif //TMPTILFIXED_NODE_H
