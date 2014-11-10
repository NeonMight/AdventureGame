#include "adventure.h"
#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>  

///////////
///Player
///////////

void Player::go(int x) {
	location = location->adjacent[x];
	switch (x) {
		case 0: std::cout << "You have moved north.\n"; return;
		case 1: std::cout << "You have moved south.\n"; return;
		case 2: std::cout << "You have moved east.\n"; return;
		case 3: std::cout << "You have moved west.\n"; return;
		default: return;
	}
}

void Player::showHealth() const {
	std::cout << "Your current health is " << player.hp << ".\n";
}

void Player::modifyHealth(int x) {
	player.hp += x;
	std::cout << "You have ";
	if (x > 0) ? std::cout << "gained ": std::cout << "lost ";
	std::cout << x << " health.\n";
}

bool Player::isAlive() const {
	if (player.hp > 0) ? return true : return false;
}

void Player::doInput(string s) {
	// Separate string into 2 strings in arg array
	string args[2];
	/*Code goes here to split string*/
	
	// Make the strings lowercase so they can be checked without being case sensitive.
	for (int i = 0; i < 2; i++)
		boost::algorithm::string::to_lower(args[i]); // Should convert string to lowercase. Have not tested it yet.
		
	// Base input checker, takes the first word and uses the switch to call the needed function
	switch (args[0]) {
		case "eat": goto eat;
		case "get": goto get;
		case "drop": goto drop;
		case "go": goto go;
		case "attack": goto attack;
		case "search": location->searchRoom(); return;
		case "inventory": checkInventory(); return;
		case "health": showHealth(); return;
		case "help": goto help;
		default: std::cout << "Unknown command, use 'help' to view commands.\n"; return;
	}
	
eat:
	switch (args[1]) {
		default: std::cout << "Invalid argument for 'eat'.\n"; return;
	}
	
get:
	switch (args[1]) {
		default: std::cout << "Invalid argument for 'get'.\n"; return;
	}
	
drop:
	switch (args[1]) {
		default: std::cout << "Invalid argument for 'drop'.\n"; return;
	}
	
go:
	switch (args[1]) {
		case "n": go(0); return;
		case "s": go(1); return;
		case "e": go(2); return;
		case "w": go(3); return;
		default: std::cout << "Invalid argument for 'go'.\nValid arguments for 'go' are 'n', 's', 'e', and 'w'.\n"; return;
	}
	
attack:
	switch (args[1]) {
		default: std::cout << "Invalid argument for 'attack'.\n"; return;
	}
	
help:
	std::cout << "Valid commands are 'eat', 'get', 'drop', 'go', 'attack', 'search', 'inventory', 'health', and 'help'.\n";
	return;
}

///////////
///Room
///////////

///////////
///Item
///////////

///////////
///Monster
///////////

///////////
///Food
///////////

///////////
///Weapon
///////////
