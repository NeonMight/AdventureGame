#include "player.h"
#include "room.h"
#include "item.h"
#include "monster.h"
#include <iostream>
#include <string> 
#include <cstdlib>
#include <ctime>

///////////
///Player
///////////

Player::Player(int health, int a, Room* l)
{
	hp = health;
	defaultatk = a;
	atk = defaultatk;
	defense = 0;
	location = l;
	inventory = new Item*[10];
	for (int i = 0; i < 10; i++) {
		inventory[i] = NULL;
	}
	currentwep = -1;
	gear = -1;
}

Player::~Player()
{
	delete [] inventory;
}

void Player::go(int x) {
	if (location->getAdjacent(x) == NULL) { std::cout << "No passage in this direction.\n"; return; }
	location = location->getAdjacent(x);
	switch (x) {
		case 0: std::cout << "You have moved north.\n"; break;
		case 1: std::cout << "You have moved south.\n"; break;
		case 2: std::cout << "You have moved east.\n"; break;
		case 3: std::cout << "You have moved west.\n"; break;
		default: return;
	}
	
	std::cout << "You have entered " << location->getName() << ".\n";
	
	std::cout << "Connected Rooms:\n";
	std::cout << "North: ";
	if (location->getAdjacent(0) != NULL) {std::cout << location->getAdjacent(0)->getName() << "\n";}
	else std::cout << "No Passage\n";
	
	std::cout << "South: ";
	if (location->getAdjacent(1) != NULL) {std::cout << location->getAdjacent(1)->getName() << "\n";}
	else std::cout << "No Passage\n";
	
	std::cout << "East: ";
	if (location->getAdjacent(2) != NULL) {std::cout << location->getAdjacent(2)->getName() << "\n";}
	else std::cout << "No Passage\n";
	
	std::cout << "West: ";
	if (location->getAdjacent(3) != NULL) {std::cout << location->getAdjacent(3)->getName() << "\n";}
	else std::cout << "No Passage\n";
	
	std::cout << "Enemies Here:\n";
	for (int i = 0; i < 5; i++) {
		if (location->monsterIndex(i) != NULL) std::cout << i <<": " << location->monsterIndex(i)->getName() << "\n";
	}
}

void Player::get(int x) {
	int i = nextOpen(); // Get next open spot
	if ( i == -1 ) { std::cout << "There is no space in your inventory.\n"; return; } // If no spot available, return
	if (location->atIndex(x) == NULL) {std::cout << "No item in this position\n";return;}
	std::cout << "You picked up " << location->atIndex(x)->getName() << ".\n";
	inventory[i] = location->atIndex(x); // Give the item to the inventory
	location->give(x); // Take from room's inventory
}


void Player::eat(int x) {
	if (inventory[x] == NULL) {std::cout << "No item at this index.\n"; return;}
	if (inventory[x]->getID() != 1) {std::cout << "This item is not food.\n"; return;}
	int v = inventory[x]->getValue(); // Get healing value
	modifyHealth(v); // Add to health
	inventory[x] = NULL; // Open space in inventory
}

void Player::drop(int x) {
	if (inventory[x] == NULL) {std::cout << "No item in this space.\n"; return;}
	int i = location->nextOpen();
	if (i == -1) {std::cout << "No space in the room.\n"; return;}
	std::cout << "You dropped " << inventory[x]->getName() << ".\n";
	location->take(i,inventory[x]);
	inventory[x] = NULL;
	if (inventory[currentwep] == NULL) {currentwep = -1; atk = defaultatk;}
	if (inventory[gear] == NULL) {gear = -1; defense = 0;}
}

void Player::attack(int x) {
	Monster* m = location->monsterIndex(x);
	if ( m == NULL ) { std::cout << "No enemy in this position.\n"; return; }
	// Generate random number for damage
	srand( time(NULL) );
	int r = (rand() % atk) - (atk/2);
	// Modify enemy health, determine if attack kills
	m->modifyHealth(r-atk);
	std::cout << "You attacked " << m->getName() << " for " << -1 * (r - atk) << " hit points.\n";
	if (m->getHealth() <= 0) {std::cout << "You killed " << m->getName() << ".\n"; location->kill(x); return;}
	std::cout << m->getName() << " now has " << m->getHealth() << " HP.\n";
}

void Player::weapon(int x) {
	if (inventory[x] == NULL) {std::cout << "No item at this index.\n"; return;}
	if (inventory[x]->getID() != 2) {std::cout << "This item is not a weapon.\n"; return;}
	currentwep = x;
	atk = defaultatk + inventory[currentwep]->getValue();
	std::cout << "You have equipped "<< inventory[currentwep]->getName() << ".\n";
	std::cout << "Your attack value is now " << atk << ".\n";
}

void Player::armor(int x) {
	if (inventory[x] == NULL) {std::cout << "No item at this index.\n"; return;}
	if (inventory[x]->getID() != 3) {std::cout << "This item is not armor.\n"; return;}
	gear = x;
	defense = inventory[gear]->getValue();
	std::cout << "You have equipped "<< inventory[gear]->getName() << ".\n";
	std::cout << "Your defense value is now " << defense << ".\n";
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
	std::cout << "Weapon: ";
	if (currentwep == -1) {std::cout << "None\n";}
	else {std::cout << inventory[currentwep]->getName() << "\n";}
	std::cout << "Armor: ";
	if (gear == -1) {std::cout << "None\n";}
	else {std::cout << inventory[gear]->getName() << "\n";}
}

void Player::modifyHealth(int x) {
	hp += x;
	std::cout << "You have ";
	if (x > 0) {std::cout << "gained " << x;}
	else {std::cout << "lost " << -x;}
	std::cout << " health.\n";
	showHealth();
}

void Player::showHealth() const {
	std::cout << "Your current health is " << hp << ".\n";
}

bool Player::isAlive() const {
	if (hp > 0) {return true;}
	else {return false;}
}

bool Player::doInput(std::string s) {
	// Create 2 new arrays, each to hold a word.
	std::string args[2];
	
	// Put words into arrays
	int divisionpoint = s.find(" ");
	args[0] = s.substr(0,divisionpoint);
	args[1] = s.substr(divisionpoint+1);
	
	// Make the strings lowercase so they can be checked without being case sensitive.
	for (int i = 0; i < 16; i++) {if (args[0][i] <='Z' && args[0][i]>='A') args[0][i] -= ('Z'-'z');} // Convert string to lowercase.
	for (int i = 0; i < 16; i++) {if (args[1][i] <='Z' && args[1][i]>='A') args[1][i] -= ('Z'-'z');} // Convert string to lowercase.
	
	// Base input checker, takes the first word and uses the switch to call the needed function
	if (args[0] == "eat") goto eat;
	else if (args[0] == "get") goto get;
	else if (args[0] == "drop") goto drop;
	else if (args[0] == "go") goto go;
	else if (args[0] == "attack") goto attack;
	else if (args[0] == "search") {location->searchRoom(); return false;}
	else if (args[0] == "inventory") {checkInventory(); return false;}
	else if (args[0] == "health") {showHealth(); return false;}
	else if (args[0] == "weapon") goto weapon;
	else if (args[0] == "armor") goto armor;
	else if (args[0] == "suicide") {suicide(); return false;}
	else if (args[0] == "help") goto help;
	else {std::cout << "Unknown command, use 'help' to view commands.\n"; return false;}
	
eat:
	if (args[1] == "0") {eat(0); return true;}
	else if (args[1] == "1") {eat(1); return true;}
	else if (args[1] == "2") {eat(2); return true;}
	else if (args[1] == "3") {eat(3); return true;}
	else if (args[1] == "4") {eat(4); return true;}
	else if (args[1] == "5") {eat(5); return true;}
	else if (args[1] == "6") {eat(6); return true;}
	else if (args[1] == "7") {eat(7); return true;}
	else if (args[1] == "8") {eat(8); return true;}
	else if (args[1] == "9") {eat(9); return true;}
	else {std::cout << "Invalid argument for 'eat'.\nValid arguments for 'eat' are numbers 0-9.\n"; return false;}
	
get:
	if (args[1] == "0") {get(0); return true;}
	else if (args[1] == "1") {get(1); return true;}
	else if (args[1] == "2") {get(2); return true;}
	else if (args[1] == "3") {get(3); return true;}
	else if (args[1] == "4") {get(4); return true;}
	else if (args[1] == "5") {get(5); return true;}
	else if (args[1] == "6") {get(6); return true;}
	else if (args[1] == "7") {get(7); return true;}
	else if (args[1] == "8") {get(8); return true;}
	else if (args[1] == "9") {get(9); return true;}
	else {std::cout << "Invalid argument for 'get'.\nValid arguments for 'get' are numbers 0-9.\n"; return false;}
	
drop:
	if (args[1] == "0") {drop(0); return true;}
	else if (args[1] == "1") {drop(1); return true;}
	else if (args[1] == "2") {drop(2); return true;}
	else if (args[1] == "3") {drop(3); return true;}
	else if (args[1] == "4") {drop(4); return true;}
	else if (args[1] == "5") {drop(5); return true;}
	else if (args[1] == "6") {drop(6); return true;}
	else if (args[1] == "7") {drop(7); return true;}
	else if (args[1] == "8") {drop(8); return true;}
	else if (args[1] == "9") {drop(9); return true;}
	else {std::cout << "Invalid argument for 'drop'.\nValid arguments for 'drop' are numbers 0-9.\n"; return false;}
	
go:
	if (args[1] == "n") {go(0); return true;}
	else if (args[1] == "s") {go(1); return true;}
	else if (args[1] == "e") {go(2); return true;}
	else if (args[1] == "w") {go(3); return true;}
	else {std::cout << "Invalid argument for 'go'.\nValid arguments for 'go' are 'n', 's', 'e', and 'w'.\n"; return false;}
	
attack:
	if (args[1] == "0") {attack(0); return true;}
	else if (args[1] == "1") {attack(1); return true;}
	else if (args[1] == "2") {attack(2); return true;}
	else if (args[1] == "3") {attack(3); return true;}
	else if (args[1] == "4") {attack(4); return true;}
	else {std::cout << "Invalid argument for 'attack'.\nValid arguments for 'attack' are numbers 0-4.\n"; return false;}

weapon:
	if (args[1] == "0") {weapon(0); return true;}
	else if (args[1] == "1") {weapon(1); return true;}
	else if (args[1] == "2") {weapon(2); return true;}
	else if (args[1] == "3") {weapon(3); return true;}
	else if (args[1] == "4") {weapon(4); return true;}
	else if (args[1] == "5") {weapon(5); return true;}
	else if (args[1] == "6") {weapon(6); return true;}
	else if (args[1] == "7") {weapon(7); return true;}
	else if (args[1] == "8") {weapon(8); return true;}
	else if (args[1] == "9") {weapon(9); return true;}
	else {std::cout << "Invalid argument for 'weapon'.\nValid arguments for 'weapon' are numbers 0-9.\n"; return false;}
	
armor:
	if (args[1] == "0") {armor(0); return true;}
	else if (args[1] == "1") {armor(1); return true;}
	else if (args[1] == "2") {armor(2); return true;}
	else if (args[1] == "3") {armor(3); return true;}
	else if (args[1] == "4") {armor(4); return true;}
	else if (args[1] == "5") {armor(5); return true;}
	else if (args[1] == "6") {armor(6); return true;}
	else if (args[1] == "7") {armor(7); return true;}
	else if (args[1] == "8") {armor(8); return true;}
	else if (args[1] == "9") {armor(9); return true;}
	else {std::cout << "Invalid argument for 'armor'.\nValid arguments for 'armor' are numbers 0-9.\n"; return false;}
	
help:
	std::cout << "Valid commands are 'eat', 'get', 'drop', 'go', 'attack', 'search', 'inventory', 'health', 'weapon', 'armor', 'suicide', and 'help'.\n";
	return false;
}

std::string Player::getCurrentLocation() const
{
	return location->getName();
}

void Player::battle() {
	int x = 0;
	int r;
	int a;
	srand( time(NULL) );
	for (int i = 0; i < 5; i++) {
		if (location->monsterIndex(i) != NULL) {
			a = location->monsterIndex(i)->getAttack();
			r = ( (rand() % (a/2)) - (a/4) ) + 0.5;
			x += a + r;
		}
	}
	if (x == 0) {return;}
	std::cout << "\nYou were attacked by enemies.\n";
	x = (int)((1-defense)*x);
	modifyHealth(-x);
}

void Player::suicide() {
	std::cout << "You have banged your head against the ground until you died.\n";
	hp = 0;
}

///////////
///Room
///////////

Room::Room(std::string n, Item** t, Monster** m) {
	name = n;
	adjacent = new Room*[4]; //no more than 4 adjacent rooms
	inventory = new Item*[10];	//no more than 10 items per room
	enemies = new Monster*[5];	//no more than 5 enemies per room
	//if there is an overflow, for loop will handle it
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
	std::cout << "Room: " << name << "\n";
	std::cout << "Items:\n";
	for (int i = 0; i < 10; i++) {
		std::cout << i << ": ";
		if (inventory[i] != NULL) std::cout << inventory[i]->getName() << "\n";
		else std::cout << "Empty\n";
	}
	
	std::cout << "Monsters:\n";
	for (int i = 0; i < 5; i++) {
		std::cout << i << ": ";
		if (enemies[i] != NULL) std::cout << enemies[i]->getName() << "(" << enemies[i]->getHealth() << " HP)\n";
		else std::cout << "No Enemy\n";
	}
	
	std::cout << "Connected Rooms:\n";
	std::cout << "North: ";
	if (adjacent[0] != NULL) {std::cout << adjacent[0]->getName() << "\n";}
	else std::cout << "No Passage\n";
	
	std::cout << "South: ";
	if (adjacent[1] != NULL) {std::cout << adjacent[1]->getName() << "\n";}
	else std::cout << "No Passage\n";
	
	std::cout << "East: ";
	if (adjacent[2] != NULL) {std::cout << adjacent[2]->getName() << "\n";}
	else std::cout << "No Passage\n";
	
	std::cout << "West: ";
	if (adjacent[3] != NULL) {std::cout << adjacent[3]->getName() << "\n";}
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

void Room::kill(int x) {
	//This should only be called from attack()
	enemies[x] = NULL;
}

void Room::addAdjacent(Room** r)
{
	for( int i = 0; i < 4; i++)
	{
		adjacent[i] = r[i];
	}
}

///////////
///Item
///////////
Item::Item(std::string n, int iid, float v)
{
	name = n;
	id = iid;
	val = v;
}

std::string Item::getName() const {
	return name;
}

float Item::getValue() const {
	return val;
}

int Item::getID() const {
	return id;
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

int Monster::getHealth() const{
	return hp;
}

int Monster::getAttack() const{
	return atk;
}

bool Monster::isAlive() const {
	if (hp > 0) {return true;}
	else {return false;}
}
