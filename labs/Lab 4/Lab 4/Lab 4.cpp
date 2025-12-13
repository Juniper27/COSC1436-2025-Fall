// June Barkley
// Lab 4 
// Cosc 1436 Fall 2025

#include <iostream>
#include <iomanip>

/// <summary>
/// Displays the program header information.
/// </summary>
void displayHeader()
{
    std::cout << "June Barkley" << std::endl;
    std::cout << "Lab 4" << std::endl;
    std::cout << "Cosc 1436 Fall 2025" << std::endl;
}

/// <summary> Prompts the user for int values to fill an array. Stops when the array is full or the user enters a negative value. </summary>
/// <param name="numbers"> the array to store values in </param>
/// <param name="maxSize"> the max number of values the array can hold </param>
/// <returns> the number of valid inputs by the user </returns>
int fillArray(int numbers[], int maxSize)
{
    int count = 0;
    int input;

    while (count < maxSize)
    {
        std::cout << "Enter a value: ";
        std::cin >> input; 

        if (input < 0)
        {
            std::cout << "Error!! Value must be greater than or equal to 0." << std::endl;
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

/// <summary> displays the main menu and returns the user's choice </summary>
/// <returns> user menu choice </returns>
char menuChoice()
{
  char choice;
  do
  {
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

      std::cin >> choice;

      if (choice != 'A' && choice != 'a' &&
          choice != 'L' && choice != 'l' &&
          choice != 'M' && choice != 'm' &&
          choice != 'S' && choice != 's' &&
          choice != 'I' && choice != 'i' &&
          choice != 'V' && choice != 'v' &&
          choice != 'Q' && choice != 'q')
      {
          std::cout << "Error!! Invalid menu option." << std::endl;
      }

  } while (choice != 'A' && choice != 'a' &&
           choice != 'L' && choice != 'l' &&
           choice != 'M' && choice != 'm' &&
           choice != 'S' && choice != 's' &&
           choice != 'I' && choice != 'i' &&
           choice != 'V' && choice != 'v' &&
           choice != 'Q' && choice != 'q');

  return choice;
}

/// <summary> returns the largest value in the array </summary>
/// <param name="numbers"> the array </param>
/// <param name="count"> the number of values stored in the array </param>
/// <returns> the largest value in the array </returns>
int getLargest(const int numbers[], int count)
{
    int largest = numbers[0];

    for (int i = 1 ; i < count; i++)
    {
        if (numbers[i] > largest)
        {
            largest = numbers[i];
        }
    }
    return largest;
}

/// <summary> returns the smallest value in the array </summary>
/// <param name="numbers"> the array </param>
/// <param name="count"> the number of values in the array </param>
/// <returns> the smallest value in the array </returns>
int getSmallest(const int numbers[], int count)
{
    int smallest = numbers[0];

    for (int i = 1 ; i < count; i++)
    {
        if (numbers[i] < smallest)
        {
            smallest = numbers[i];
        }
    }

    return smallest;
}

/// <summary> adds the values in the array and returns the totals </summary>
/// <param name="numbers"> the array </param>
/// <param name="count"> the number of values in the array </param>
/// <returns> the sum of the values in the array </returns>
int getSum(const int numbers[], int count)
{
    int sum = 0;

    for (int i = 0; i < count; i++)
    {
        sum += numbers[i];
    }

    return sum;
}

/// <summary> calculates the mean of values in the array the returns answer </summary>
/// <param name="numbers"> the array </param>
/// <param name="count"> the number of values in the array </param>
/// <returns> the average value of the array </returns>
double getMean(const int numbers[], int count)
{
    int sum = getSum(numbers, count);
    return static_cast<double>(sum) / count;
}

/// <summary> displays the values in the array </summary>
/// <param name="numbers"> the array </param>
/// <param name="count"> the number of values in the array </param>
void displayValues(const int numbers[], int count)
{
    for (int i = 0; i < count; i++)
    {
        std::cout << numbers[i] << " ";

        if ((i + 1) % 10 == 0)
        {
            std::cout << std::endl;
        }
    }

    std::cout << std::endl;
}

/// <summary> allows the user to insert additional values into the array, follows same rules as fillArray </summary>
/// <param name="numbers"> the array </param>
/// <param name="count"> the number of values in the array </param>
/// <param name="maxSize"> the maximum number of values the array can hold </param>
/// <returns> updated number of values in array </returns>
int insertValue(int numbers[], int count, int maxSize)
{
    int input;

    while (count < maxSize)
    {
        std::cout << "Enter a value: ";
        std::cin >> input;

        if (input < 0)
        {
            std::cout << "Error!! Value must be greater than or equal to 0. " << std::endl;
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

int main()
{
    displayHeader();

    const int MAX_SIZE = 100;
    int numbers[MAX_SIZE];

    int count = fillArray(numbers, MAX_SIZE);

    char choice;

    do
    { 
        choice = menuChoice();

        switch (choice)
        {
            case 'A': case 'a':
                std::cout << "Sum = " << getSum(numbers, count) << std::endl;
                break;

            case 'L': case 'l':
                std::cout << "Largest = " << getLargest(numbers, count) << std::endl;
                break;

            case 'M': case 'm':
                std::cout << std::fixed << std::setprecision(4);
                std::cout << "Mean = " << getMean(numbers, count) << std::endl;
                break;

            case 'S': case 's':
                std::cout << "Smallest = " << getSmallest(numbers, count) << std::endl;
                break;

            case 'I': case 'i':
                count = insertValue(numbers, count, MAX_SIZE);
                break;

            case 'V': case 'v':
                displayValues(numbers, count);
                break;
        }
    } while (choice != 'Q' && choice != 'q');

    return 0;
}