#include <iostream>
#include <string>
#include "item.h"
#include "room.h"
#pragma once

//Player Class
class Player //denotes the player character
{
	public:
		Player(int health, int a, Room* l); //no inventory because always starts as null
		~Player();
		void go(int); // Goes in a direction, 0-4, corresponding with n,s,e, and w
		void get(int); //Takes int value to correspond with item index in room. When player gets a weapon, modify currentwep. Item is removed from room and added to inventory.
		void drop(int); //Takes int value to correspond with item index in inventory to drop. Adds to room
		void eat(int); //Adds food value, then consumes food
		void attack(int); //does damage equal to player attack + currentwep. if null, + 0. Takes index of monster in room
		void weapon(int); // Choose weapon
		void armor(int); // Choose armor
		int nextOpen() const; // Gives reference to next open space in inventory
		Item* atIndex(int) const; // Gives reference to the item at an index in the inventory
		void checkInventory() const; //outputs all things in player inventory
		void modifyHealth(int); // Takes an int value and alters player's health by that value
		void showHealth() const; // Prints out player's health
		bool isAlive() const; // Returns status of the player, alive or dead
		bool doInput(std::string); // Function that takes user input
		std::string getCurrentLocation() const; //uses get name on current room to describe current location
		void battle(); //accesses current location and calls monsterAttack
		void suicide(); // Allows player to kill themself, exiting the game.
		
		void chooseClass(int H, int A, float D){
		hp+=H; defaultatk+=A; defense+=D;} //modifies base stats
		
	private:
		int hp;		//hit points
		int atk;	//attack value
		int defaultatk; // Default attack value
		float defense; // armor value, should be less than 1
		Room* location;
		Item** inventory;	//array of item pointers
		int currentwep; // Index of weapon. If -1, no weapon
		int gear; // Index of armor. If -1, no armor
};
