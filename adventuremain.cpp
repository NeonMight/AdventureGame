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
	/*Room r("Test",NULL,NULL,NULL);
	Room* startroom = &r;*/
	Player p(100,10,/*startroom*/NULL,NULL); // This is placeholder code.

	// Game loop
	// Flow: Ask for user input, player does action, if monsters are present, they attack, repeat.
	while (p.isAlive()) { // Continue looping while the player is alive
		cout << "Input Command:";
		cin >> input;
		p.doInput(input); // This function will convert user input into a function call. All game output will be from a function called from here.
		cout << "\n";
	}
	cout << "You died!\n"; // Game over
}
