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

void Player::get(int x) {
	int i = nextOpen(); // Get next open spot
	if ( i == -1 ) { std::cout << "There is no space in your inventory.\n"; return; } // If no spot available, return
	inventory[i] = location->atIndex(x); // Give the item to the inventory
	location->give(x); // Take from room's inventory
}

int Player::nextOpen() const {
	for (int i = 0; i < 10; i++) {
		if ( inventory[i] == NULL ) return i;
	}
	return -1; // No space available
}

void Player::modifyHealth(int x) {
	player.hp += x;
	std::cout << "You have ";
	if (x > 0) ? std::cout << "gained ": std::cout << "lost ";
	std::cout << x << " health.\n";
}

void Player::showHealth() const {
	std::cout << "Your current health is " << player.hp << ".\n";
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
		case "0": eat(0); return;
		case "1": eat(1); return;
		case "2": eat(2); return;
		case "3": eat(3); return;
		case "4": eat(4); return;
		case "5": eat(5); return;
		case "6": eat(6); return;
		case "7": eat(7); return;
		case "8": eat(8); return;
		case "9": eat(9); return;
		default: std::cout << "Invalid argument for 'eat'.\nValid arguments for 'eat' are numbers 0-9.\n"; return;
	}
	
get:
	switch (args[1]) {
		case "0": get(0); return;
		case "1": get(1); return;
		case "2": get(2); return;
		case "3": get(3); return;
		case "4": get(4); return;
		case "5": get(5); return;
		case "6": get(6); return;
		case "7": get(7); return;
		case "8": get(8); return;
		case "9": get(9); return;
		default: std::cout << "Invalid argument for 'get'.\nValid arguments for 'get' are numbers 0-9.\n"; return;
	}
	
drop:
	switch (args[1]) {
		case "0": drop(0); return;
		case "1": drop(1); return;
		case "2": drop(2); return;
		case "3": drop(3); return;
		case "4": drop(4); return;
		case "5": drop(5); return;
		case "6": drop(6); return;
		case "7": drop(7); return;
		case "8": drop(8); return;
		case "9": drop(9); return;
		default: std::cout << "Invalid argument for 'drop'.\nValid arguments for 'drop' are numbers 0-9.\n"; return;
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
		case "0": attack(0); return;
		case "1": attack(1); return;
		case "2": attack(2); return;
		case "3": attack(3); return;
		case "4": attack(4); return;
		default: std::cout << "Invalid argument for 'attack'.\nValid arguments for 'attack' are numbers 0-4.\n"; return;
	}
	
help:
	std::cout << "Valid commands are 'eat', 'get', 'drop', 'go', 'attack', 'search', 'inventory', 'health', and 'help'.\n";
	return;
}

///////////
///Room
///////////

int Room::nextOpen() const {
	for (int i = 0; i < 10; i++) {
		if ( inventory[i] == NULL ) return i;
	}
	return -1; // No space available
}

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
