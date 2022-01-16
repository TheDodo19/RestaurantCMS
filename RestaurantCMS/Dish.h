#include <string>

class Dish
{
private:
	int DishId;
    float Price;
	std::string Ingredients;
	std::string Name;
public:
    Dish(int id, std::string name, std::string ingredients, float price);
};

