#include <iostream>
#include <string>
#pragma once

// Item Classes
class Item //items are things that the player can add to inventory. Some points in game may check inventory to see if player has that item.
{
	public:
		Item(std::string,int);
		~Item();
		std::string getName() const;
	private:
		std::string name;
		int id;
};

//derived classes

class Food : public Item //food will restore player health
{
	public:
		Food(std::string n, int iid, int v); //calls item constructor
		~Food();
		int getValue() const;
	private:
		int val; //amount of hit points you will recover
};

class Weapon : public Item //temporarily boosts player attack. player cannot have more than one
{
	public:
		Weapon(std::string n, int iid, int v); //calls item constructor
		~Weapon();
		int getValue() const;
	private:
		int val; //attack stat increase
};
