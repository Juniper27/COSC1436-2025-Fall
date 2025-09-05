/*
* June Barkley
* Lab #
* COSC 1436 Fall 2025
*/
//preprocessor directive 
#include <iostream>

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
    std::cout <<
    // 
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

    // assignment is right associative (evaliate right to left) 
    //length = 100;
    //width = 100; 
    length = width = 100;

}