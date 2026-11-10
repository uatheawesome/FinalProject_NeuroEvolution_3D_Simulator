//
// Created by ua on 10/11/2026.
//

#include "NeuralNetwork.h"
#include "Node.h"
#include "Weight.h"
#include <iostream>

static float ActivationFunctionRelu(float num) {
    if (num < 0)
        return 0;
    return num;
}
static float ActivationFunctionSigmoid(float num) {
    return 1 / (1 + exp(-num));
}
static float ActivationFunctionTanh(float num) {
    return (exp(num)-exp(-num))/(exp(num)+exp(-num));
}