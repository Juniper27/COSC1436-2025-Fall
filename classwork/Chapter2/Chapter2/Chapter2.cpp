/*
* June Barkley
* Lab #
* COSC 1436 Fall 2025
*/
//preprocessor directive 
#include <iostream>
#include <string> // needed for string data type

int main()
{
    // every C++ statement MUST end with a semicolon (;)
    // statements = anything that does something in the language
  
   // std::cout << "Hello World!" << " " << "Your Name";
   // std::cout << "Hello World!";
   // std::cout << "Your Name";
   // these 2 things are the same 
    std::cout << "Hello World! " << "Juniper " << std::endl;
    std::cout << "You are... " << 21 << " years old" << std::endl;

    // identical to << std::endl;
    std::cout << "Hello World! " << "Juniper\n";

    std::cout << "Hello World!\tJuniper";

    std::cout << "Hello World!\"Juniper\"";

    std::cout << "C:\\Windows";

    // string literals "..."
    // "whatever"
    // escape sequences \n \t \" - special meaning to the compiler
    //               ~ starts w/ backslash (\) followed by a character !! ONLY WITH STRING LITERALS
    // use one or the other - not both (either endl or \n) 
    // \n - newline
    // \t - tab 
    // \" - double quote (like a person quoting someone else)
    // \\ - slash (for smth like a file path) 
  
    // integer literals - one or more digits (0-9)
    
    // floating-point literals - one or more digits + fraction NO DECIMALS
    // 3.14159 or 3E10 -3E10 3E-10 scientific notation works in cpp! 

    // variable - named memory location where data is stored (means something to the programmer not the data)
    std::string name; 
    name = " Juniper";
    std::cout << "Hello World! " << name; 
    // before you can use a variable you must declare it and define it! (std::string name; name = _____) -- CODE RUNS TOP DOWN SILLY


    //var-declaration ::= T id;
    //type = define what can be stored in the variable and in what format
    int age;
    age = 21;
    std::cout << "you are " << age << " years old";

    // area of retangle calculator!! 
    // A = L * W
    std::string firstname;
    // int length;
    // int width;
    // length = 10;
    // width = 20;
    int length = 10, width = 20;

    // uninitialized variable - YOU MUST assign a value to a variable before you read it
    // int area;
    // area = 0;
    int area = 0;
    //area = length * width;
    
    std::cout << "area of rectangle is " << area << std::endl;

    // 2 different approaches to declaring variables
    // block - all variables together
    // int radius, diameter;
     // std:: string circleName;
     
     // now i can use the variables

     // inline - variables are declared just before they are used
     int radius, diameter;
    // use radius, diameter 

    std::string circleName;
    // use circleName

    double pi;
    pi = 3.14159; 

    char lettergrade;
    lettergrade = 'A'; // single quotes for char literals

    bool ispassing;
    ispassing = true; // false 

    area = length * width; 

    // assignment is right associative (evaliate right to left) 
    //length = 100;
    //width = 100; 
    length = width = 100;
    //std::cout << length; // DONT USE THIS IS WRONG WAY TO DEBUG
    // F9 TOGGLE BREAKPOINT pauses the program if there is an issue and let me see (it tells the dubugger to stop here and let me look at the variables)
    // f5 toggle for debugger to run
    // yellow error tells you what line of code will run next when started up again
    // f10 stepover run the code to the next avalible code 
    
    //int and Int are different
    // camel casing > all lowercase, capitalize on word boundaries (firstName) 2nd word capitalized but no spaces

    // arithmetic operators
    // arith_op ::= + - * / %
    length = length + 10;
    width = width - 20;

    // int division :: = int / int produces an int, remainder is lost
    double result = 10 / 3; // = 3 nearist whole number 
    
    // modulus is remainder and ONLY works for the integral types (int, short, long)
    double remainder = 10 % 3; // 1
    // int + int = int types must match on both sides of the assignment operator (=) so 10/3 = 3 (whole number) chops off the decimal
    // remainder operator (%) only works with integers shows the remainder of a division problem since 9+9=18 18/10=1 remainder 8   

    int negativeLength = -length;

    // scope - lifetime of a variable
    { // starting new block
        int newVariable1 = 10;
        double newVariable2 = 45.7;
    }

    {
        char newVariable1 = 'A';
    }
    //std::cout << newVariable1; // this is out of scope and will give an error

    // strings c++
    std::string studentName; // compiler cant read string without std:: this is why its not a primitive data type
    studentName = "June";

    studentName = studentName + " Barkley";

    // literal - great for atatic values that dont change
    // variable - great for dynamic values that do change (writeable and readable) - grades, emails, names, addresses
    // Named constant - great for static values that dont change (readable only) - pi, tax rates, conversion factors - cant change them in the program
    const double pi = 3.14159;

    // A = Pi r^2;
    double areaCircle = pi * (radius * radius);

    const int NumberOfLabGrades = 5;
    const int NumberOfExamGrades = 4;
    // pascal casing > first letter of each word is capitalized (NumberOfLabGrades) common for constants

   // pi = 140; // this will give an error because pi is a constant and cant be changed

}