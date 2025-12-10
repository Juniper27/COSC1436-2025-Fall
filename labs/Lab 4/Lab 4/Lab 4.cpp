// June Barkley
// Lab 4 
// Cosc 1436 Fall 2025

#include <iostream>

/// <summary>
/// Displays the program header information.
/// </summary>
void displayHeader()
{
    std::cout << "June Barkley" << std::endl;
    std::cout << "Lab 4" << std::endl;
    std::cout << "Cosc 1436 Fall 2025" << std::endl;
}

/// <summary> Prompts the user for int values to fill an array.
/// stops when the array is full or the user enters a negative value. </summary>
/// <param name="numbers"> the array to store values in </param>
/// <param name="maxSize"> the max number of values the array can hold </param>
/// <returns> the number of valid inputs by the user </returns>
int fillArray(int numbers[], int maxSize)
{
    int count = 0;
    int input;

    while (count < maxSize)
    {
        std::cout << "\n Enter a value: ";
        std::cin >> input;

        if (input < 0)
        {
            std::cout << "Value must be greater than or equal to 0." << std::endl;
        }
        else if (input == 0)
        {
            return count; 
        }
        else
        {
            numbers[count] = input;
            count++;
        } 
    }
    return count;
}

char menuChoice()
{
  char choice;
  std::cout << std::endl;
  std::cout << "Main Menu" << std::endl;
  std::cout << "---------------" << std::endl;
  std::cout << "A) Add (Sum)" << std::endl;
  std::cout << "L) Largest" << std::endl;
  std::cout << "M) Mean" << std::endl;
  std::cout << "S) Smallest" << std::endl;
  std::cout << "I) Insert" << std::endl;
  std::cout << "V) View" << std::endl;
  std::cout << "Q) Quit" << std::endl;
  std::cout << "Enter choice: ";

}

int main()
{
    displayHeader();

    const int MAX_SIZE = 100;
    int numbers[MAX_SIZE];

    int count = fillArray(numbers, MAX_SIZE);

    return 0;
}