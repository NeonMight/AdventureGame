#include <iostream>
#include <string>
#pragma once

//Monster Class
class Monster //monsters will attack player if player is in same room. Player cannot use go if monsters are present.
{
	public:
		//Monster(int health, int a, string n, Room* l, Weapon* c); //will call player constructor with same parameters
		Monster(int health, int a, std::string n); // Monster constructor
		~Monster();
		std::string getName() const;
		void modifyHealth(int);
	private:
		int atk; // Attack damage
		int hp; // Hit points
		std::string name;
};
