#include "PlayersLeague.h"
#include "Admin.h"

PlayersLeague::PlayersLeague() {

}

bool compareByPoints(Player* a, Player* b) {
	return a->getTeamPoints() > b->getTeamPoints();
}

void PlayersLeague::sortPlayers() {
	std::sort(players.begin(), players.end(), compareByPoints);
}

void PlayersLeague::showPlayers() {
	this->sortPlayers();
	for (Player* player : players) {
		cout << player->username<<" with: "<< player->getTeamPoints()<<" points" << endl;
	}
}
void PlayersLeague::addPlayer(int id) {
	players.push_back(Admin::all_players[id]);
}