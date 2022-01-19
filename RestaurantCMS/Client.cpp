#include "Client.h"

void Client::SetName(std::string name)
{
	Name = name;

}

void Client::SetIsOrderForDelivery(bool value)
{
	IsHisOrderForDelivery = value;
}

bool Client::GetIsOrderForDelivery()
{
	return IsHisOrderForDelivery;
}

void Client::SetAddress(std::string address)
{
	Address = address;
}

void Client::AddDishToOrder(Dish dishToAdd)
{
	Orders.push_back(dishToAdd);
}

int Client::GetOrderCount()
{
	return Orders.size();
}

float Client::GetOrderSummedPrice()
{
	float result = 0.0f;
	for (Dish item : Orders)
	{
		result += item.GetDishPrice();
	}
	return result;
}

void Client::SetTableNumber(int number)
{
	TableNumber = number;
}

void Client::SetPrefDeliveryTime(std::string time)
{
	PrefDeliveryTime = time;
}

std::vector<Dish> Client::GetOrders()
{
	return Orders;
}
std::string Client::GetDeliveryTime()
{
	return PrefDeliveryTime;
}
std::string Client::GetDeliveryAdress()
{
	return Address;
}