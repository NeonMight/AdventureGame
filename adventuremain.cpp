// Version 2.0
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
	
	//Test Items
	Item t1("Healing herb",1,30); // When we start to make enemies fight back, we'll want this for testing
	//Item t1("H4X0R 4rm0r",3,2); // Heal damage taken instead...
	//Food
	Item f1("Apple",1,5);
	Item f2("Orange",1,5);
	Item f3("Healing Potion",1,20);
	Item f4("Strange Berries",1,-5);
	Item f5("Strange Mushroom",1,-100);
	Item f6("Loaf of Bread",1,25);
	Item f7("Magic Powder",1,100);
	Item f8("Sandwich",1,15);
	Item f9("Pear",1,10);
	Item f10("Banana",1,15);
	Item f11("Pork n Beans",1,40);
	Item f12("Can o Spam",1,50);
	Item f13("Hotdog Buns",1,25);
	Item f14("Ice Cream",1,50);
	Item f15("Pizza",1,40);
	// Weapons
	Item w1("Wooden Staff",2,5);
	Item w2("Iron Sword",2,20);
	Item w3("Giant Hammer",2,30);
	Item w4("Fire Sword",2,40);
	Item w5("Legendary Sword",2,50);
	Item w6("Holy Lance",2,120);
	// Armor
	Item a1("Wooden Armor",3,0.07);
	Item a2("Steel Armor",3,0.1);
	Item a3("Bronze Armor",3,0.3);
	Item a4("Silver Armor",3,0.4);
	Item a5("Gold Armor",3,0.5);
	Item a6("Diamond Armor",3,0.7);
	
	// Monsters
	Monster m1(50,3,"Territorial Oak");
	Monster m2(40,2,"Attack Slug");
	Monster m3(20,5,"Putrid Moldyman");
	Monster m4(100,5,"Very Large Snake");
	Monster m5(80,4,"Smelly Ghost");
	Monster m6(90,4,"Rowdy Mouse");
	Monster m7(60,8,"Mobile Sprout");
	Monster m8(100,7,"Spiteful Crow");
	Monster m9(110,10,"Great Grey Wolf");
	Monster m10(120,12,"Bear on Fire");
	Monster m11(100,10,"Horned Beast");
	Monster m12(140,15,"Blue Phantom");
	Monster m13(200,60,"Shattered Man");
	Monster m14(500,50,"Dark Spirit");
	
	Monster* finalboss = &m14;
	
	// Rooms
	Item* r1i[] = {&a1,NULL,&f3,NULL,NULL,NULL,NULL,NULL,&t1,NULL};
	Monster* r1m[] = {NULL,NULL,NULL,NULL,NULL};
	Room r1("an alleyway",r1i,r1m);
	
	Item* r2i[] = {NULL,&w1,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	Monster* r2m[] = {NULL,&m2,NULL,&m1,NULL};
	Room r2("a courtyard",r2i,r2m);
	
	Item* r3i[] = {&f8,&f9,&f10,NULL,NULL,NULL,NULL,NULL,&f1,NULL};
	Monster* r3m[] = {NULL,NULL,NULL,NULL,NULL};
	Room r3("a bathroom",r3i,r3m);
	
	Item* r4i[] = {NULL,NULL,NULL,&f4,NULL,NULL,&a2,NULL,NULL,NULL};
	Monster* r4m[] = {NULL,NULL,NULL,NULL,&m4};
	Room r4("a garden",r4i,r4m);
	
	Item* r5i[] = {NULL,NULL,NULL,&a3,NULL,NULL,NULL,NULL,&w2,NULL};
	Monster* r5m[] = {NULL,NULL,&m3,NULL,NULL};
	Room r5("a hidden tunnel",r5i,r5m);
	
	Item* r6i[] = {&f11,NULL,&f14,&f2,&f13,NULL,&w3,&f12,&f14,NULL};
	Monster* r6m[] = {NULL,NULL,&m9,NULL,NULL};
	Room r6("a kitchen",r6i,r6m);
	
	Item* r7i[] = {NULL,NULL,&f3,NULL,NULL,NULL,&a4,NULL,NULL,NULL};
	Monster* r7m[] = {NULL,&m10,NULL,NULL,&m5};
	Room r7("a hazy passageway",r7i,r7m);
	
	Item* r8i[] = {NULL,&w4,NULL,NULL,NULL,&f6,NULL,NULL,NULL,NULL};
	Monster* r8m[] = {NULL,&m6,NULL,NULL,NULL};
	Room r8("a damp corridor",r8i,r8m);
	
	Item* r9i[] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	Monster* r9m[] = {&m12,NULL,NULL,NULL,NULL};
	Room r9("a dimly lit room",r9i,r9m);
	
	Item* r10i[] = {NULL,NULL,&w5,NULL,NULL,&a5,NULL,NULL,NULL,NULL};
	Monster* r10m[] = {&m7,NULL,&m8,&m11,NULL};
	Room r10("a dusty hallway",r10i,r10m);
	
	Item* r11i[] = {NULL,NULL,&f7,NULL,NULL,&a5,NULL,NULL,NULL,NULL};
	Monster* r11m[] = {NULL,NULL,NULL,NULL,NULL};
	Room r11("rest point",r11i,r11m);
	
	Item* r12i[] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
	Monster* r12m[] = {NULL,NULL,&m14,NULL,NULL};
	Room r12("the dark chamber",r12i,r12m);
	
	Item* r13i[] = {NULL,&w6,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&a6};
	Monster* r13m[] = {&m13,NULL,NULL,NULL,NULL};
	Room r13("sacred place",r13i,r13m);
	
	// Adjacent Rooms
	Room* r1a[] = {NULL,&r2,NULL,NULL};
	r1.addAdjacent(r1a);
	
	Room* r2a[] = {&r1,&r3,&r4,NULL};
	r2.addAdjacent(r2a);
	
	Room* r3a[] = {&r2,NULL,NULL,NULL};
	r3.addAdjacent(r3a);
	
	Room* r4a[] = {NULL,NULL,&r5,&r2};
	r4.addAdjacent(r4a);
	
	Room* r5a[] = {&r6,NULL,&r13,&r4};
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
	
	Room* r13a[] = {NULL,NULL,NULL,&r5};
	r13.addAdjacent(r13a);
	
	// Player
	Player p(100,5,&r1);
	
	// Game loop
	// Flow: Ask for user input, player does action, if monsters are present, they attack, repeat.
	
	cout<<"Welcome hero!\n";
	cout<< "Choose your class:\n assassin   paladin   ulfheidinn berserker black_knight\n If you enter anything different, you will start off with base health, armor and damage.\n";
	
	cout << "As an assassin, you strike with deadly accuracy to the enemy's critical points, granting +20 damage.  You move swiftly and evasively, taking 1 percent less damage.\n";
	cout << "As a paladin, your strong constitution grants +50 health; your advanced musculature allows you to shrug off minor wonds, taking 10 percent less of it.\n";	
	cout << "A warrior who has slain a wolf with their bare hands, the ulfheidinn strikes with terrible fury, adding +10 damage to any attack.  The wolf pelt you wear into battle grants 5 percent damage protection.\n";
	cout << "The elite frontline spearhead of any Viking invasion, the berserker slays bears with no weapons other than his own fearsome strength, with +15 damage; your highly durable bearhide shirt protects you from 6 percent of damage.\n";
	cout << "With no great weapon prowess, but +150 health, the Black Knight fights on when all others would yield.  Blows that would maim a sane person, are to you mere flesh wounds.\n";

	string classChoice;
	cin>>classChoice;
	
	if(classChoice=="assassin")p.chooseClass(0,20,0.01);
	else if(classChoice=="paladin")p.chooseClass(50,0,0.1);
	else if(classChoice=="ulfheidinn")p.chooseClass(0,10,0.05);
	else if(classChoice=="berserker")p.chooseClass(0,15,0.06);
	else if(classChoice=="black_knight")p.chooseClass(150,0,0);
	else p.chooseClass(0,0,0);

	cout<<"\n";
	
	while (p.isAlive() && finalboss->isAlive()) { // Continue looping while the player is alive and the final boss is alive
		cout << "\nInput Command: ";
		getline(cin,input);
		attackturn = p.doInput(input); // This function will convert user input into a function call. All game output will be from a function called from here.
		if (attackturn == true) {p.battle();}
	}
	if (p.isAlive() == false) {cout << "You died!\n"; return 0;} // Game over
	if (finalboss->isAlive() == false) {cout << "Congratulations!\nYou defeated the final boss!\n"; return 0;}
}
