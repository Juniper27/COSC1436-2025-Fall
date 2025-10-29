// June Barkley
// Lab 3
// COSC 1436 Fall 2025

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>



void fallingDistance(double time)
{
    double g = 9.8;
    double distance = 0.5 * g * time * time;
    std::cout << "Falling Distance = " << distance << " meters in "  << time << " seconds." << std::endl;
}

int main()
{
    std::cout << "Lab 3: Falling Distance" << std::endl;
    std::cout << "June Barkley " << std::endl;
    std::cout << "COSC 1430 Fall 2025" << std::endl;
    std::cout << "\n";

    int fallingTime;
    std::cout << "Enter falling time in secounds (1-60secs): ";
    std::cin >> fallingTime;

    while (fallingTime < 1 || fallingTime > 60)
    {
        std::cout << "Error! Time must be between 1 and 60 seconds: ";
        std::cin >> fallingTime;
    }
    std::cout << "Falling Time: " << fallingTime << " seconds" << std::endl;
    fallingDistance(fallingTime);


}