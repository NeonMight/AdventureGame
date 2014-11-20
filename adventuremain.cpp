// Version 1.0
// Created by Stephen Hoffman, Ethan Waddle, & Justin McAlister

#include "player.h"
#include "room.h"
#include <iostream>
#include <string> 
using namespace std;

int main() {
	string input;
	bool attackturn = false;
	
	//Initializations
	Item t1("Test Item 1",0,0);
	Item t2("Test Food",1,10);
	Item t3("Test Weapon",2,5);
	Item t4("The Holy Grail",1,10000); // When we start to make enemies fight back, we'll want this for testing
	Item t5("Test Armor",3,0.5);
	
	Monster m1(50,3,"Test Monster 1");
	Monster m2(40,2,"Test Monster 2");
	
	Item* r1i[] = {&t1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&t5,NULL};
	Monster* r1m[] = {NULL,NULL,NULL,NULL,NULL};
	Room r1("Test 1",r1i,r1m);
	
	Item* r2i[] = {NULL,&t2,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	Monster* r2m[] = {NULL,&m2,NULL,&m1,NULL};
	Room r2("Test 2",r2i,r2m);
	
	Item* r3i[] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&t4,NULL};
	Monster* r3m[] = {NULL,NULL,NULL,NULL,NULL};
	Room r3("Test 3",r3i,r3m);
	
	Item* r4i[] = {NULL,NULL,NULL,&t3,NULL,NULL,NULL,NULL,NULL,NULL};
	Monster* r4m[] = {NULL,NULL,NULL,NULL,NULL};
	Room r4("Test 4",r4i,r4m);
	
	Room* r1a[] = {NULL,&r2,NULL,NULL};
	Room* r2a[] = {&r1,&r3,&r4,NULL};
	Room* r3a[] = {&r2,NULL,NULL,NULL};
	Room* r4a[] = {NULL,NULL,NULL,&r2};
	
	r1.addAdjacent(r1a);
	r2.addAdjacent(r2a);
	r3.addAdjacent(r3a);
	r4.addAdjacent(r4a);
	
	Player p(100,10,&r1); // This is placeholder code.

	// Game loop
	// Flow: Ask for user input, player does action, if monsters are present, they attack, repeat.
	while (p.isAlive()) { // Continue looping while the player is alive
		cout << "Input Command:";
		getline(cin,input);
		attackturn = p.doInput(input); // This function will convert user input into a function call. All game output will be from a function called from here.
		if (attackturn == true) {p.battle();}
		cout << "\n";
	}
	cout << "You died!\n"; // Game over
}
