// June Barkley
// Lab 1
// COSC 1430 Fall 2025

#include <iostream>
#include <string>

int main () 
{
    std::cout << "Lab 1 " << std::endl;
    std::cout << "June Barkley " << std::endl;
    std::cout << "COSC 1430 Fall 2025\n " << std::endl;

    std::cout << "Enter Name ";
    std::string name;
    std::getline(std::cin, name);
    std::cout << " \n" << std::endl;

    std::cout << "Enter Score - Lab 1: ";
    std::string lab1;
    std::getline(std::cin, lab1);

    std::cout << "Enter Score - Lab 2: ";
    std::string lab2;
    std::getline(std::cin, lab2);

    std::cout << "Enter Score - Lab 3: ";
    std::string lab3;
    std::getline(std::cin, lab3);

    std::cout << "Enter Score - Lab 4: ";
    std::string lab4;
    std::getline(std::cin, lab4);

    std::cout << "Enter Score - Exam 1: ";
    std::string exam1;
    std::getline(std::cin, exam1);

    std::cout << "Enter Score - Exam 2 ";
    std::string exam2;
    std::getline(std::cin, exam2);

    std::cout << "Enter Score - Exam 3 ";
    std::string exam3;
    std::getline(std::cin, exam3);

    std::cout << name << ", Your Lab Scores are: " << std::endl;
    std::cout << "Lab 1: " << lab1 << std::endl;
    std::cout << "Lab 2: " << lab2 << std::endl;
    std::cout << "Lab 3: " << lab3 << std::endl;
    std::cout << "Lab 4: " << lab4 << std::endl;    

}
