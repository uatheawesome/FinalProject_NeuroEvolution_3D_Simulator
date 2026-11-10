//
// Created by ua on 10/11/2026.
//

#ifndef TMPTILFIXED_WEIGHT_H
#define TMPTILFIXED_WEIGHT_H
class Node;

class Weight
{
    float WValue;
    Node* InputNode;
    public:
    Weight(float Value, Node* InputNode);
    Weight();
    float GetWValue();
    void SetWValue(float WValue);
    Node* GetInputNode();
};


#endif //TMPTILFIXED_WEIGHT_H
