#include "Attribute.h"

Attribute::Attribute(std::string name, int value, int weight) {
    this->name = name;
    this->value = value;
    this->weight = weight;
}

std::string Attribute::getName() {
    return this->name;
}

int Attribute::getValue() {
    return this->value;
}

int Attribute::getWeight() {
    return this->weight;
}