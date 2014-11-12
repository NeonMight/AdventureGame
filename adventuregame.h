// Version 1.0
//Created by Stephen Hoffman, Ethan Waddle, & Justin McAlister
#include <iostream>
//Flow: Ask for user input, player does action, if monsters are present, they attack, repeat.
//enum Direction {NORTH, SOUTH, EAST, WEST};
class Player //denotes the player character
{
	public:
		Player(int health, int a, Room* l, Weapon* c); //no inventory because always starts as null
		~Player();
		void go(int); // Goes in a direction, 0-4, corresponding with n,s,e, and w
		void get(int); //Takes int value to correspond with item index in room. When player gets a weapon, modify currentwep. Item is removed from room and added to inventory.
		void drop(int); //Takes int value to correspond with item index in inventory to drop. Adds to room
		void eat(int); //Adds food value, then consumes food
		void attack(int); //does damage equal to player attack + currentwep. if null, + 0. Takes index of monster in room
		/* void go(); //go followed by north, south, east, or west will send player to adjacent room based on initialization list
		void get(Item i, Room r); //when player gets a weapon, modify currentwep; adds i from current room inventory to player inventory
		void drop(Item i, Room r); //when player drops a weapon, modify currentwep
		void eat(Food f); //adds food value, then deletes food
		void attack(Monster m); //does damage equal to player attack + currentwep. if null, + 0 */
		int nextOpen() const; // Gives reference to next open space in inventory
		Item* atIndex(int) const; // Gives reference to the item at an index in the inventory
		void checkInventory() const; //outputs all things in player inventory
		//void takeDamage(int d); //function to access player hp when monster attacks
		void modifyHealth(int); // Takes an int value and alters player's health by that value
		void showHealth() const; // Prints out player's health
		bool isAlive() const; // Returns status of the player, alive or dead
		void doInput(string); // Function that takes user input
	private:
		int hp;		//hit points
		int atk;	//attack value
		Room* location;
		Item** inventory;	//array of item pointers
		Weapon* currentwep; //points to current weapon. If current points to null, player can pick up a weapon
};

class Room //each separate space. Player can travel between adjacent spaces with go command
{
	public:
		Room(string n, Room** a, Item** t, Monster** m);
		~Room();
		//void viewAdjacent() const; //prints out all possible directions to go from room
		void searchRoom() const; // prints out all the items, monsters, and adjacent rooms
		void give(int); // Give an item to the player.
		void take(int,Item*); // Take an item from the player.
		int nextOpen() const; // Gives index to next open space in inventory. -1 for no space available.
		Item* atIndex(int) const; // Gives reference to the item at an index in the inventory
		string getName() const; // Returns name of room
		Room* getAdjacent(int) const; // Return pointer to adjacent room
	private:
		string name;	//basic name
		Item** inventory; //items that room contains (Array)
		Monster** enemies; //Monsters that the room contains (Array)
		Room** adjacent;	//room pointer list denoting different directions; north=0, east=1, south=2, west=3
};

class Item //items are things that the player can add to inventory. Some points in game may check inventory to see if player has that item.
{
	public:
		Item(string n);
		~Item();
		string getName() const;
	private:
		string name;
};

class Monster : public Player //monsters will attack player if player is in same room. Player cannot use go if monsters are present.
{
	private:
		string name;
	public:
		Monster(int health, int a, string n, Room* l, Weapon* c); //will call player constructor with same parameters
		~Monster();
		string getName() const;
};

//derived classes

class Food : public Item //food will restore player health
{
	public:
		Food(string n, int v); //calls item constructor
		~Food();
		int getValue() const;
	private:
		int val; //amount of hit points you will recover
};

class Weapon : public Item //temporarily boosts player attack. player cannot have more than one
{
	public:
		Weapon(string n, int v); //calls item constructor
		~Weapon();
		int getValue() const;
	private:
		int val; //attack stat increase
};
