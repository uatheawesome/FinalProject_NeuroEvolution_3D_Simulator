#ifndef NEUROEVOLUTION3DSIMULATOR_RANDOM_H
#define NEUROEVOLUTION3DSIMULATOR_RANDOM_H

#include <random>

inline std::random_device RandomDevice;
inline std::mt19937 RandomGen{RandomDevice()};
inline std::uniform_real_distribution<float> UniformFloat(-1.0f, 1.0f);
inline std::bernoulli_distribution Bernoulli(0.5);
inline std::uniform_int_distribution<int> OneInTen(1, 10);
inline std::normal_distribution<float> NudgeWeight(0.0f, 0.3f);
inline int get_random_int(const int N)
{
    std::uniform_int_distribution<> OneThroughN(0, N);
    return OneThroughN(RandomGen);
}
#endif //NEUROEVOLUTION3DSIMULATOR_RANDOM_H