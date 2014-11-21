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
	Room r1("an alleyway",r1i,r1m);
	
	Item* r2i[] = {NULL,&w1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	Monster* r2m[] = {NULL,&m2,NULL,&m1,NULL};
	Room r2("a courtyard",r2i,r2m);
	
	Item* r3i[] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&f1,NULL};
	Monster* r3m[] = {NULL,NULL,NULL,NULL,NULL};
	Room r3("a bathroom",r3i,r3m);
	
	Item* r4i[] = {NULL,NULL,NULL,&f4,NULL,NULL,&a2,NULL,NULL,NULL};
	Monster* r4m[] = {NULL,NULL,NULL,NULL,&m4};
	Room r4("a garden",r4i,r4m);
	
	Item* r5i[] = {NULL,NULL,NULL,&a3,NULL,NULL,NULL,NULL,&w2,NULL};
	Monster* r5m[] = {NULL,NULL,&m3,NULL,NULL};
	Room r5("a hidden tunnel",r5i,r5m);
	
	Item* r6i[] = {NULL,NULL,NULL,&f2,NULL,NULL,&w3,NULL,NULL,NULL};
	Monster* r6m[] = {NULL,NULL,NULL,NULL,NULL};
	Room r6("a kitchen",r6i,r6m);
	
	Item* r7i[] = {NULL,NULL,&f3,NULL,NULL,NULL,&a4,NULL,NULL,NULL};
	Monster* r7m[] = {NULL,NULL,NULL,NULL,&m5};
	Room r7("a hazy passageway",r7i,r7m);
	
	Item* r8i[] = {NULL,&w4,NULL,NULL,NULL,&f6,NULL,NULL,NULL,NULL};
	Monster* r8m[] = {NULL,&m6,NULL,NULL,NULL};
	Room r8("a damp corridor",r8i,r8m);
	
	Item* r9i[] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	Monster* r9m[] = {NULL,NULL,NULL,NULL,NULL};
	Room r9("a dimly lit room",r9i,r9m);
	
	Item* r10i[] = {NULL,NULL,&w5,NULL,NULL,&a5,NULL,NULL,NULL,NULL};
	Monster* r10m[] = {&m7,NULL,&m8,NULL,NULL};
	Room r10("a dusty hallway",r10i,r10m);
	
	Item* r11i[] = {NULL,NULL,&f7,NULL,NULL,&a6,NULL,NULL,NULL,NULL};
	Monster* r11m[] = {NULL,NULL,NULL,NULL,NULL};
	Room r11("the rest room",r11i,r11m);
	
	Item* r12i[] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	Monster* r12m[] = {NULL,NULL,NULL,NULL,NULL};
	Room r12("the boss room",r12i,r12m);
	
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
	
	Room* r6a[] = {NULL,&r5,NULL,&r7};
	r6.addAdjacent(r6a);
	
	Room* r7a[] = {&r8,NULL,&r6,NULL};
	r7.addAdjacent(r7a);
	
	Room* r8a[] = {NULL,&r7,NULL,&r9};
	r8.addAdjacent(r8a);
	
	Room* r9a[] = {NULL,NULL,&r8,&r10};
	r9.addAdjacent(r9a);
	
	Room* r10a[] = {&r11,NULL,&r9,NULL};
	r10.addAdjacent(r10a);
	
	Room* r11a[] = {&r12,&r10,NULL,NULL};
	r11.addAdjacent(r11a);
	
	Room* r12a[] = {NULL,NULL,NULL,NULL};
	r12.addAdjacent(r12a);
	
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
