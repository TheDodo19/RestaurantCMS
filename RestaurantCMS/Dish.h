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
	Dish();
	float GetDishPrice();
	void SetDishId(std::string id);
	void SetDishId(int id);
	void SetPrice(std::string price);
	void SetPrice(float price);
	void SetIngredients();
	void SetName(std::string name);
};

