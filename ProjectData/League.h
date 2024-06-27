#pragma once
#include <vector>
#include "Player.h"
#include "Match.h"
#include<queue>
#include<list>
using namespace std;


struct CompareMatchDay {
	bool operator()( Match* a,  Match* b)  {
		return a->day > b->day;
	}
};

class League {
    priority_queue<Match*, vector<Match*>, CompareMatchDay> matches;
public:
    League(void);
    Match* currentMatch;
    void addMatch(int match_id);
    void nextMatch();
};
