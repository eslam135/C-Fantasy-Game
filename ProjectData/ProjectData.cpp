#include <iostream>
#include "Admin.h"
#include "League.h"
#include "Player.h"
#include "Team.h"
#include "Footballer.h"
#include "PlayersLeague.h"
int main() {
    Admin admin;

    Footballer* f1 = admin.createFootballer(1, "Lionel Messi", 120);
    Footballer* f2 = admin.createFootballer(2, "Cristiano Ronaldo", 110);
    Footballer* f3 = admin.createFootballer(3, "Neymar", 100);
    Footballer* f4 = admin.createFootballer(4, "Benzema", 200);
    f1->updatepoints(10);
    f2->updatepoints(8);
    f3->updatepoints(6);
    f4->updatepoints(4);

    f1->addAttribute("speed", 90, 3);
    f1->addAttribute("dribbling", 95, 4);

    f2->addAttribute("speed", 92, 3);
    f2->addAttribute("dribbling", 89, 4);

    f3->addAttribute("speed", 88, 3);
    f3->addAttribute("dribbling", 94, 4);

    f4->addAttribute("speed", 100, 3);
    f4->addAttribute("dribbling", 32, 4);

    int newPriceF1 = f1->calculatePrice(f1->last_match_points);
    int newPriceF2 = f2->calculatePrice(f2->last_match_points);
    int newPriceF3 = f3->calculatePrice(f3->last_match_points);
    int newPriceF4 = f4->calculatePrice(f4->last_match_points);


    std::cout << "Footballer " << f1->name << " has a new price of $" << newPriceF1 << std::endl;
    std::cout << "Footballer " << f2->name << " has a new price of $" << newPriceF2 << std::endl;
    std::cout << "Footballer " << f3->name << " has a new price of $" << newPriceF3 << std::endl;
    std::cout << "Footballer " << f4->name << " has a new price of $" << newPriceF4 << std::endl;


    Player* player1 = admin.createPlayer(1, "player1", "password1");
    player1->spinTheWheel(1000);
    Player* player2 = admin.createPlayer(2, "player2", "password2");
    Player* player3 = admin.createPlayer(3, "player3", "password3");

    player1->buyFootballer(2);

    player2->buyFootballer(3);
    player2->buyFootballer(4);

    cout << "====================================================" << endl;


    cout << "Player1's team price after manually changing the points " << player1->created_team->getPrice() << endl;
    cout << "Player2's team price after manually changing the points " << player2->created_team->getPrice() << endl;
    cout << "Player1's team points after manually changing the points " << player1->getTeamPoints() << endl;
    cout << "Player2's team points after manually changing the points " << player2->getTeamPoints() << endl;


    Team* Barca = admin.insertTeam("Barca", 1);
    Team* Real = admin.insertTeam("Real", 2);
    Barca->addFootballer(1);
    Barca->addFootballer(3);

    Real->addFootballer(2);
    Real->addFootballer(4);

    vector<int> match1Goals = { 2, 3 };
    vector<int> match2Goals = { 1, 4 };
    vector<int> match1scorers = { 1, 2 };
    vector<int> match2scorers = { 3, 4 };
    Match* match1 = admin.createMatch(1, 1, 1, 2, match1Goals, match1scorers);
    Match* match2 = admin.createMatch(2, 1, 2, 1, match2Goals, match2scorers);

    League league;
    league.addMatch(1);
    league.addMatch(2);

    admin.next_match(league);

    cout << "====================================================" << endl;

    cout << "Player1's team price after first match changing the points " << player1->created_team->getPrice() << endl;
    cout << "Player2's team price after first match changing the points " << player2->created_team->getPrice() << endl;
    cout << "Player1's team points after first match changing the points " << player1->getTeamPoints() << endl;
    cout << "Player2's team points after first match changing the points " << player2->getTeamPoints() << endl;

    admin.next_match(league);

    cout << "====================================================" << endl;

    cout << "Player1's team price after second match changing the points " << player1->created_team->getPrice() << endl;
    cout << "Player2's team price after second match changing the points " << player2->created_team->getPrice() << endl;
    cout << "Player1's team points after second match changing the points " << player1->getTeamPoints() << endl;
    cout << "Player2's team points after second match changing the points " << player2->getTeamPoints() << endl;

    PlayersLeague l;
    l.addPlayer(1);
    l.addPlayer(3);
    l.addPlayer(2);
    l.showPlayers();

    return 0;
}
