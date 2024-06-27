#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include "Footballer.h"
using namespace std;

class Team {
public:
    string name;
    int id;
    int total_price;
    list<Footballer*> currentPlayers;
    Team(string& name, int id);
    Team(void);
    void addFootballer(int footballer_id);
    void removeFootballer(int footballer_id);
    void replaceFootballer(int footballer1, int footballer2);
    int getPrice();
};
