#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

void CharDemo()
{
    //Character sets
    //  ANSI - 1 byte, char in C++, string for string
    //  Unicode - 2 bytes, wchar_t in C++, wstring for string
    char ansiCharacter = 'A';
    wchar_t unicodeCharacter = 'A';

    std::string ansiString = "Bob";
    std::wstring unicodeString = L"Bob";

    //Variants - Unicode variants of fixed size
    //char8_t char8Byte;
    char16_t char16Byte;
    char32_t char32Byte;
}

void CharFunctionDemo()
{
    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::cout << "Character "
        << std::setw(15) << "Letter? "
        << std::setw(10) << "Digit? "
        << std::setw(10) << "Letter/Digit? "
        << std::setw(10) << "Lowercase? "
        << std::setw(10) << "To Lower "
        << std::setw(10) << "Uppercase? "
        << std::setw(10) << "To Upper "
        << std::setw(10) << "Space? " << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    //Enumerate the characters of the string
    for (int index = 0; index < input.length(); ++index)
    {
        char ch = input[index];

        // All char functions are from C and therefore accept and return an int, not a char
        // Typecast back to char
        std::cout << ch
            << std::setw(15) << isalpha(ch)
            << std::setw(10) << isdigit(ch)
            << std::setw(10) << isalnum(ch)
            << std::setw(10) << islower(ch)
            << std::setw(10) << (char)tolower(ch)
            << std::setw(10) << isupper(ch)
            << std::setw(10) << (char)toupper(ch)
            << std::setw(10) << isspace(ch)
            << std::endl;
    };
}

void UnicodeCharFunctionDemo()
{
    std::wstring input;

    std::cout << "Enter a string: ";
    std::getline(std::wcin, input);

    std::cout << "Character "
        << std::setw(15) << "Letter? "
        << std::setw(10) << "Digit? "
        << std::setw(10) << "Letter/Digit? "
        << std::setw(10) << "Lowercase? "
        << std::setw(10) << "To Lower "
        << std::setw(10) << "Uppercase? "
        << std::setw(10) << "To Upper "
        << std::setw(10) << "Space? " << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    //Enumerate the characters of the string
    for (int index = 0; index < input.length(); ++index)
    {
        wchar_t ch = input[index];

        // All char functions are from C and therefore accept and return an int, not a char
        // Typecast back to char
        std::cout << ch
            << std::setw(15) << iswalpha(ch) // letters
            << std::setw(10) << iswdigit(ch) // digit
            << std::setw(10) << iswalnum(ch) // true if letter or digit
            << std::setw(10) << iswlower(ch) // need to see if its a uppercase or lowercase
            << std::setw(10) << (char)towlower(ch)
            << std::setw(10) << iswupper(ch) // uppercase a letter
            << std::setw(10) << (char)towupper(ch) // lowercase a letter
            << std::setw(10) << iswspace(ch) // space.
            << std::endl;
    };
}

void CStringDemo()
{
    //Implicit sizing makes sense here
    char title[] = "My Program";
    char title2[] = {'M', 'y', ' '};

    //Normally use char* for C strings
    // or char const* for C strings that are const
}

void CStringFunctions()
{
    const int MaxInputSize = 100;
    char input[101] = {0}; // highest number you can get is 99 because there is always a null on the end, to get 100 you will need to put 101
    char output[101] = {0};

    std::cout << "Input a value: ";
    std::cin >> input;

    // common c string function - #include <cstrings>
    int len = strlen(input); // strlen(string) size_t :: returns size of string

    // copying string
    // std::string str;
    // str = "Hello";
    strcpy(output, input);  // strcpy(target, source) :: copies source to target until it finds the null
                            // it will null terminate the target string !!!!!!!!!! 
                            // if output is exactly the length of input then no null is written
                            // if output is smaller than output then it overwrites memory (security vuln) 
    strncpy_s(output, input, MaxInputSize); // strncpy (target, source, maxsize) ;; copies up to maxsize characters

    // concat a string
    // str += " Done";
    strcat(output, " Done"); // concats the second string to the end of the first string
    strncat(output, " Done", MaxInputSize); 

    // comparison
    // str1 == str2
    strcmp(output, input); // compares 2 strings, case sensitive (>0, =0, <0)
    _stricmp(output, input); // case insensitive
    strncmp(output, input, MaxInputSize); // compares 2 strings up to max len

    char* pos = strstr(input, "a"); // find substring in string, returns pointer to start of substring or nullptr

    // conversion
    int value = atoi("123"); // parses string to int
    value = atoi("123abc"); // 123
    value = atoi("abc"); // 0
    // atol -> parses a string to a long
    // atof -> parses a string to a floating point value (double)

    char* end;
    value = strtol("123abc", &end, 0); // parses a string to a long, using the base given
                                       // and returns the last character parsed
}

void CPlusPlusStringFunction()
{
    std::string input, output;

    std::cout << "Enter a Value: ";
    std::cin >> input;

    //copying a string
    output = input;

    // concat a string
    output += " done";

    // compare
    bool isEqual = input == output;

    // length of the string
    int len = input.length(); // strlen(input)
    bool isEmpty = input == "";
    isEmpty = input.length() == 0;
    isEmpty = input.empty(); // preferred

    // reseting a string
    output = ""; // strcpy(output, "");
    output.clear(); // clears a string

    // modification
    output.append(" Done"); // strcat(output, " Done");
    // output.insert()

    // find strings
    input.find("a"); // strstr(input, "a"); // iterator (will be used in further classes)

    std::string sub = input.substr(10); // gets the characters starting at index, up to the given length)
    sub = input.substr(10, 4);

    const char* ptr = input.c_str(); // gets the C string version of the c++ string 
}
int main()
{
    CharFunctionDemo();
}
