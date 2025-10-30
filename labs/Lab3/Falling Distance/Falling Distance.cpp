// June Barkley
// Lab 3
// COSC 1436 Fall 2025

#include <iostream>
#include <iomanip>

/// <summary> Displays the header information for the program.</summary>
/// display program title, my name, course, and semester.
void showHeader()
{
    std::cout << "Lab 3: Falling Distance" << std::endl;
    std::cout << "June Barkley " << std::endl;
    std::cout << "COSC 1430 Fall 2025" << std::endl;
    std::cout << "\n";
}

/// <summary> ask the user to enter the time (in seconds) that an object has been falling.</summary> 
/// validates entry is between 1 and 60 seconds.
/// <param name="time"> how long the object has been falling in seconds</param>
void fallingTime(int &time)
{
    std::cout << "Enter the time (in seconds) that the object has been falling: ";
    std::cin >> time;

    while (time < 1 || time > 60)
    {
        std::cout << "Error!! Please enter a time between 1 and 60 seconds: ";
        std::cin >> time;
    }
}

/// <summary>ask the user to choose the unit of measurement for the results: meters or feet.</summary>
/// <param name="unit"> which unit the user would like the results in</param>
void pickUnit(char &unit)
{
    std::cout << "Would you like the results in meters or feets? (m/f): ";
    std::cin >> unit;

    while (unit != 'm' && unit != 'M' && unit != 'f' && unit != 'F')
    {
        std::cout << "Error!! Please enter 'm' for meters or 'f' for feet: ";
        std::cin >> unit;
    }
}

/// <summary> calculates the distance for the object depending on the time it has been falling.</summary>
/// <param name="time"> time in seconds</param>
/// <param name="distance"> stores calculated distance</param>
void fallingDistance(int time, double &distance)
{
    double g = 9.8;
    distance = 0.5 * g * time * time;
    //std::cout << std::fixed << std::setprecision(2);
    //std::cout << "Falling Distance = " << distance << " meters in "  
        //<< time << " seconds." << std::endl;                              MOVE TO MAIN LATER?
}

/// <summary> converts the distance from meters to feet.</summary>
/// <param name="meters"> distance to convert</param>
void changeUnit(double &distance)
{
   distance = distance * 3.28084;
}

/// <summary> caculates the falling velocity based on time in seconds.
/// caps the velocity at 90 m/s.</summary>
/// <param name="time"> time in seconds</param>
/// <param name="velocity"> stores calculated velocity</param>
void fallingVelocity(int time, double &velocity)
{
    double g = 9.8;
    velocity = g * time;

    if (velocity > 90)
        velocity = 90;
}

/// <summary> displays a table showing the time in seconds, the falling distance, and the falling velocity.
/// format changes based on user unit choice.</summary>
/// <param name="time"> time in seconds</param>
/// <param name="unit"> unit choice for display</param>
void displayTable(int time, char unit)
{
    std::cout << "\nFalling Distance Table\n";
    std::cout << "===========================================\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::right
        << std::setw(10) << "Seconds"
        << std::setw(12) << "Distance"
        << std::setw(12) << "Velocity"
        << std::endl;
    std::cout << "===========================================\n";

    for (int i = 1; i <= time; i++)
    {
        double distance, velocity;

        fallingDistance(i, distance);
        fallingVelocity(i, velocity);

        if (unit == 'f' || unit == 'F')
            changeUnit(distance);
       
        std::cout << std::right << std::setw(10) << i 
            << std::setw(10) << distance;

        if (unit == 'm' || unit == 'M')
            std::cout << "m";
        else
            std::cout << "ft";
       
        std::cout << std::setw(10) << velocity;
        
        if (unit == 'm' || unit == 'M')
            std::cout << " m/s";
        else
            std::cout << " ft/s";

        std::cout << std::endl;
    }
}

int main()
{
    showHeader();

    int time;
    char unit;

    fallingTime(time);
    pickUnit(unit);
    displayTable(time, unit);

    return 0;
}