#include "Client.h"

void Client::SetName(std::string name)
{
	Name = name;
}

void Client::SetIsOrderForDelivery(bool value)
{
}

bool Client::GetIsOrderForDelivery()
{
	return IsHisOrderForDelivery;
}
