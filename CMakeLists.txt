cmake_minimum_required(VERSION 3.16)
project(NeuroEvolution3DSimulator VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source files
set(SOURCES
    main.cpp
    NeuralNetwork.cpp
        Synapse.cpp
        Synapse.h
        Neuron.cpp
        Neuron.h
        Mutate.cpp
        Mutate.h
)

# Header files
set(HEADERS
    NeuralNetwork.h
        Genome.cpp
        Genome.h
        Synapse.cpp
        Synapse.h
        Neuron.cpp
        Neuron.h
        Mutate.cpp
        Mutate.h
)

# Executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS}
        Synapse.cpp
        Synapse.h
        Neuron.cpp
        Neuron.h
        Mutate.cpp
        Mutate.h)

# Set output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
