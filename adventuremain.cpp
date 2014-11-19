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
	Monster mouse1(999,500,"Rowdy Mouse"); //create an enemy
	Room mouseRoom("dusty room with mice", NULL, NULL, NULL); //create mouse room
	Room* startingpoint = &mouseRoom; //point to mouse room
	Player p(100,10,startingpoint,NULL);
	// Game loop
	// Flow: Ask for user input, player does action, if monsters are present, they attack, repeat.
	while (p.isAlive()) { // Continue looping while the player is alive
		cout << "You are in a " << p.getCurrentLocation() << "." << endl;
		cout << "Input Command:";
		getline(cin,input);
		p.doInput(input); // This function will convert user input into a function call. All game output will be from a function called from here.
		cout << "\n";
	}
	cout << "You died!\n"; // Game over
}
