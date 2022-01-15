// RestaurantCMS.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include "Restaurant.h"
#include "Client.h"

const std::string AccepptanceValues[] = {"Tak","tak","t","true","True","Yes","yes","y",""};
const std::string DeclineValues[] = {"Nie","nie","n",""};
std::string PrintRestaurantData() {
    return "";
}

bool GetBoolFromClient(std::string message)
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
        std::cout << "Podano niepoprawną wartość, proszę wpisać odpowiedź jednym słowem tak/nie" << std::endl;;
    } while (!IsUserInputSuccesscful);
    return IsUserInputSuccesscful;
}

int main()
{
    std::string input="";
    Restaurant restaturant("PIZZADOBRA", "ADRES","OPIS");
    std::cout<<restaturant.PrintRestaurantData("WITAJ W RESTAURACJI ");
    Client client;
    client.SetIsOrderForDelivery(GetBoolFromClient("Czy zamowienie bedzie na dowoz"));
    std::cout << "Hello World!\n";
}
