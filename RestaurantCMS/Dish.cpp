#include "Dish.h"

Dish::Dish(int id, std::string name, std::string ingredients, float price) {
    this-> DishId = id; 
    this-> Name = name;
    this-> Ingredients = ingredients;
    this-> Price = price;
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
    DishId=atoi(id.c_str());
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

void Dish::SetIngredients()
{
    Ingredients = "TODO LIST OF INGREDIENTS";
}

void Dish::SetName(std::string name)
{
    Name = name;
}
