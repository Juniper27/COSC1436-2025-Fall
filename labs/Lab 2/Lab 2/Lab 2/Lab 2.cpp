// June Barkley
// Lab 2
// COSC 1430 Fall 2025

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

int main()
{
    std::cout << "Lab 2" << std::endl;
    std::cout << "June Barkley " << std::endl;
    std::cout << "COSC 1430 Fall 2025" << std::endl;
    std::cout << "\n";

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
    int monthlyPayment;
    do
    {
        std::cout << "Enter monthly payment amount (Must be between $1 and " << initialLoan << "): ";
        std::cin >> monthlyPayment;

        if (monthlyPayment < 1 || monthlyPayment > initialLoan)
        {
            std::string message = "Monthly payment must be between $1 and Initial Loan Amount.";
            std::cout << "ERROR! " << message << std::endl;
        }
    } while (monthlyPayment < 1 || monthlyPayment > initialLoan);

    std::cout << "\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "First 12 Months of Loan" << std::endl;
    std::cout << std::setw(70) << std::setfill('-') << "" << std::setfill(' ') << std::endl;
    std::cout << std::right << std::setw(8) << "Month " << std::setw(12) << "Balance " << std::setw(12) << "Payment " << std::setw(12) << "Intrest " << std::setw(14) << "New Balance " << std::endl;
    std::cout << std::setw(70) << std::setfill('-') << "" << std::setfill(' ') << std::endl;

    double balance = initialLoan;
    double paymentTotal = 0.0;
    double interestTotal = 0.0;

    for (int month = 1; month <= 12; ++month)
    {
        double payment = 0.0;
        double interest = 0.0;
        double oldBalance = balance;

        if (month == 1)
        { 
            payment = 0.0;
            interest = 0.0;
            balance = oldBalance;
        }
        else if (balance > 0)
        {
            if (balance < monthlyPayment)
            {
                payment = balance;
            }
            else
            {
                payment = monthlyPayment;
            }

            balance -= payment;
            if (balance > 0)
            {
                interest = balance * (interestRate / 100.0);
            }
            balance = balance + interest;
            paymentTotal = paymentTotal + payment;
            interestTotal = interestTotal + interest;
        }

        std::cout << std::right 
            << std::setw(8) << month 
            << std::setw(12) << "$" << oldBalance 
            << std::setw(12) << "$" << payment 
            << std::setw(12) << "$" << interest 
            << std::setw(14) << "$" << balance << std::endl;
        //std::cout << month << std::setw(8) << "$" << oldBalance << std::setw(8) << "$" << payment << std::setw(8) << "$" << interest << std::setw(8) << "$" << balance << std::endl;
        //::cout << std::right << std::setw(5) << month << std::setw(8) << "$" << initialLoan << std::setw(8) << "$" << 0.00 << std::setw(8) << "$" << 0.00 << std::setw(8) << "$" << initialLoan << std::endl;
    }

    std::cout << "Total Payments: $" << paymentTotal << "    Total Interest: $" << interestTotal;

}