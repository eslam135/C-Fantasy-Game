#pragma once
#include <string>
#include <unordered_map>
#include "Attribute.h"

class Footballer {
public:
    Footballer(int id, std::string name, int price);
    Footballer();
    void updatepoints(int points);
    void addAttribute(std::string name, int value, int weight);
    int calculatePrice(int last_match_points);
    int calculatePrice();
    int getValue(std::string name);
    int getPrice();
    int id;
    std::string name;
    int price;
    int points;
    int last_match_points;
    std::unordered_map<std::string, Attribute*> attributes;
};