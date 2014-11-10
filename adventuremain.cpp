#include "adventure.h"
#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>  
using namespace std;

int main() {
startgame: // startgame label. When restarting a game, it will jump back to here.
	//Initializations
	Player p(); // This is placeholder code.
	string input;

	// Game loop
	while (p.isAlive()) { // Continue looping while the player is alive
		cin >> input;
		p.doInput(input); // This function will convert user input into a function call. All game output will be from a function called from here.
	}

	// Check if player wants to play again
	cout << "You died!\n";
playagainchecker: // If input is invalid, program will jump back to here
	cout << "Do you want to play again?\n";
	cout << "Type 'y' or 'yes' for yes. Type 'n' or 'no' for no.\n";
	cin >> input;
	boost::algorithm::string::to_lower(input); // This should convert string to lowercase. Have not tested it yet.
	switch (input) {
		case "yes": goto restartgame; // Jump to restartgame
		case "no": return 0; // Exit program
		case "y": goto restartgame; // Jump to restartgame
		case "n": return 0; // Exit program
		default: cout << "Invalid answer.\n"; goto playagainchecker; // Ask again
	}

	// Repair game to original state to be played again.	
restartgame: // restartgame label. Program jumps here if the player wants to play again.
	// Code will go here to deconstruct all objects constructed at the beginning of the program.
	goto startgame;	// Program will jump to startgame label, recreating all the objects allowing the player to play again.
}
