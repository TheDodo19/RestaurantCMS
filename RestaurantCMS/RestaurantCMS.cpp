// RestaurantCMS.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "iostream"
#include "string"
#include "Restaurant.h"
#include "Client.h"
#include "Dish.h"
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
const int RestaurantOpeningTime = 10;
const int RestaurantClosingTime = 21;
const std::string menuFilePath = "dish.txt";
const std::string AccepptanceValues[] = { "Tak","ta","tak","t","T","true","True","Yes","yes","y","" };
const std::string DeclineValues[] = { "Nie","nie","n","N","" };
bool isNumber(const std::string& str)
{
	for (char const& c : str) {
		if (std::isdigit(c) == 0) return false;
	}
	return true;
}
int GetIntFromClient(std::string message = "")
{
	std::cout << std::endl << message << std::endl;
	std::string userInput;
	bool IsUserInputUnSuccesscful = true;
	int iterator = 0;
	do {
		if (iterator != 0)
		{
			std::cout << "Podano niepoprawna wartosc, prosze wpisac cyfre/liczbe " << std::endl;
		}
		std::getline(std::cin >> std::ws, userInput);
		iterator++;
	} while (!isNumber(userInput));
	return atoi(userInput.c_str());
}
std::string GetStringFromClient(std::string message = "")
{
	std::cout << std::endl << message << std::endl;
	std::string userInput;
	std::getline(std::cin >> std::ws, userInput);
	return userInput;
}
bool GetBoolFromClient(std::string message = "")
{

	std::cout << message << std::endl;;
	std::string userInput;

	bool IsUserInputSuccesscful = false;
	do {
		std::cin >> userInput;
		for (int i = 0; AccepptanceValues[i].length(); i++)
		{
			if (userInput == AccepptanceValues[i])
			{
				return true;
			}
		}
		for (int i = 0; DeclineValues[i].length(); i++)
		{
			if (userInput == DeclineValues[i])
			{
				return false;
			}
		}
		std::cout << "Podano niepoprawna wartosc, prosze wpisac odpowiedz jednym slowem tak/nie" << std::endl;;
	} while (!IsUserInputSuccesscful);
	return IsUserInputSuccesscful;
}
std::vector<Dish> getDishesFromFile(std::string filepath)
{
	std::string varOutput;
	std::vector<Dish> result;
	// Read from the text file
	std::ifstream DishFile(filepath);
	int propNumber = 0;
	Dish dish;
	while (std::getline(DishFile, varOutput, ';')) {
		//wyzerowanie w celu poprawnego bindingu danych 
		if (propNumber == 4) {
			propNumber = 0;
			dish = Dish();
		}
		propNumber++;
		switch (propNumber)
		{
		case 1: dish.SetDishId(varOutput);
			break;
		case 2: dish.SetName(varOutput);
			break;
		case 3: dish.SetIngredients(varOutput);
			break;
		case 4: dish.SetPrice(varOutput);
			break;
		}
		if (propNumber == 4)   result.push_back(dish);
	}
	DishFile.close();
	return result;
}
std::string GetClientName()
{
	std::string name = GetStringFromClient("PODAJ SWOJE IMIE");
	return name;
}
void SetTableNumber(int number, Client* client)
{
	client->SetTableNumber(number);
}
std::string GetRestaurantDeliveryDateTime()
{
	int deliveryHour = GetIntFromClient("Podaj preferowana pelna godzine dostawy");
	while (deliveryHour > RestaurantClosingTime || deliveryHour < RestaurantOpeningTime)
	{
		std::cout << "Podano godzine wykraczajaca poza godziny dzialania restauracji" << std::endl;
		deliveryHour = GetIntFromClient("Podaj inna preferowana pelna godzine dostawy");
	}
	return std::to_string(deliveryHour);
}
void SetDeliveryData(Client* client)
{
	std::string adress = GetStringFromClient("Podaj adres");
	client->SetAddress(adress);
	std::string DeliveryHour = GetRestaurantDeliveryDateTime();
	client->SetPrefDeliveryTime(DeliveryHour);
}
void PrintMenu(std::vector<Dish> menu)
{
	for (Dish item : menu)
	{
		item.PrintDishAsMenu();
	}
	std::cout << std::endl;
}

void ChooseDishAsClientRequest(Client* client)
{
	std::vector<Dish> menu = getDishesFromFile(menuFilePath);
	std::string userInput = "";
	std::string userInfo = "";
	do {
		system("CLS");
		PrintMenu(menu);

		std::cout << "ABY DODAC POZYCJE DO ZAMOWIENIA WPISZ NUMER DANIA, KTORE CHCESZ WYBRAC " << std::endl;
		std::cout << "WPISZ 'ok' ABY ZATWIERDZIC SWOJE ZAMOWIENIE" << std::endl;
		std::cout << "OBECNA CENA TWOJEGO ZAMOWIENIA WYNOSI: " << client->GetOrderSummedPrice() << std::endl << "POZYCJI NA ZAMOWIENIU: " << client->GetOrderCount() << std::endl;
		std::cout << std::endl << userInfo << std::endl;
		std::cin >> userInput;
		if (userInput == "ok" || userInput == "OK" || userInput == "Ok" || userInput == "oK")
		{
			if (client->GetOrderCount() >= 1)
			{
				break;
			}
			else
			{
				userInfo = "Dodaj minimum jedna pozycja do zamowienia";
			}
		}
		else
		{
			Dish selectedDish = Dish();
			bool isFoundOnMenu = false;
			for (Dish item : menu)
			{
				if (std::to_string(item.GetDishId()) == userInput)
				{
					isFoundOnMenu = true;
					selectedDish = item;
				}
			}
			if (isFoundOnMenu)
			{

				bool isMoreThanOne = GetBoolFromClient("Czy chcesz zamowic wiecej niz jedna porcja?");
				if (isMoreThanOne)
				{
					int portionCount = -1;
					do {
						portionCount = GetIntFromClient("Ile porcji chcesz zamowic?");
					} while (portionCount <= 0 || portionCount > 999);
					for (int i = 0; i < portionCount; i++)
					{
						client->AddDishToOrder(selectedDish);
					}
				}
				else
				{
					client->AddDishToOrder(selectedDish);
				}
			}
			else
			{
				userInfo = "Nie znaleziono pozycji o takim numerze";
			}

		}
	} while (true);
}
struct DishDTO {
	Dish dish;
	int howMany;
};
bool checkIfDishExistsInDtoList(std::vector<DishDTO> dishDtoList,Dish item){
	for (DishDTO& dishdto : dishDtoList)
	{
		if (dishdto.dish.GetDishId() == item.GetDishId())
		{
			return true;
		}
	}
	return false;
}
std::vector<DishDTO> GroupByDishId(std::vector<Dish> dishes)
{
	std::vector<DishDTO> dishDtoList;
	for (Dish item : dishes)
	{

		if (checkIfDishExistsInDtoList(dishDtoList,item))
		{
			for (DishDTO& dishdto : dishDtoList)
			{
				if (dishdto.dish.GetDishId() == item.GetDishId())
				{
					dishdto.howMany = dishdto.howMany + 1;
					break;
				}
			}
		}
		else
		{
			DishDTO newDish;
				newDish.dish = item;
				newDish.howMany = 1;
				dishDtoList.push_back(newDish);
		}
		if (dishDtoList.size() == 0)
		{
			DishDTO newDish;
			newDish.dish = item;
			newDish.howMany = 1;
			dishDtoList.push_back(newDish);
		}
	}
	return dishDtoList;
}

void PrintBill(Client* client)
{
	std::ofstream File;
	File.open("Bill.txt");
	File << "Cena twojego zamowienia wynosi" << std::endl;
	File << client->GetOrderSummedPrice() << std::endl;
	File << "Twoje zamówienie to" << std::endl;
	std::vector<Dish> dishes = client->GetOrders();
	std::vector<DishDTO> dishDtoList= GroupByDishId(dishes);
	
	for (DishDTO dishdto: dishDtoList)
	{
		File << dishdto.dish.GetDishToBill() << "x" << dishdto.howMany << std::endl;
	}
	
	std::cout << std::endl;
	File.close();
}
void WriteSummary(Client* client)
{
	std::cout << "Twoje zamowienie to:" << std::endl;
	std::vector<Dish> dishes = client->GetOrders();
	std::vector<DishDTO> dishDtoList = GroupByDishId(dishes);
	for (DishDTO dishdto : dishDtoList)
	{
		std::cout << dishdto.dish.GetDishToBill()  << "x" << dishdto.howMany << std::endl;
	}
	std::cout << "Cena twojego zamowienia to:" << std::endl;
	std::cout << client->GetOrderSummedPrice() << std::endl;
}
void PreparationTime(Client* client)
{
	std::cout << "przewidywany czas przygotowania to: " << client->GetOrderCount() * 5 << "min" << std::endl;
}




int main()
{
	std::string input = "";
	Restaurant restaurant("PIZZADOBRA", "Glogowska 289", "MY ROBIMY TY JESZ");
	std::cout << restaurant.PrintRestaurantData("WITAJ W RESTAURACJI ");
	Client client;
	client.SetName(GetClientName());
	client.SetIsOrderForDelivery(GetBoolFromClient("Czy zamowienie bedzie na dowoz"));
	if (client.GetIsOrderForDelivery())
	{
		SetDeliveryData(&client);
	}
	else
	{
		SetTableNumber(GetIntFromClient("Podaj numer stolika"), &client);
	}
	ChooseDishAsClientRequest(&client);
	WriteSummary(&client);
	if (client.GetIsOrderForDelivery())
	{
		std::cout << "Dania dostarczymy o " << client.GetDeliveryTime() << std::endl;
	}
	else
	{
		PreparationTime(&client);
	}
	PrintBill(&client);
	system("PAUSE");
}
