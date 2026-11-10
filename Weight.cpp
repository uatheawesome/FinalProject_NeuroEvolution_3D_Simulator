//
// Created by ua on 10/11/2026.
//

#include "Weight.h"

Weight::Weight(float WValue, Node* InputNode)
{
    this->WValue = WValue;
    this->InputNode = InputNode;
}
Weight::Weight() {
    this->WValue = 0;
    this->InputNode = nullptr;
}
void Weight::SetWValue(float WValue) {
    this->WValue = WValue;
}
float Weight::GetWValue() {
    return this->WValue;
}
Node* Weight::GetInputNode() {
    return this->InputNode;
}