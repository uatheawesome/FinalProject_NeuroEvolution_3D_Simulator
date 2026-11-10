//
// Created by ua on 10/11/2026.
//

#ifndef TMPTILFIXED_HIDDENLAYER_H
#define TMPTILFIXED_HIDDENLAYER_H
#include "Node.h"

class HiddenLayer {
    std::vector<Node> HiddenNodes;
    public:
    HiddenLayer();
    void AddHiddenNode(Node node);
    void UpdateThisHiddenLayerWeights(HiddenLayer PrevLayer);
};


#endif //TMPTILFIXED_HIDDENLAYER_H
