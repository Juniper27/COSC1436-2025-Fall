// June Barkley
// Lab 5: Trip Planner
// COSC 1430 Fall 2025

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cctype>

/// <summary>
/// shows the header information
/// </summary>
void showHeader()
{
    std::cout << "Lab 5: Trip Planner " << std::endl;
    std::cout << "June Barkley " << std::endl;
    std::cout << "COSC 1430 Fall 2025" << std::endl;
    std::cout << "\n";
}

char showMenu()
{
    char choice;
    std::cout << "A) Add Stop " << std::endl;
    std::cout << "B) View Trip Summary " << std::endl;
    std::cout << "C) Delete Stop " << std::endl;
    std::cout << "D) Clear Trip " << std::endl;
    std::cout << "E) Exit " << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return toupper(choice);
}

int main()
{
    showHeader();

    char choice = showMenu();

    return 0;
}