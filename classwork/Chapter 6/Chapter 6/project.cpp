/*
 * Chapter 6
 * COSC 1436
 */
#include <iostream>
#include <string>
#include <iomanip>

//Movie details
struct Movie
{
    std::string title;          //Required
    std::string description;    //Optional
    int runLength;              //Required, 0
    int releaseYear;            //Optional, but between 1900-2100
    bool isClassic;             //Required, false
    std::string genres;         //Optional (comma separated list of genres)
};

int g_thisIsAGlobalVariable = 100; // <- this is an example of a global variable (don't do this!)
// any int declared outside of a function is a global variable

enum class ForegroundColor {
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Cyan = 36,
    BrightRed = 91,
    BrightGreen = 92,
    BrightYellow = 93,
    BrightCyan = 96
};

// Function prototypes
// Forward declarations/referencing ---- try to avoid using this and just rearrange code order
void DisplayError(std::string);

void ResetTextColor()
{
    std::cout << "\033[0m";
}

void SetTextColor(ForegroundColor color)
{
    std::cout << "\033[" << (int)color << "m"; // must type cast to get this to work
}

/// <summary> Display a confirmation message
/// <param name="message">Message to show</param>
/// <returns>returns true or false depending on user input</returns>
bool Confirm (std::string message)
{
std::cout << message << " (Y / N) ";
std::string input;
std::cin >> input;

while (true)
{
    if (_strcmpi(input.c_str(), "Y") == 0)
        return true;
    else if (_strcmpi(input.c_str(), "N") == 0)
        return false;
    else {
        DisplayError("You Must enter either Y or N");
        std::cin >> input;
        }
    }
}

/// <summary> Displays ab error message to the user </summary>
/// <param name="message">Message to display.</param>
void DisplayError(std::string message)
{
    //std::cout << "\033[91m"
    SetTextColor(ForegroundColor::BrightRed);
    std::cout << "ERROR: " << message << std::endl;
    // << "\033[0m"
        ResetTextColor();
       // << std::endl;
}

void DisplayWarning(std::string message)
{
    SetTextColor(ForegroundColor::BrightYellow);
    std::cout << message << std::endl;
    ResetTextColor();
}

std::string ReadString(std::string message, bool isRequired)
{
    std::cout << message;

    std::string imput;
    std::getline(std::cin, imput);

    while (isRequired && imput == "")
    {
        DisplayError("Value is Required");
        std::getline(std::cin, imput);
    }
    return imput;
}

/// <summary>View details of a movie.</summary>
/// <remarks>
/// More details including paragraphs of data if you want.
/// </remarks>
void ViewMovie(Movie movie)
{
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
    std::cout << "Is Classic? " << (movie.isClassic ? "Yes" : "No") << std::endl;
    if (movie.description != "")
        std::cout << movie.description << std::endl;
    std::cout << std::endl;
}

/// <summary>Prompt user and add movie details.</summary>
Movie AddMovie()
{
    Movie movie;// = {0};

    //Get movie details
    std::cout << "Enter movie title: ";
    std::cin.ignore();
    std::getline(std::cin, movie.title);

    //Title is required
    movie.title = ReadString("Enter movie title: ", true);
   
    std::cout << "Enter the run length (in minutes): ";
    do
    {
        std::cin >> movie.runLength;

        //Error
        if (movie.runLength < 0)
        {
            DisplayError("Run length must be at least 0");
        }
    } while (movie.runLength < 0);

    std::cout << "Enter the release year (1900-2100): ";
    std::cin >> movie.releaseYear;
    while (movie.releaseYear < 1900 || movie.releaseYear > 2100)
    {
        DisplayError("Release year must be between 1900 and 2100");

        std::cin >> movie.releaseYear;
    }

    movie.description = ReadString("Enter the optional description: ", false);

    // Genres, up to 5
    for (int index = 0; index < 5; ++index)
    {
        std::string genre = ReadString("Enter genre (or blank to continue): ", false);
        if (genre == "")
            break;
        else if (genre == " ")
            continue;

        movie.genres = movie.genres + ", " + genre;
    }

    movie.isClassic = Confirm("Is this a classic?");
   
    return movie;
}

void DeleteMovie(Movie movie)
{
    if (Confirm("Are you sure you want to delete this movie?" + movie.title + "?"))
        return;

    // TODO: Delete movie
    DisplayWarning("Delete not implemented");
}

void EditMovie(Movie movie)
{
    DisplayWarning("Edit not implemented");
}

int main()
{
    //Display main menu
    bool done = false;
    do
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

        Movie movie;

        switch (choice)
        {
            case 'A':
            case 'a': movie = AddMovie(); break;

            case 'V':
            case 'v': ViewMovie(movie); break;

            case 'D':
            case 'd': DeleteMovie(movie); break;

            case 'E':
            case 'e': EditMovie(movie); break;

            case 'Q':
            case 'q': done = true;

            default: DisplayError("Invalid choice"); break;
        };
    } while (!done);

    //std::cin.ignore();
    // Function call ::= func () 
    //ViewMovie();
}

//EVERY FUNCTION MUST HAVE COMMENTS OR I  WILL LOSE POINTS 

//NEVER USE GLOBAL SCOPE 
    // they are unacceptable in professional code
    // they are unreliable
    // they make code harder to read and maintain
    // functions are no longer isolated units 
    // chance at memory corruption increases