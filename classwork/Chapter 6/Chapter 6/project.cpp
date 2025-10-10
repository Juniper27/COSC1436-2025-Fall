//Chapter 6
// COSC 1430

#include <iostream>
#include <string>
#include <iomanip>

// Movie details
struct Movie
{
    std::string title;                 // Required      
    std::string description;           // Optional
    int runLength;                     // Required, 0
    int releaseYear;                   // Optional, but betwen 1900-2000
    double userRating;                 // Optional, 1.0-10.0
    bool isClassic;                    // Required, false
};

void AddMovie();

/// <summary> View details of a movie </summary>
/// <remarks> This function displays the details of a movie to the console. </remarks>
/// more details including paragraphs of data if you want
void ViewMovie ()
{
    Movie movie;

    // View movie
    //    Title (Year)
    //    Run Length # min
    //    User Rating = ##
    //    Is Classic? 
    //    [Description]
    std::cout << std::fixed << std::setprecision(1) << std::endl;
    std::cout << movie.title << " (" << movie.releaseYear << ")" << std::endl;
    std::cout << "Run Length " << movie.runLength << " mins" << std::endl;
    std::cout << "Genres " << movie.genres << std::endl;

int main()

{
    std::cout << "Enter a valuse: ";
    int number;
    std::cin >> number;
  
    for (int rows = 0; rows <= 12; ++rows)
        (
         for (int cols = 0; cols < 10; ++cols)
                
         std::cout << std::setw(4) << (rows * cols);
        )
         stds::cout << std::endl; 
)

    //Display main menu
    bool done = false;
    do // while (!done)
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
        case 'A': 
        case 'a': std::cout << "Add not implemented" << std::endl; done = true; break;

        case 'V':
        case 'v': 
        {
         
            ViewMovie();
            done = true;
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
        Movie movie // = {0};

    std::cout << "Enter movie title: ";
    std::getline(std::cin, title);

    bool isEmpty = title == "";
    if (isEmpty)
        std::cout << "Title is required" << std::endl;

    std::cout << "Enter the run length (in mins): ";
  
   do // while (runLength < 0)
    {
       std::cin >> runLength;
        //ERROR
       if (runLength >= 0)
       {
           std::string message = "Run length must be at least 0";
           std::cout << "ERROR: " << message << std::endl;
       }

   } while (runLength < 0); 

    std::cout << "Enter the release year (1900-2100): ";
    std::cin >> releaseYear;
 
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

    std::cout << "Is this a classic (y/n)?: ";
    std::string input;
    std::cin >> input;

    isClassic = false;
    if (_strcmpi(input.c_str(), "Y") == 0)
        isClassic = true;
    else
        if (_strcmpi(input.c_str(), "N") == 0)
            isClassic = false;
        else
             std::cout << "You must enter Y or N";

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

    bool areEqual = left == right;
    std::cout << "areEqual = " << areEqual << std::endl;
    areEqual = left == right;
    std::cout << "areEqual = " << areEqual << std::endl;

    std::cout << "> " << (left > right) << std::endl;
    std::cout << "< " << (left < right) << std::endl;
    std::cout << ">= " << (left >= right) << std::endl;
    std::cout << "<= " << (left <= right) << std::endl;
    std::cout << "== " << (left == right) << std::endl;
    std::cout << "!= " << (left != right) << std::endl;

    float someValue = (10 / 3.0) * 3.0;
    float someOtherValue = (10 / 3.0) / 3.0;
    areEqual = someValue == someOtherValue;
    std::cout << areEqual << std::endl;

    std::string name1 = "Bob ";
    std::string name2 = "bob ";
    std::cout << (name1 == name2) << std::endl; 

    areEqual = _strcmpi(name1.c_str(), name2.c_str()); 

    // Function call ::func () |
    ViewMovie();
   
}

//EVERY FUNCTION MUST HAVE COMMENTS OR I  WILL LOSE POINTS 