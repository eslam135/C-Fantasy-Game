#include "Admin.h"
#include "Footballer.h"

unordered_map<int, Footballer*> Admin::all_footballers;
unordered_map<int, Player*> Admin::all_players;
unordered_map<int, Match*> Admin::all_matches;
unordered_map<int, Team*> Admin::all_teams;


Footballer* Admin::createFootballer(int id, string name, int price) {
    Footballer* new_footballer = new Footballer(id, name, price);
    Admin::all_footballers[id] = new_footballer;
    return new_footballer; 
}

Team* Admin::insertTeam(string name, int id) {
    Team* team = new Team(name, id);
    Admin::all_teams[id] = team;
    return team;
}


Player* Admin::createPlayer(int id, string username, string password) {
    Player* player = new Player(id, username, password);
    Admin::all_players[id] = player;
    return player;
}

Match* Admin::createMatch(int id, int day, int home_team_id, int away_team_id, std::vector<int> goals, std::vector<int> players) {
    Match* match = new Match(id,day, home_team_id, away_team_id, goals, players);
    Admin::all_matches[id] = match;
    return match;
}

void Admin::next_match(League& league) {
    league.nextMatch();
}

Admin::Admin() {

}





