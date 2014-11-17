// Version 1.0
// Created by Stephen Hoffman, Ethan Waddle, & Justin McAlister

#include "player.h"
//#include "room.h"
#include <iostream>
#include <string> 
using namespace std;

int main() {
	string input;
	
	//Initializations
	Player p(100,10,NULL,NULL); // This is placeholder code.

	// Game loop
	// Flow: Ask for user input, player does action, if monsters are present, they attack, repeat.
	while (p.isAlive()) { // Continue looping while the player is alive
		cin >> input;
		p.doInput(input); // This function will convert user input into a function call. All game output will be from a function called from here.
	}
	cout << "You died!\n"; // Game over
}
