#pragma once
#include <unordered_map>
#include<vector>

class Match
{
	int home_team_id;
	int away_team_id;
	static const int goal_weight = 5;
public:
	int id;
	int day;
	std::unordered_map<int, int> playerScorings;
	Match(int id, int day ,int home_team_id, int away_team_id, std::vector<int> goals, std::vector<int> players);
	void calculate_points();
	void updateFootballers();
};

