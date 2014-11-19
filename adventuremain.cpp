// Version 1.0
// Created by Stephen Hoffman, Ethan Waddle, & Justin McAlister

#include "player.h"
#include "room.h"
#include <iostream>
#include <string> 
using namespace std;

int main() {
	string input;
	
	//Initializations
	Item t1("Test Item",0,0);
	
	Monster m1(20,3,"Test Monster");
	
	Item* r1i[] = {&t1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	Monster* r1m[] = {NULL,&m1,NULL,NULL,NULL};
	Item* r2i[] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	Monster* r2m[] = {NULL,NULL,NULL,NULL,NULL};
	
	Room r1("Test 1",NULL,r1i,r1m);
	Room r2("Test 2",NULL,r2i,r2m);
	
	Room* r1a[] = {NULL,&r2,NULL,NULL};
	Room* r2a[] = {&r1,NULL,NULL,NULL};
	
	r1.addAdjacent(r1a);
	r2.addAdjacent(r2a);
	
	Player p(100,10,&r1); // This is placeholder code.

	// Game loop
	// Flow: Ask for user input, player does action, if monsters are present, they attack, repeat.
	while (p.isAlive()) { // Continue looping while the player is alive
		cout << "Input Command:";
		getline(cin,input);
		p.doInput(input); // This function will convert user input into a function call. All game output will be from a function called from here.
		cout << "\n";
	}
	cout << "You died!\n"; // Game over
}
