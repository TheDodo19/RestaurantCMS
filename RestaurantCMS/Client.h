#include <list>
#include "Order.h"
#include <string>
class Client
{
private:
	int Id;
	bool IsHisOrderForDelivery;
	std::string Address;
	std::string Name;
	std::list<Order> Orders;
public:
	void SetName(std::string name);
	void SetIsOrderForDelivery(bool value);
	bool GetIsOrderForDelivery();
};
