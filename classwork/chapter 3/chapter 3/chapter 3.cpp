#include <iostream>
#include <string>
#include <cmath> // math functions
#include <iomanip> // IO manipulators for std::setw

void main()
{
    // get values for x and y
    std::cout << " Enter values for x and y: ";

    double x, y;
    std::cin >> x >> y;

    // function X    Y    Result
    //-------------------------------
    std::cout << std::fixed << std::setprecision(4); // use fixed point notation for floating point values FORCES DECIMAL POINT TO BE SHOWN
    std::cout << std::setw(9) << std::left << "Function " << std::setw(7) << " x " << std::setw(7) << " y " << std::setw(12) << " result " << std::endl;
    std::cout << std::setw(35) << std::setfill('_') << "" << std::setfill(' ') << std::endl;

    std::cout << std::setw(9) << std::left << "pow " << std::setw(7) << x << std::setw(7) << y << std::setw(12) << pow(x, y) << std::endl;
    std::cout << std::setw(9) << std::left << "sqrt " << std::setw(7) << x << std::setw(7) << y << std::setw(12) << sqrt(x) << std::endl;

    std::cout << std::setw(9) << std::left << "ceil " << std::setw(7) << x << std::setw(7) << y << std::setw(12) << ceil(x) << std::endl;
    std::cout << std::setw(9) << std::left << "floor " << std::setw(7) << x << std::setw(7) << y << std::setw(12) << floor(x) << std::endl;

    std::cout << std::setw(9) << std::left << "round " << std::setw(7) << x << std::setw(7) << y << std::setw(12) << round(x) << std::endl;
    std::cout << std::setw(9) << std::left << "trunc " << std::setw(7)<<  x << std::setw(7) << y << std::setw(12) << trunc(x) << std::endl;
    // makes a pretty table yippe!! 
}
void ExpressionDemo()
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

    // type coercion - compiler implicitly converts an expression of one type to a larger type

    // type casting - you explicitly convert a expressions type to another type
    // c style cast

    int left = 10;
    int right = 3;

    // int intDivision = 10 / 3; // int / int = int - both of the numbers are ints so the result is an int (anything smaller than an int + int = int)
    double intDivision = 10 / 3;
    intDivision = 10.0 / 3; // double / int = double - one of the numbers is a double so the result is a double

    intDivision = left / right;

    intDivision = (double)left / right; // double / int = double - left is explicitly cast to a double so the result is a double
    intDivision = left / (double)right; // these are both the same!! - int / double = double

    intDivision = (double)(left / right); // this will produce an int result first then cast it to a double - this is NOT what we want!!! 

    intDivision = static_cast<double>(left) / right; // this is the C++ style cast - it is safer than the C style cast
    intDivision = left / static_cast<double>(right); // int / double = double

    // this is wrong and will produce 5 NEVER USE THIS vvvvv
    intDivision = (int)"5"; 
    //intDivision = static_cast<int>("5"); // this is safer and will produce a compile time error

    // MATH FUNCTIONS
    // pow(x , y) >> power x to the y power 5^3 = power(5,3)
    // sqrt(x) >> square root of x 
    // abs(x) >> absolute value of x
    //
    // ceil(x) >> smallest possible integral value >= x
    // floor(x) >> largest possible integral value <= x
   
    // round(x) >> rounds to nearest integer value (rounds float to int)
    // trunc(x) >> truncates a float to an integer (removes decimal portion)

    // exp(x) >> e^x exponential function
    // log(x) >> natural logarithm of x (base e) inverse of exp(x)

    double result;
    result = pow(5, 3); // 5 * 5 * 5 = 125
    result = pow(125, -3); // cube root of 125

    result = sqrt(100); // 10
    result = sqrt(pow(5, 2)); // 5 

    result = abs(-10); // 10
    result = abs(10); // 10

    result = ceil(14.5); // 15
    result = floor(3.1); // 3 

    result = round(14.5); // 15
    result = round(14.4); // 14

    result = trunc(14.5); // 14
    result = trunc(14.9); // 14
    result = (int)14.9; // this is the same as above line

    result = exp(4);
    result = log(54);




}