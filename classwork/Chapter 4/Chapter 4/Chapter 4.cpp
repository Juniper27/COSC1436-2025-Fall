//Chapter 4
// COSC 1430

#include <iostream>
#include <string>

int main()
{
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
    std::cin >> runLength;
    if (runLength < 0)
    {
        std::cout << "Run length must be at least 0" << std::endl;
        runLength = 0;
    };

    std::cout << "Enter the release year (1900-2100): ";
    std::cin >> releaseYear;
    if (releaseYear < 1900)
    {
        std::cout << "Release year must be at least 1900" << std::endl;
        releaseYear = 1900;
    };

    std::cout << "Enter the optional description: ";
    std::getline(std::cin, description);

    std::cout << "Enter the optional user rating (1.0-10.0) : ";
    std::cin >> userRating;

    std::cout << "Is this a classic (y/n)?: ";
    std::string input;
    std::cin >> input;
    if (_strcmpi(input.c_str(), "Y") == 0)
        isClassic = true;
    if (_strcmpi(input.c_str(), "N") == 0)
        isClassic = false;
    //TODO: HANDLE OTHER VALUES

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
    std::cout << "== " << (left > right) << std::endl;
    std::cout << "!= " << (left < right) << std::endl;

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

