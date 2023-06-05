#include <iostream>
#include <cmath>
#include "mymap.h"

enum MENU
{
    ADD = 1,
    REMOVE = 2,
    PRINT = 4,
    FIND = 8,
    SIZE = 16,
    EXIT = 32,
};

void printMenu()
{
    for(int i = 0; i < 40; ++i)
    {
        std::cout << "-";
    }
    std::cout << "\nMenu: " << std::endl;
    std::cout << "1 - Add;" << std::endl;
    std::cout << "2 - Remove;" << std::endl;
    std::cout << "3 - Print;" << std::endl;
    std::cout << "4 - Find;" << std::endl;
    std::cout << "5 - Size;" << std::endl;
    std::cout << "6 - Exit." << std::endl;
    std::cout << "Our choice: ";
}
template<typename Argument>
const Argument argument(const char* type)
{
    Argument mean;
    std::cout << "Enter the " << type << ": ";
    while(!(std::cin >> mean))
    {
        std::cout << "Enter the correct value: ";
        std::cin.clear();
        std::cin.ignore();
    }
    return mean;
}

int main()
{
    std::cout << "The program - map." << std::endl;
    MyMap<int, int> example;
    while(true)
    {
        int choice;
        printMenu();
        while(!(std::cin >> choice))
        {
            std::cout << "Enter the correct choice: ";
            std::cin.clear();
            std::cin.ignore();
        }
        choice = pow(2, (choice - 1));
        if(ADD == choice)
        {
            int k = argument<int>("key");
            int v = argument<int>("value");
            example.add(k, v);
        }
        else if (REMOVE == choice)
        {
            example.remove(argument<int>("key"));
        }
        else if(PRINT == choice)
        {
            example.print();
        }
        else if(FIND == choice)
        {
            int value = example.find(argument<int>("key"));
            std::cout << " value - "<< value << std::endl;
        }
        else if (SIZE == choice)
        {
            std::cout << example.size() << std::endl;
        }
        else if(EXIT == choice)
        {
            break;
        }
    }
    return 0;
}
