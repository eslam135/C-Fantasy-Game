#include "Match.h"
#include <queue>
#include <vector>
#include "Footballer.h"
#include "Admin.h"


Match::Match(int id,int day, int home_team_id, int away_team_id, vector<int> goals, vector<int> players) {
	this->id = id;
	this->home_team_id = home_team_id;
	this->away_team_id = away_team_id;
    this->day = day;
    for (int i = 0; i < players.size(); i++) {
        playerScorings[players.at(i)] = { goals.at(i) };
    }
}



void Match::calculate_points() {
    for (auto& playerScore : playerScorings) {
        int footballer_id = playerScore.first;
        int goals = playerScore.second;
        if (Admin::all_footballers.find(footballer_id) != Admin::all_footballers.end()) {
            Footballer* footballer = Admin::all_footballers[footballer_id];
            footballer->updatepoints(goals * goal_weight);
        }
    }
}

void Match::updateFootballers() {
    for ( auto& playerScoring : playerScorings) {
        int footballer_id = playerScoring.first;
        int goals = playerScoring.second;
        Footballer* footballer = Admin::all_footballers[footballer_id];
        footballer->calculatePrice(goals); 
    }
}

