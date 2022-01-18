#include <string>
#pragma once
class Dish
{
private:
	int DishId;
	float Price;
	std::string Ingredients;
	std::string Name;
public:
	Dish(int id, std::string name, std::string ingredients, float price);
	Dish();
	float GetDishPrice();
	void SetDishId(std::string id);
	void SetDishId(int id);
	void SetPrice(std::string price);
	void SetPrice(float price);
	void SetIngredients(std::string ingredients);
	void SetName(std::string name);
	void PrintDishAsMenu();
	int GetDishId();
};

