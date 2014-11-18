#include "player.h"
#include "room.h"
#include "item.h"
#include "monster.h"
#include <iostream>
#include <string> 
#include <sstream>

///////////
///Player
///////////

Player::Player(int health, int a, Room* l, Weapon* c)
{
	hp = health;
	atk = a;
	location = l;
	inventory = new Item*[10];
	currentwep = c;
}

Player::~Player()
{
	delete [] inventory;
}

void Player::go(int x) {
	if (location->getAdjacent(x) == NULL) { std::cout << "No passage in this direction.\n"; return; }
	location = location->getAdjacent(x);
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
	std::cout << "You picked up " << location->atIndex(x)->getName() << ".\n";
	inventory[i] = location->atIndex(x); // Give the item to the inventory
	location->give(x); // Take from room's inventory
}


void Player::eat(int x) {
	//Code to determine if item is food will go here
	//int v = inventory[x]->getValue(); // Get healing value
	//modifyHealth(v); // Add to health
	//~*inventory[x];
	inventory[x] = NULL; // Open space in inventory
}

void Player::drop(int x) {
	if (inventory[x] == NULL) {std::cout << "No item in this space.\n"; return;}
	int i = location->nextOpen();
	if (i == -1) {std::cout << "No space in the room.\n"; return;}
	std::cout << "You dropped " << inventory[x]->getName() << ".\n";
	location->take(i,inventory[x]);
	inventory[x] = NULL;
}

void Player::attack(int x) {
	Monster* m = location->monsterIndex(x);
	if ( m == NULL ) { std::cout << "No enemy in this position.\n"; return; }
	m->modifyHealth(-atk);
	std::cout << "You attacked " << m->getName() << " for " << atk << " hit points.\n";
}

int Player::nextOpen() const {
	for (int i = 0; i < 10; i++) {
		if ( inventory[i] == NULL ) return i;
	}
	return -1; // No space available
}

void Player::checkInventory() const {
	std::cout << "Inventory:\n";
	for (int i = 0; i < 10; i++) {
		std::cout << i << ": ";
		if (inventory[i] != NULL) {std::cout << inventory[i]->getName() << "\n";}
		else {std::cout << "Empty\n";}
	}
}

void Player::modifyHealth(int x) {
	hp += x;
	std::cout << "You have ";
	if (x > 0) {std::cout << "gained ";}
	else {std::cout << "lost ";}
	std::cout << x << " health.\n";
}

void Player::showHealth() const {
	std::cout << "Your current health is " << hp << ".\n";
}

bool Player::isAlive() const {
	if (hp > 0) {return true;}
	else {return false;}
}

void Player::doInput(std::string s) {
	// Create 2 new arrays, each to hold a word.
	std::string args[2];
	
	// Put words into arrays
	std::istringstream is1(s);
	is1 >> args[0];
	std::istringstream is2(s);
	is2 >> args[1];
	
	std::cout << "Word 1:" << args[0] << std::endl;
	std::cout << "Word 2:" << args[1] << std::endl;
	// Make the strings lowercase so they can be checked without being case sensitive.
	for (int k = 0; k < 2; k++)
		for (int l = 0; args[k][l] != '\0'; l++ )
			std::tolower(args[k][l]); // Should convert string to lowercase. Have not tested it yet.
	
	std::cout << "Lowercase Word 1:" << args[0] << std::endl;
	// Base input checker, takes the first word and uses the switch to call the needed function
	if (args[0] == "eat") goto eat;
	else if (args[0] == "get") goto get;
	else if (args[0] == "drop") goto drop;
	else if (args[0] == "go") goto go;
	else if (args[0] == "attack") goto attack;
	else if (args[0] == "search") {location->searchRoom(); return;}
	else if (args[0] == "inventory") {checkInventory(); return;}
	else if (args[0] == "health") {showHealth(); return;}
	else if (args[0] == "help") goto help;
	else {std::cout << "Unknown command, use 'help' to view commands.\n"; return;}
	
eat:
	if (args[1] == "0") {eat(0); return;}
	else if (args[1] == "1") {eat(1); return;}
	else if (args[1] == "2") {eat(2); return;}
	else if (args[1] == "3") {eat(3); return;}
	else if (args[1] == "4") {eat(4); return;}
	else if (args[1] == "5") {eat(5); return;}
	else if (args[1] == "6") {eat(6); return;}
	else if (args[1] == "7") {eat(7); return;}
	else if (args[1] == "8") {eat(8); return;}
	else if (args[1] == "9") {eat(9); return;}
	else {std::cout << "Invalid argument for 'eat'.\nValid arguments for 'eat' are numbers 0-9.\n"; return;}
	
get:
	if (args[1] == "0") {get(0); return;}
	else if (args[1] == "1") {get(1); return;}
	else if (args[1] == "2") {get(2); return;}
	else if (args[1] == "3") {get(3); return;}
	else if (args[1] == "4") {get(4); return;}
	else if (args[1] == "5") {get(5); return;}
	else if (args[1] == "6") {get(6); return;}
	else if (args[1] == "7") {get(7); return;}
	else if (args[1] == "8") {get(8); return;}
	else if (args[1] == "9") {get(9); return;}
	else {std::cout << "Invalid argument for 'get'.\nValid arguments for 'get' are numbers 0-9.\n"; return;}
	
drop:
	if (args[1] == "0") {drop(0); return;}
	else if (args[1] == "1") {drop(1); return;}
	else if (args[1] == "2") {drop(2); return;}
	else if (args[1] == "3") {drop(3); return;}
	else if (args[1] == "4") {drop(4); return;}
	else if (args[1] == "5") {drop(5); return;}
	else if (args[1] == "6") {drop(6); return;}
	else if (args[1] == "7") {drop(7); return;}
	else if (args[1] == "8") {drop(8); return;}
	else if (args[1] == "9") {drop(9); return;}
	else {std::cout << "Invalid argument for 'drop'.\nValid arguments for 'drop' are numbers 0-9.\n"; return;}
	
go:
	if (args[1] == "n") {go(0); return;}
	else if (args[1] == "s") {go(1); return;}
	else if (args[1] == "e") {go(2); return;}
	else if (args[1] == "w") {go(3); return;}
	else {std::cout << "Invalid argument for 'go'.\nValid arguments for 'go' are 'n', 's', 'e', and 'w'.\n"; return;}
	
attack:
	if (args[1] == "0") {attack(0); return;}
	else if (args[1] == "1") {attack(1); return;}
	else if (args[1] == "2") {attack(2); return;}
	else if (args[1] == "3") {attack(3); return;}
	else if (args[1] == "4") {attack(4); return;}
	else {std::cout << "Invalid argument for 'attack'.\nValid arguments for 'attack' are numbers 0-4.\n"; return;}
	
help:
	std::cout << "Valid commands are 'eat', 'get', 'drop', 'go', 'attack', 'search', 'inventory', 'health', and 'help'.\n";
	return;
}

///////////
///Room
///////////

Room::Room(std::string n, Room** a, Item** t, Monster** m) {
	name = n;
	adjacent = new Room*[4]; //no more than 4 adjacent rooms
	inventory = new Item*[10];	//no more than 10 items per room
	enemies = new Monster*[5];	//no more than 5 enemies per room
	//if there is an overflow, for loop will handle it
	//construct adjacent rooms
	for( int i = 0; i < 4; i++)
	{
		adjacent[i] = a[i];
	}
	//construct inventory
	for( int j = 0; j < 10; j++)
	{
		inventory[j] = t[j];
	}
	//construct enemies
	for( int k = 0; k < 5; k++)
	{
		enemies[k] = m[k];
	}
}

Room::~Room()
{
	delete [] adjacent;
	delete [] inventory;
	delete [] enemies;
}

void Room::searchRoom() const {
	std::cout << "Items:\n";
	for (int i = 0; i < 10; i++) {
		std::cout << i << ": ";
		if (inventory[i] != NULL) std::cout << inventory[i]->getName() << "\n";
		else std::cout << "Empty\n";
	}
	
	std::cout << "Monsters:\n";
	for (int i = 0; i < 5; i++) {
		std::cout << i << ": ";
		if (enemies[i] != NULL) std::cout << enemies[i]->getName() << "\n";
		else std::cout << "No Enemy\n";
	}
	
	std::cout << "Connected Rooms:\n";
	std::cout << "North: ";
	if (adjacent[0] != NULL) std::cout << adjacent[0]->getName() << "\n";
	else std::cout << "No Passage\n";
	
	std::cout << "South: ";
	if (adjacent[1] != NULL) std::cout << adjacent[1]->getName() << "\n";
	else std::cout << "No Passage\n";
	
	std::cout << "East: ";
	if (adjacent[2] != NULL) std::cout << adjacent[2]->getName() << "\n";
	else std::cout << "No Passage\n";
	
	std::cout << "West: ";
	if (adjacent[3] != NULL) std::cout << adjacent[3]->getName() << "\n";
	else std::cout << "No Passage\n";
}

void Room::give(int x) {
	//This should only be called from get()
	inventory[x] = NULL;
}

void Room::take(int x, Item* y) {
	//This should only be called from drop()
	inventory[x] = y;
}

int Room::nextOpen() const {
	for (int i = 0; i < 10; i++) {
		if ( inventory[i] == NULL ) return i;
	}
	return -1; // No space available
}

Item* Room::atIndex(int x) const {
	return inventory[x];
}

Monster* Room::monsterIndex(int x) const {
	return enemies[x];
}

std::string Room::getName() const {
	return name;
}

Room* Room::getAdjacent(int x) const {
	return adjacent[x];
}

///////////
///Item
///////////
Item::Item(std::string n, int iid)
{
	name = n;
	id = iid;
}

Item::~Item()
{

}

std::string Item::getName() const {
	return name;
}

///////////
///Monster
///////////

/*Monster::Monster(int health, int a, string n, Room* l, Weapon* c) : Player(int health, int a, Room* l, Weapon* c)
{
	name = n;
}*/

Monster::Monster(int health, int a, std::string n) {
	hp = health;
	atk = a;
	name = n;
}

std::string Monster::getName() const {
	return name;
}

void Monster::modifyHealth(int x) {
	hp += x;
}

///////////
///Food
///////////
Food::Food(std::string n, int iid, int v) : Item(n, iid) //call item constructor
{
	val = v;
}

Food::~Food()
{
	
}
int Food::getValue() const {
	return val;
}

///////////
///Weapon
///////////

Weapon::Weapon(std::string n, int iid, int v) : Item(n, iid)
{
	val = v;
}

Weapon::~Weapon()
{
	
}
int Weapon::getValue() const {
	return val;
}
