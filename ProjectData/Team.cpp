#include "Team.h"
#include "Footballer.h"
#include "Admin.h"
#include <iostream>
using namespace std;
Team::Team(string& name, int id) {
	this->name = name;
	this->id = id;
	this->total_price = 0;
}

Team::Team() {

}

void Team::addFootballer(int footballer_id) {
	if (this->currentPlayers.size() < 12) {
		bool found = false;
		for (Footballer* thisplayer : currentPlayers) {
			if (thisplayer->id == footballer_id) {
				cout << "You Already have this player in your team";
				return;
			}
		}

		unordered_map<int, Footballer*>::iterator it;
		for (it = Admin::all_footballers.begin(); it != Admin::all_footballers.end(); it++) {
			if (footballer_id == it->first) {
				Team::currentPlayers.push_back(Admin::all_footballers[footballer_id]);
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "There's no player with this ID";
		}
	}
	else {
		cout << "Sorry your team has reached the maximum capacity" << endl;
	}

}

void Team::removeFootballer(int footballer_id) {
	auto it = currentPlayers.begin();
	while (it != currentPlayers.end()) {
		if ((*it)->id == footballer_id) {
			currentPlayers.erase(it);
			break;
		}
		++it;
	}
}

void Team::replaceFootballer(int footballer1, int footballer2) {
	Team::removeFootballer(footballer1);
	Team::addFootballer(footballer2);
}

int Team::getPrice() {
	int total_price = 0;
	for (Footballer* thisplayer : currentPlayers) {
		total_price += thisplayer->getPrice();
	}
	this->total_price = total_price;
	return this->total_price;
}