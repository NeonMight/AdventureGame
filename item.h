#include <iostream>
#include <string>
#pragma once

// Item Classes
class Item //items are things that the player can add to inventory. Some points in game may check inventory to see if player has that item.
{
	public:
		Item(std::string,int,int);
		~Item();
		std::string getName() const;
		int getValue() const;
	private:
		std::string name;
		int id; // 0 = None, 1 = Food, 2 = Weapon
		int val; // Value for food or weapon
};
