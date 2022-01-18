#include <vector>
#include "Order.h"
#include <string>
#include "Dish.h"
class Client
{
private:
	int Id;
	int TableNumber;
	bool IsHisOrderForDelivery;
	std::string Address;
	std::string Name;
	std::vector<Dish> Orders;
public:
	void SetName(std::string name);
	void SetIsOrderForDelivery(bool value);
	bool GetIsOrderForDelivery();
	void SetAddress(std::string address);
	void AddDishToOrder(Dish dishToAdd);
	int GetOrderCount();
	float GetOrderSummedPrice();
	void SetTableNumber(int number);
};
