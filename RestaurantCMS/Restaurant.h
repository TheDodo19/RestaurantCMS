#pragma once
#include <string>
class Restaurant
{
private:
	int Id;
	std::string Description;
	std::string Address;
	std::string Name;
public:
	void setRestaurantId(int id);
	std::string getRestaurantId();
	std::string getRestaurantName();
	Restaurant(std::string name, std::string address, std::string description);
	std::string PrintRestaurantData(std::string);
};

