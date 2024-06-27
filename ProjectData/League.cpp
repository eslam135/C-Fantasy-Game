#include "League.h"
#include "Admin.h"
#include <algorithm>
#include <iostream>
#include<queue>
using namespace std;


League::League() {
	currentMatch = 0x0;
}


void League::addMatch(int match_id) {
	bool found = false;
	unordered_map<int, Match*>::iterator it;
	for (it = Admin::all_matches.begin(); it != Admin::all_matches.end(); it++) {
		if (match_id == it->first) {
			if (matches.empty()) {
				currentMatch = Admin::all_matches[match_id];
				cout << "current Match added to ID" <<currentMatch->id << endl;
			}
			League::matches.push(Admin::all_matches[match_id]);
			found = true;
			cout << "Match added" << endl;
			break;
		}
	}
	if (!found) {
		cout << "There's nothing with this ID";
	}
}

void League::nextMatch() {
	currentMatch->calculate_points();
	currentMatch->updateFootballers();
	matches.pop();
	if (!matches.empty()) {
		currentMatch = matches.top();
	}
}
