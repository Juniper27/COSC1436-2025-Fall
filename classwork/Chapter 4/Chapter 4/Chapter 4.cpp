//Chapter 4
// COSC 1430

#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    // Demo prefix/postfix-increment/decrement
    std::cout << "Enter a valuse: ";
    int number;
    std::cin >> number;

    /*
    std::cout << "Prefix (++x) = " << ++number << ", X =" << number << std::endl;
    std::cout << "Prefix (--x) = " << --number << ", X =" << number << std::endl;
    std::cout << "Postfix (x++) = " << number++ << ", X =" << number << std::endl;
    std::cout << "Prefix (x--) = " << number-- << ", X =" << number << std::endl; */

    //Display main menu
    bool done = false;
    while (!done)
    {
        std::cout << "Movie Library" << std::endl;
        std::cout << "--------------" << std::endl;
        std::cout << "A)dd Movie" << std::endl;
        std::cout << "V)iew Movies" << std::endl;
        std::cout << "E)dit Movie" << std::endl;
        std::cout << "D)elete Movie" << std::endl;
        std::cout << "Q)uit" << std::endl;

        char choice;
        std::cin >> choice;


        switch (choice)
    {
        case 'A': //std::cout << "Add not implemented" << std::endl; break;
        case 'a': std::cout << "Add not implemented" << std::endl; done = true; break;

        case 'V':
        case 'v': //can be written like this
        {
            //declaring a variable 
            // switch-statement
            std::cout << "View not implemented" << std::endl; done = true;
            break;
        }
        case 'D': std::cout << "Delete not implemented" << std::endl; done = true; break;
        case 'd': std::cout << "Delete not implemented" << std::endl; done = true; break;

        case 'E': std::cout << "Edit not implemented" << std::endl; done = true; break;
        case 'e': std::cout << "Edit not implemented" << std::endl; done = true; break;

        case 'Q': return 0;
        case 'q': return 0;

        default: std::cout << "Invalid choice" << std::endl; break;
    };

    // movie details
    std::string title;                 // Required      
    std::string description;           // Optional
    int runLength;                     // Required, 0
    int releaseYear;                   // Optional, but betwen 1900-2000
    double userRating;                 // Optional, 1.0-10.0
    bool isClassic;                    // Required, false

    // get movie details
    std::cout << "Enter movie title: ";
    std::getline(std::cin, title);

    // Title is required
    bool isEmpty = title == "";
    if (isEmpty)
        std::cout << "Title is required" << std::endl;

    std::cout << "Enter the run length (in mins): ";
   /* runLength = -1;
    while (runLength < 0)
    {
        std::cin >> runLength;
        if (runLength < 0)
            std::cout << "ERROR: Run length must be at least 0" << std::endl;
    };*/
    std::cin >> runLength;
    while (runLength < 0)
    {
        //ERROR
        std::string message = "Run length must be at least 0";
        std::cout << "ERROR: " << message << std::endl;

        std::cin >> runLength;
    }

    std::cout << "Enter the release year (1900-2100): ";
    std::cin >> releaseYear;
   // if (releaseYear < 1900)
   // {
   //    std::cout << "Release year must be at least 1900" << std::endl;
   //    releaseYear = 1900;
   // } else if (releaseYear > 2100)
   // {
   //    std::cout << "Release year must be between 1900 - 2100" << std::endl;
   // }
    if (releaseYear < 1900 || releaseYear > 2100)
    {
        std::cout << "Release year must be between 1900 - 2100" << std::endl;
        releaseYear = 1900;
    }


    std::cout << "Enter the optional description: ";
    std::getline(std::cin, description);

    std::cout << "Enter the optional user rating (1.0-10.0) : ";
    std::cin >> userRating;
    if (userRating < 1.0 || userRating > 10.0)
    {
        std::cout << "Rating must be between 1.0 and 10.0" << std::endl;
        userRating = 1.0;
    }
   // if (userRating < 1.0)
   // {
   //     std::cout << "Rating must be between 1.0 and 10.0" << std::endl;
   //     userRating = 1.0;
   // } else if (userRating > 10.0)
   // {
   //     std::cout << "Rating must be between 1.0 and 10.0" << std::endl;
   //     userRating = 1.0;
   // }

    std::cout << "Is this a classic (y/n)?: ";
    std::string input;
    std::cin >> input;
    // if (eb) $ [ else $];
   // if (_strcmpi(input.c_str(), "Y") == 0)
   //     isClassic = true;
   // if (_strcmpi(input.c_str(), "N") == 0)
   //     isClassic = false;
   // else
   //     std::cout << "You must enter Y or N";

    isClassic = false;
    if (_strcmpi(input.c_str(), "Y") == 0)
        isClassic = true;
    else
        if (_strcmpi(input.c_str(), "N") == 0)
            isClassic = false;
        else
             std::cout << "You must enter Y or N";

     // View movie
    //    Title (Year)
    //    Run Length # min
    //    User Rating = ##
    //    Is Classic? 
    //    [Description]
    std::cout << std::fixed << std::setprecision(1) << std::endl;
    std::cout << title << " (" << releaseYear << ")" << std::endl;
    std::cout << "Run Length " << runLength << " mins" << std::endl;
    std::cout << "User Rating = " << userRating << std::endl;

    std::cout << "Is Classic? " << (isClassic ? "Yes" : "No") << std::endl;
    if (description != "")
        std::cout << description << std::endl;
    std::cout << std::endl;
}


void relationalDemo()
{
    std::cout << "Enter two values ";

    int left, right;
    std::cin >> left >> right;

    // relational operators :: ==, !=, >, <, >=, <=
    // WARNING 1 ~ equality and equals are similar and work in the same situations
    // WARNING 2 ~ be very very VERY careful of floatf point comparison for equality
    //                      (consider using >= or <= instead, unless comparing to an integar)
    // WARNING 3 ~ strings compare by character values not by locale
    bool areEqual = left == right;
    std::cout << "areEqual = " << areEqual << std::endl;
    areEqual = left == right;
    std::cout << "areEqual = " << areEqual << std::endl;
    // remember bool is true or false

    //areEqual = 10 == left; // put the literal on the left side
    //areEqual = 10 = left: // this is an error because = is an assignment operator

    std::cout << "> " << (left > right) << std::endl;
    std::cout << "< " << (left < right) << std::endl;
    std::cout << ">= " << (left >= right) << std::endl;
    std::cout << "<= " << (left <= right) << std::endl;
    std::cout << "== " << (left == right) << std::endl;
    std::cout << "!= " << (left != right) << std::endl;

    // if a line isnt working put perithesis around the expression
    // 1 = true 0 = false
    // if there is a ! before the expression it negates the value != MEANS NOT EQUAL inequality

    float someValue = (10 / 3.0) * 3.0;
    float someOtherValue = (10 / 3.0) / 3.0;
    areEqual = someValue == someOtherValue;
    std::cout << areEqual << std::endl;

    // comparison works but is case sensitive so we typically wont use strings here if i put in "51" and "154" 51 would be higher because 5 is higher than 1
    std::string name1 = "Bob ";
    std::string name2 = "bob ";
    std::cout << (name1 == name2) << std::endl; // false because B and b are different character values CASE MATTERS WITH STRINGS!!!

    // to compare strings case insensitive use the strcmpi (string compare ignore)
    // > 0 ::= left > right
    // < 0 ::= left < right
    // = 0 ::= left == right
    areEqual = _strcmpi(name1.c_str(), name2.c_str()); // c_str() converts a string to a c-style string cant use cpp style strings with strcmpi
    // add _ to strcmpi if it isnt working
}

