#include <iostream>
#include <string>

void main()
{
    // prompt user for radius of circle
    std::cout << "Enter Radius ";

    // cin is used to get input from user
    // use the input stream operator >> before the variable names
    int radius = 0;
    std::cin >> radius; 

    const double Pi = 3.14159;

    // area = pi * r^2
    // double * int * int = double  (int is promoted to double, the smaller type is promoted to the larger type)
    double area = Pi * radius * radius;
    std::cout << "Area = " << Pi << " * " << radius << " * " << radius << std::endl;
    std::cout << "Area = " << area << std::endl;

    // triangle

    std::cout << "Enter base and height of triangle ";
    
    int base = 0, height = 0;
    //std::cin >> base;
    //std::cin >> height;
    std::cin >> base >> height; // this is the same as above two lines
    // endl does NOT work for cin like it does for cout

    // area = 1/2 * base * height
    // (int / int) * int * int = int (all ints)
    area = (1.0 / 2) * base * height; // adding the .0 makes it a double - that way the number can be divided properly (look into this more)
    std::cout << "Area = " << area << std::endl;

    int summValue = (1.0 / 2); // this wont work properly because summValue is an int but 1.0/2 is a double

    std::cout << "Enter Name ";

    std::string name;
    //std::cin >> name;
    std::cin.ignore(); // this ignores the newline character left in the input buffer by previous cin
    std::getline(std::cin, name); // this allows for spaces in the name use this instead of above line
    std::cout << name << std::endl;

    // overflow and underflow
    short smallvalue = 32767; // max value for short
    smallvalue = smallvalue + 1; // overflow

    short largevalue = -32768; // lowest value for short
    largevalue = largevalue - 1; // underflow

    std::cout << smallvalue << " " << largevalue << std::endl;
   // if you excede the limits of a data type you get overflow or underflow and it wraps around to the other end of the range


}