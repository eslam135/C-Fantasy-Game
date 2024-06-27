#pragma once
#include "Team.h"
#include <string>
using namespace std;

class Player {
public:
    int id;
    string username;
    string password;
    int budget;
    Team* created_team;
    Player(int id, string username, string password);
    Player(void);
    void buyFootballer(int footballer_id);
    void sellFootballer(int footballer_id);
    int getTeamPoints();
    void spinTheWheel(int price);
    int randomizeation();
};
