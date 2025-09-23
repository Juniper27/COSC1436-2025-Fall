// June Barkley
// Lab 1
// COSC 1430 Fall 2025

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

int main () 
{
    std::cout << "Lab 1 " << std::endl;
    std::cout << "June Barkley " << std::endl;
    std::cout << "COSC 1430 Fall 2025\n " << std::endl;

    std::cout << "Enter Name: ";
    std::string name;
    std::getline(std::cin, name);
    std::cout << " \n" << std::endl;

    std::cout << "Enter Score - Lab 1: ";
    double lab1 = 0;
    std::cin >> lab1; // switched from using string to using cin
    //std::getline(std::cin, lab1); -- what it used to be remember to use old string line if you put this back!

    std::cout << "Enter Score - Lab 2: ";
    double lab2 = 0;
    std::cin >> lab2;
   
    std::cout << "Enter Score - Lab 3: ";
    double lab3 = 0;
    std::cin >> lab3;

    std::cout << "Enter Score - Lab 4: ";
    double lab4 = 0;
    std::cin >> lab4;

    std::cout << "Enter Score - Exam 1: ";
    double exam1 = 0;
    std::cin >> exam1;
    
    std::cout << "Enter Score - Exam 2: ";
    double exam2 = 0;
    std::cin >> exam2;

    std::cout << "Enter Score - Exam 3: ";
    double exam3 = 0;
    std::cin >> exam3;

    std::cout << "Enter your Participation Score: ";
    double participation = 0;
    std::cin >> participation;

    std::cout << "Enter Final Exam Score: ";
    double finalExam= 0;
    std::cin >> finalExam;

    std::cout << " \n";
    std::cout << name << ", Your Lab Scores are: " << std::endl;
    std::cout << "Lab 1: " << lab1 << std::endl;
    std::cout << "Lab 2: " << lab2 << std::endl;
    std::cout << "Lab 3: " << lab3 << std::endl;
    std::cout << "Lab 4: " << lab4 << std::endl;
  
    std::cout << " \n";
    std::cout << name << ", Your Exam Scores are: " << std::endl;
    std::cout << "Exam 1: " << exam1 << std::endl;
    std::cout << "Exam 2: " << exam2 << std::endl; 
    std::cout << "Exam 3: " << exam3 << std::endl; 

    std::cout << " \n";
    std::cout << name << ", Your Other Scores are: " << std::endl;
    std::cout << "Participation: " << participation << std::endl;
    std::cout << "Final Exam: " << finalExam << std::endl;

    std::cout << std::fixed << std::setprecision(2);
    double labAverage;
    labAverage = (lab1 + lab2 + lab3 + lab4) / 4;
    double examAverage;
    examAverage = (exam1 + exam2 + exam3) / 3;
    double classAverage;
    classAverage = (labAverage * 0.65) + (examAverage * 0.20) + (participation * 0.05) + (finalExam * 0.10);


    std::cout << " \n";
    std::cout << name << ", Here are your class averages: " << std::endl;
    std::cout << "Lab Average (65%): " << labAverage << "%" << std::endl;
    std::cout << "Exam Average (20%): " << examAverage << "%" << std::endl;
    std::cout << "Participation (5%): " << participation << "%" << std::endl;
    std::cout << "Final Exam (10%): " << finalExam << "%" << std::endl;
    std::cout << "Your Class Average = " << classAverage << "%" << std::endl;
}
