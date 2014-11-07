// Version 1.0
//Created by Stephen Hoffman, Ethan Waddle, & Justin McAlister
#include <iostream>
//Flow: Ask for user input, player does action, if monsters are present, they attack, repeat.
enum Direction {NORTH, SOUTH, EAST, WEST};
class Player //denotes the player character
{
	public:
		Player(int health, int atk, string n, Room* l, Item** i, Weapon* currentwep);
		~Player();
		void go(); //go followed by north, south, east, or west will send player to adjacent room based on initialization list
		void get(Item i, Room r); //when player gets a weapon, modify currentwep; adds i from current room inventory to player inventory
		void drop(Item i, Room r); //when player drops a weapon, modify currentwep
		void eat(Food f); //adds food value, then deletes food
		void attack(Monster m); //does damage equal to player attack + currentwep. if null, + 0
		void checkInventory(); //outputs all things in player inventory
		void takeDamage(int d); //function to access player hp when monster attacks
	private:
		int hp;		//hit points
		int atk;	//attack value
		string name; //description
		Room* location;
		Item** inventory;	//array of item pointers
		Weapon* currentwep; //points to current weapon. If current points to null, player can pick up a weapon
};

class Room //each separate space. Player can travel between adjacent spaces with go command
{
	public:
		Room(int i, string n, Room** a, Item** t, Monster** m);
		~Room();
		void viewAdjacent() const; //prints out all possible directions to go from room
	private:
		int id;	//unique identifier
		string name;	//basic name
		Item** inventory; //items that room contains (Array)
		Monster** enemies; //Monsters that the room contains (Array)
		Room** adjacent;	//room pointer list denoting different directions; north=0, east=1, south=2, west=3
		
};

class Item //items are things that the player can add to inventory. Some points in game may check inventory to see if player has that item.
{
	public:
		//item cannot do things
		Item();
		~Item();
	private:
		string name;
};

class Monster : public Player //monsters will attack player if player is in same room. Player cannot use go if monsters are present.
{
		
};

//derived classes

class Food : public Item //food will restore player health
{
	private:
		int val; //amount of hit points you will recover
};

class Weapon : public Item //temporarily boosts player attack. player cannot have more than one
{
	private:
		int val; //attack stat increase
};
