#include "Dish.h"
#include <iostream>
Dish::Dish(int id, std::string name, std::string ingredients, float price) {
	this->DishId = id;
	this->Name = name;
	this->Ingredients = ingredients;
	this->Price = price;
}

Dish::Dish()
{
	DishId = 0;
	Price = 0;
	Ingredients = "";
	Name = "";
}

float Dish::GetDishPrice()
{
	return Price;
}

void Dish::SetDishId(std::string id)
{
	DishId = atoi(id.c_str());
}

void Dish::SetDishId(int id)
{
	DishId = id;
}

void Dish::SetPrice(std::string price)
{
	Price = std::stof(price);
}

void Dish::SetPrice(float price)
{
	Price = price;
}

void Dish::SetIngredients(std::string ingredients)
{
	Ingredients = ingredients;
}

void Dish::SetName(std::string name)
{
	Name = name;
}

void Dish::PrintDishAsMenu()
{
	std::cout << "Numer dania: " << DishId << " Nazwa: " << Name << " " << "Cena: " << Price << "zl " << "Skladniki: " << Ingredients << " " << std::endl;
}

int Dish::GetDishId()
{
	return DishId;
}
std::string Dish::GetDishToBill()
{
	return " Nazwa: " + Name + " " + "Cena: " + std::to_string(Price) + "zl " + "\n";
}