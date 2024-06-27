#include "Footballer.h"

Footballer::Footballer(int id, std::string name, int price) {
    this->id = id;
    this->name = name;
    this->price = price;
    this->points = 0;
    this->last_match_points = 0;
}

Footballer::Footballer() {}

void Footballer::updatepoints(int points) {
    this->points += points;
}

void Footballer::addAttribute(std::string name, int value, int weight) {
    Attribute* attr = new Attribute(name, value, weight);
    price += value * weight;
    this->price = price;
    this->attributes[name] = attr;
}

int Footballer::calculatePrice(int last_match_points) {
    this->last_match_points = last_match_points;
    price += (last_match_points/price) * 100;
    return this->price;
}

int Footballer::calculatePrice() {
    return this->price;
}

int Footballer::getValue(std::string name) {
    if (this->attributes.find(name) != this->attributes.end()) {
        return this->attributes[name]->getValue();
    }
    return 0;
}

int Footballer::getPrice() {
    return this->price;
}