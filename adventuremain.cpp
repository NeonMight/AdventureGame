// Version 1.0
// Created by Stephen Hoffman, Ethan Waddle, & Justin McAlister

#include "player.h"
#include "room.h"
#include <iostream>
#include <string> 
using namespace std;

int main() {
	string input;
	bool attackturn = false;
	
	//Initializations
	// Test items
	Item t1("The Holy Grail",1,10000); // When we start to make enemies fight back, we'll want this for testing
	// Food
	Item f1("Apple",1,5);
	Item f2("Orange",1,5);
	Item f3("Healing Potion",1,20);
	Item f4("Strange Berries",1,-5);
	Item f5("Strange Mushroom",1,-100);
	Item f6("Loaf of bread",1,25);
	Item f7("Magic Powder",1,100);
	// Weapons
	Item w1("Wooden Staff",2,5);
	Item w2("Iron Sword",2,10);
	Item w3("Giant Hammer",2,20);
	Item w4("Fire sword",2,30);
	Item w5("Legendary Sword",2,50);
	// Armor
	Item a1("Paper Armor",3,0.05);
	Item a2("Steel Armor",3,0.25);
	Item a3("Bronze Armor",3,0.5);
	Item a4("Silver Armor",3,0.6);
	Item a5("Gold Armor",3,0.7);
	Item a6("Diamond Armor",3,0.8);
	
	// Monsters
	Monster m1(50,3,"Territorial Oak");
	Monster m2(40,2,"Zombie");
	Monster m3(20,5,"Goblin");
	Monster m4(100,5,"Giant Snake");
	Monster m5(80,4,"Smelly Ghost");
	Monster m6(90,4,"Rowdy Mouse");
	Monster m7(60,3,"Saibamen");
	Monster m8(10,2,"No Emenies");
	Monster m9(400,30,"Titanic Ant");
	
	// Rooms
	Item* r1i[] = {&a1,NULL,&f3,NULL,NULL,NULL,NULL,NULL,&t1,NULL};
	Monster* r1m[] = {NULL,NULL,NULL,NULL,NULL};
	Room r1("A Drainage Pipe",r1i,r1m);
	
	Item* r2i[] = {NULL,&w1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	Monster* r2m[] = {NULL,&m2,NULL,&m1,NULL};
	Room r2("A Hazy Passageway",r2i,r2m);
	
	Item* r3i[] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&f1,NULL};
	Monster* r3m[] = {NULL,NULL,NULL,NULL,NULL};
	Room r3("A Bathroom",r3i,r3m);
	
	Item* r4i[] = {NULL,NULL,NULL,&f4,NULL,NULL,&a2,NULL,NULL,NULL};
	Monster* r4m[] = {NULL,NULL,NULL,NULL,&m4};
	Room r4("A Garden",r4i,r4m);
	
	Item* r5i[] = {NULL,NULL,NULL,&a3,NULL,NULL,NULL,NULL,&w2,NULL};
	Monster* r5m[] = {NULL,NULL,&m3,NULL,NULL};
	Room r5("A Hidden Tunnel",r5i,r5m);
	
	Item* r6i[] = {NULL,NULL,NULL,&f2,NULL,NULL,&w3,NULL,NULL,NULL};
	Monster* r6m[] = {NULL,NULL,NULL,NULL,NULL};
	Room r6("A Kitchen",r6i,r6m);
	
	// Adjacent Rooms
	Room* r1a[] = {NULL,&r2,NULL,NULL};
	r1.addAdjacent(r1a);
	
	Room* r2a[] = {&r1,&r3,&r4,NULL};
	r2.addAdjacent(r2a);
	
	Room* r3a[] = {&r2,NULL,NULL,NULL};
	r3.addAdjacent(r3a);
	
	Room* r4a[] = {NULL,NULL,&r5,&r2};
	r4.addAdjacent(r4a);
	
	Room* r5a[] = {&r6,NULL,NULL,&r4};
	r5.addAdjacent(r5a);
	
	Room* r6a[] = {NULL,&r5,NULL,NULL};
	r6.addAdjacent(r6a);
	
	// Player
	Player p(100,5,&r1);

	// Game loop
	// Flow: Ask for user input, player does action, if monsters are present, they attack, repeat.
	cout << "Welcome!\n";
	while (p.isAlive()) { // Continue looping while the player is alive
		cout << "Input Command: ";
		getline(cin,input);
		attackturn = p.doInput(input); // This function will convert user input into a function call. All game output will be from a function called from here.
		if (attackturn == true) {p.battle();}
		cout << "\n";
	}
	cout << "You died!\n"; // Game over
}
