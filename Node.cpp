//
// Created by ua on 10/11/2026.
//

#include "Node.h"
#include <cmath>

Node::Node(float NValue, std::vector<Weight>& InputWeights,float Bias)
{
    this->NValue = NValue;
    this->InputWeights = InputWeights;
    this->Bias = Bias;
}

Node::Node(float NValue, std::vector<Weight>& InputWeights)
{
    this->NValue = NValue;
    this->InputWeights = InputWeights;
    this->Bias = 0;
}

Node::Node() {
    this->NValue = 0;
    this->Bias = 0;
    this->InputWeights = std::vector<Weight>();
}
void Node::ForwardPass() {
    float tmpValue = 0;
    for (size_t i = 0; i < InputWeights.size(); i++)
    {
        if (InputWeights[i].GetInputNode() == nullptr)
            continue;
        tmpValue += InputWeights.at(i).GetWValue() * InputWeights.at(i).GetInputNode()->GetNValue();
    }
    this->NValue = tmpValue+this->Bias;
}
void Node::SetNValue(float NValue) {
    this->NValue = NValue;
}
float Node::GetNValue() {
    return this->NValue;
}
