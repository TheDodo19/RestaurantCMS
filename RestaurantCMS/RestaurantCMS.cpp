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

const std::string AccepptanceValues[] = {"Tak","tak","t","true","True","Yes","yes","y",""};
const std::string DeclineValues[] = {"Nie","nie","n",""};
bool isNumber(const std::string& str)
{
    for (char const& c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}
int GetIntFromClient(std::string message="")
{
    std::cout << message << std::endl;
    std::string userInput;
    bool IsUserInputSuccesscful = false;

    do {
        std::cin >> userInput;
        std::cout << "Podano niepoprawna wartosc, prosze wpisac cyfre/liczbe " << std::endl;;

    } while (isNumber(userInput));
}
std::string GetStringFromClient(std::string message="")
{
    std::cout << message << std::endl;
    std::string userInput;
    return userInput;
}
bool GetBoolFromClient(std::string message="")
{
  
    std::cout << message << std::endl;;
    std::string userInput;
  
    bool IsUserInputSuccesscful =false ;
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
std::vector<std::string> split(const std::string& str, int delimiter(int) = ::isspace) {
    std::vector<std::string> result;
    std::stringstream ss(str);
    for (std::string i; ss >> i;) {
        result.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }
    return result;
}

std::vector<Dish> getDishesFromFile(std::string filepath)
{
    std::string varOutput;
    std::vector<Dish> result;
    // Read from the text file
    std::ifstream DishFile(filepath);
    int propNumber = 0;
    Dish dish;
    while (std::getline(DishFile, varOutput,',')) {
        //wyzerowanie w celu poprawnego bindingu danych 
        if (propNumber == 4) {
            propNumber = 0;
            result.push_back(dish);
            dish = Dish();
        }
        propNumber++;
        switch (propNumber)
        {
            case 1: dish.SetDishId(varOutput);
            break;
            case 2: dish.SetName(varOutput);
            break;
            case 3: dish.SetName(varOutput);
            break;
            case 4: dish.SetPrice(varOutput);
            break;
        }
    }
    DishFile.close();
    return result;
}
std::string GetClientName()
{
    std::string name;
    std::cout << "PODAJ SWOJE IMIE" << std::endl;
    std::cin >> name;
    return name;
}
void SetTableNumber(int number)
{
    std::cout << "zobaczyc do czego uzywa sie table number" << std::endl;
}
std::string GetRestaurantDeliveryDateTime()
{
    //todo sprawdzenia czasow i czy nie jest mniejsza jak obecna godzina +20 minut
}
void SetDeliveryData()
{
    std::string adress=GetStringFromClient("Podaj adres");
    std::string DeliveryHour = GetRestaurantDeliveryDateTime();
}
int main()
{
    std::string input="";
    Restaurant restaurant("PIZZADOBRA", "ADRES","OPIS");
    std::cout<<restaurant.PrintRestaurantData("WITAJ W RESTAURACJI ");
    Client client;
    client.SetIsOrderForDelivery(GetBoolFromClient("Czy zamowienie bedzie na dowoz"));
    GetClientName();
    if (client.GetIsOrderForDelivery())
    {
        SetDeliveryData();
    }
    else
    {
        SetTableNumber(GetIntFromClient("Podaj numer stolika"));
    }
    std::cout << "Hello World!\n";
    Dish dish(420, "Schabowy", "mięso", 69);
    getDishesFromFile("dish.txt");
    std::cout << "Wcisnij dowolny klawisz aby wyjsc z aplikacji";
    std::cin.get();
}
