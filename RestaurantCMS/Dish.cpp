#include "Dish.h"

Dish::Dish(int id, std::string name, std::string ingredients, float price) {
    this-> DishId = id; 
    this-> Name = name;
    this-> Ingredients = ingredients;
    this-> Price = price;
}