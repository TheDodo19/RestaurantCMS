#include "Restaurant.h"

void Restaurant::setRestaurantId(int)
{
	
}

std::string Restaurant::getRestaurantId()
{
	std::string x = std::to_string(Id);
	return x;
}



std::string Restaurant::getRestaurantName()
{
	return Name;
}

Restaurant::Restaurant(std::string name, std::string address, std::string description)
{
	this->Name = name;
	this->Address = address;
	this->Description = description;
}

std::string Restaurant::PrintRestaurantData(std::string Prefix ="")
{
	std::string data = Prefix + " " + Name + " " + Address + " " + Description;
	return data;
}
