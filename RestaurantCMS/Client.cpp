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
