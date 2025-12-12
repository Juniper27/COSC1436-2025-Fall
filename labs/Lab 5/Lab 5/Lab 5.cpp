// June Barkley
// Lab 5: Trip Planner
// COSC 1430 Fall 2025

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cctype>

const int MAX_STOPS = 100;

/// <summary>
/// holds the coordinates for a stop
/// </summary>
struct Stop
{
    int x;
    int y;
};

/// <summary> shows the header information </summary>
void showHeader()
{
    std::cout << "Lab 5: Trip Planner " << std::endl;
    std::cout << "June Barkley " << std::endl;
    std::cout << "COSC 1430 Fall 2025" << std::endl;
    std::cout << "\n";
}

/// <summary> prompts the user to enter a number in the range </summary>
/// <param name="prompt"> text shown to the user when asked for input </param>
/// <param name="min"> minimum value allowed </param>
/// <param name="max"> maximum value allowed </param>
/// <returns> valid number entered by user </returns>
int getValidNumber(const char* prompt, int min, int max)
{
    int value;
    std::cout << prompt;
    std::cin >> value;

    while (value < min || value > max)
    {
        std::cout << "Error!! Please enter a number between " << min << " and " << max << ": ";
        std::cin >> value;
    }

    return value;
}

/// <summary> displays the menu and gets user choice, handles input validation </summary>
/// <returns> the validated menu option </returns>
char showMenu()
{
    char choice;
    std::cout << "A) Add Stop " << std::endl;
    std::cout << "B) View Trip " << std::endl;
    std::cout << "C) Delete Stop " << std::endl;
    std::cout << "D) Clear Trip " << std::endl;
    std::cout << "E) Exit " << std::endl;
  
    while (true)
    {
        std::cout << "Enter Your Choice: ";
        std::cin >> choice;
        choice = static_cast<char>(std::toupper(choice));

        if (choice == 'A' || choice == 'B' || choice == 'C' ||
            choice == 'D' || choice == 'E')
        {
            return choice;
        }
        
        std::cout << "Invalid choice. Please select A, B, C, D, E." << std::endl;
    }
}

/// <summary> adds a stop to the trip </summary>
/// <param name="trip"> array of stop pointers </param>
void addStop(Stop* trip[])
{
    int x = getValidNumber("Enter X coordinate (-100 - 100): ", -100, 100);
    int y = getValidNumber("Enter Y coordinate (-100 - 100): ", -100, 100);

    Stop* newStop = new Stop;
    newStop->x = x;
    newStop->y = y;

    bool added = false;
    for (int i= 0; i < MAX_STOPS; i++)
    {
        if (trip[i] == nullptr)
        {
            trip[i] = newStop;
            added = true;
            std::cout << "Stop added! " << std::endl;
            break;
        }
    }
    if (!added)
    {
        std::cout << "Trip is full! No more stops. :c " << std::endl;
        delete newStop;
    }
}

/// <summary> calculates the distance between two points </summary>
/// <param name="x1"> X coord of first point </param>
/// <param name="y1"> Y coord of first point </param>
/// <param name="x2"> X coord of second point </param>
/// <param name="y2"> Y coord of second point </param>
/// <returns> the distance between the two points </returns>
double findDistance(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    return std::sqrt(dx * dx + dy * dy);
}

/// <summary> views the trip details and calculates distances and times </summary>
/// <param name="trip"> array of stop pointers </param>
/// <param name="speed"> speed in miles per hour </param>
void viewTrip(Stop* trip[], int speed)
{
    double totalDistance = 0.00;
    double totalTime = 0.00;
    int preX = 0.00;
    int preY = 0.00;
    int stopNumber = 1;

    std::cout << std::setw(5) << "Stop"
        << std::setw(15) << "Location"
        << std::setw(20) << "Distance (miles)"
        << std::setw(20) << "Time (minutes)" << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;

    for (int i = 0; i < MAX_STOPS; i++)
    {
        if (trip[i] != nullptr)
        {
            Stop* s = trip[i];
            double distance = findDistance(preX, preY, s->x, s->y);
            double time = (distance / speed) * 60;

            std::cout << std::setw(5) << stopNumber
                << std::setw(10) << "(" << s->x << "," << s->y << ")"
                << std::setw(20) << std::fixed << std::setprecision(2) << distance
                << std::setw(20) << std::fixed << std::setprecision(2) << time << std::endl;

            totalDistance += distance;
            totalTime += time;
            preX = s->x;
            preY = s->y;
            stopNumber++;
        }
    }

    std::cout << "---------------------------------------------------------------" << std::endl;
    std::cout << std::setw(5) << stopNumber - 1
        << std::setw(10) << ""
        << std::setw(20) << std::fixed << std::setprecision(2) << totalDistance
        << std::setw(20) << std::fixed << std::setprecision(2) << totalTime << std::endl;
}

/// <summary> deletes a stop from the trip </summary>
/// <param name="trip"> array of stop pointers </param>
void deleteStop(Stop* trip[])
{
    int count = 0;
    for (int i = 0; i < MAX_STOPS; i++)
    {
        if (trip[i] != nullptr) count++;
    }

    if (count == 0)
    {
        std::cout << "No stops to delete. " << std::endl;
        return;
    }

    int stopNumber = getValidNumber("Enter stop number to delete: ", 1, count);
    delete trip[stopNumber - 1];

    for (int i = stopNumber - 1; i < MAX_STOPS - 1; i++)
    {
        trip[i] = trip[i + 1];
        if (trip[i] == nullptr) break;
    }
    trip[MAX_STOPS - 1] = nullptr;

    std::cout << "Stop deleted. " << std::endl;
}

/// <summary> clears stops from a trip </summary>
/// <param name="trip"> array of stop pointers </param>
void clearTrip(Stop* trip[])
{
    char confirm;
    std::cout << "Are you sure you want to clear all stops from the trip? (Y/N): ";
    std::cin >> confirm;
    confirm = toupper(confirm);

    if (confirm == 'Y')
    {
        for (int i = 0; i < MAX_STOPS; i++)
        {
            if (trip[i] != nullptr)
            {
                delete trip[i];
                trip[i] = nullptr;
            }
        }

        std::cout << "Trip cleared. " << std::endl;

    }
    else
    {
        std::cout << "Trip not cleared. " << std::endl;
    }
}

/// <summary> prompts the user to enter their travel speed </summary>
/// <returns> speed in mph </returns>
int getSpeed()
{
    return getValidNumber("Enter your travel speed in mph (1-60): ", 1, 60);
}

int main()
{
    showHeader();

    Stop* trip[MAX_STOPS] = { nullptr };

    int speed = getSpeed();

    bool quit = false;
    while (!quit)
    {
        char choice = showMenu();

        switch (choice)
        {
            case 'A':
                addStop(trip);
                break;
            case 'B':
                viewTrip(trip, speed);
                break;
            case 'C':
                deleteStop(trip);
                break;
            case 'D':
                clearTrip(trip);
                break;
            case 'E':
            {
                char confirm;
                std::cout << "Are you sure you want to quit? (Y/N): ";
                std::cin >> confirm;
                confirm = toupper(confirm);
                if (confirm == 'Y') quit = true;
                break;
            }
        }
    }

    clearTrip(trip);

    return 0;
}