#pragma once
#include <string>

class Attribute {
public:
    Attribute(std::string name, int value, int weight);
    std::string getName();
    int getValue();
    int getWeight();
    std::string name;
    int value;
    int weight;
};