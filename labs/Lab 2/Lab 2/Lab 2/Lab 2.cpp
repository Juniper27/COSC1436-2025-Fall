// June Barkley
// Lab 2
// COSC 1430 Fall 2025

#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    std::cout << "Lab 2" << std::endl;
    std::cout << "June Barkley " << std::endl;
    std::cout << "COSC 1430 Fall 2025" << std::endl;

    int initialLoan;
    do
    {
        std::cout << "Enter initial loan (Must be between $1 and $1000): ";
        std::cin >> initialLoan;

        if (initialLoan < 1 || initialLoan > 1000)
        {
            std::string message = "Loan must be between $1 and $1000.";
            std::cout << "ERROR! " << message << std::endl;
        }
        

    } while (initialLoan < 1 || initialLoan > 1000);
    std::cout << "\n";
    /*do
    {
        std::cin >> initialLoan;

        if (initialLoan < 1 || initialLoan > 1000)
        {
            std::string message = "Loan must be between $1 and $1000.";
            std::cout << "ERROR! " << message << std::endl;
        }
      
    } while (initialLoan < 1 || initialLoan > 1000); */
    float interestRate;
    do
    {
        std::cout << "Enter intrest rate % (Must be between 1.0 and 100.0): ";
        std::cin >> interestRate;

        if (interestRate < 1.0 || interestRate > 100.0)
        {
            std::string message = "Interest rate % must be between 1.0 and 100.0.";
            std::cout << "ERROR! " << message << std::endl;
        }
    } while (interestRate < 1.0 || interestRate > 100.0);
    std::cout << "\n";

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "First 12 Months of Loan" << std::endl;
    std::cout << std::setw(50) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
    std::cout << std::setw(9) << std::left << "Month " << std::setw(15) << "Loan Balance " << std::setw(9) << "Intrest " << std::setw(15) << "New Balance " << std::endl;
    std::cout << std::setw(50) << std::setfill('-') << "" << std::setfill(' ') << std::endl;

    std::cout << std::setw(9) << std::left << 0 << std::setw(15) << initialLoan << std::setw(9) << 0.00 << std::setw(15) << initialLoan << std::endl;


}