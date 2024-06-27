#include "Player.h"
#include "Admin.h"
#include <iostream>
#include <string>
#include<random>
using namespace std;


Player::Player(int id, string username, string password) {
    this->id = id;
    this->username = username;
    this->password = password;
    this->budget = 100000;
    string teamName = username + "'s team";
    int teamId = (Admin::all_teams.size() + 1);
    Team* t = new Team(teamName, teamId);
    Admin::all_teams[teamId] = { t };
    this->created_team = t;
}

Player::Player(void)
{
}




void Player::buyFootballer(int footballer_id) {
	if (this->created_team->currentPlayers.size() < 11) {
		bool found = false;
		for (Footballer* thisplayer : created_team->currentPlayers) {
			if (thisplayer->id == footballer_id) {
				cout << "You Already have this player in your team";
				return;
			}
		}
		unordered_map<int, Footballer*>::iterator it;
		for (it = Admin::all_footballers.begin(); it != Admin::all_footballers.end(); it++) {
			if (footballer_id == it->first) {
				if (this->budget >= it->second->getPrice()) {
					this->created_team->currentPlayers.push_back(it->second);
					this->budget -= it->second->getPrice();
					cout << this->username << " Bought: " << it->second->name << " for: " << it->second->getPrice() << " remaining budget = " << this->budget << endl;
					found = true;
					break;
				}
				else {
					found = true;
					cout << "You don't have enough money to buy this player" << endl;
				}

			}
		}
		if (!found) {
			cout << "There's no player with this ID" << endl;
		}
	}
	else {
		cout << "Sorry your team has reached the maximum capacity" << endl;
	}
}



int Player::getTeamPoints() {
    int total_points = 0;
    for (auto footballer : created_team->currentPlayers) {
        total_points += footballer->points;
    }
    return total_points;
}

void Player::spinTheWheel(int price) {
	int number = randomizeation();
	bool found = false;
	while (!found)
	{	
		auto it = Admin::all_footballers.begin();
		while (it != Admin::all_footballers.end()) {
			if (number == it->second->id) {
				if (abs((it->second->price) - price) <= 400) {
					this->budget -= price;
					this->created_team->addFootballer(number);
					cout << "Added Player: " << it->second->name << "with price" << it->second->getPrice()<<endl;
					found = true;
					break;
				}
				else {
					number = randomizeation();
					break;
				}
			}
			++it;
		}
	}
	
}

void Player::sellFootballer(int id) {
	auto it = created_team->currentPlayers.begin();
	while (it != created_team->currentPlayers.end()) {
		if ((*it)->id == id) {
			this->budget -= (*it)->getPrice();
			created_team->currentPlayers.erase(it);
			break;
		}
		++it;
	}
}
int Player::randomizeation() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(1, Admin::all_footballers.size() - 1);
	int randomIndex = dis(gen);
	return randomIndex;
}