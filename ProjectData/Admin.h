#pragma once
#include "Footballer.h"
#include "League.h"
#include "Player.h"
#include "Match.h"
#include <unordered_map>
class Admin {
public:
   static unordered_map<int, Footballer*> all_footballers;
   static unordered_map<int, Player*> all_players;
   static unordered_map<int, Match*> all_matches;
   static unordered_map<int, Team*> all_teams;
    Admin();
    Footballer* createFootballer(int id, string name, int price);
    Team* insertTeam(string ,int id);
    Player* createPlayer(int id, string username, string password);
    Match* createMatch(int id, int day, int home_team_id, int away_team_id, std::vector<int> goals, std::vector<int> players);
    void next_match(League&);
};
