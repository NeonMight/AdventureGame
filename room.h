#include <iostream>
#include <string>
#include "item.h"
#include "monster.h"
#pragma once

// Room Class
class Room //each separate space. Player can travel between adjacent spaces with go command
{
	public:
		Room(std::string n, Room** a, Item** t, Monster** m);
		~Room();
		void searchRoom() const; // prints out all the items, monsters, and adjacent rooms
		void give(int); // Give an item to the player.
		void take(int,Item*); // Take an item from the player.
		int nextOpen() const; // Gives index to next open space in inventory. -1 for no space available.
		Item* atIndex(int) const; // Gives reference to the item at an index in the inventory
		Monster* monsterIndex(int) const; // Gives reference to the monster at an index
		std::string getName() const; // Returns name of room
		Room* getAdjacent(int) const; // Return pointer to adjacent room
		void addAdjacent(Room** r);
		void monsterAttack(Player p); //accesses enemies to all use Attack function
	private:
		std::string name;	//basic name
		Item** inventory; //items that room contains (Array)
		Monster** enemies; //Monsters that the room contains (Array)
		Room** adjacent;	//room pointer list denoting different directions; north=0, east=1, south=2, west=3
};
