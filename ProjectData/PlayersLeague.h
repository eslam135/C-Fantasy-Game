#pragma once
#include<vector>
#include <algorithm>
#include <iostream>
#include "Player.h"

class PlayersLeague
{
public:
	PlayersLeague();
	std::vector<Player*> players;
	void sortPlayers();
	void showPlayers();
	void addPlayer(int);
};

