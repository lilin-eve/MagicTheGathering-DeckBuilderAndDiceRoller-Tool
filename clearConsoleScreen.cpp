#include <iostream>

//  definition for called function clearConsoleScreen()
//  function is void, returns no value to caller function
//  when called, function prints '\033[2J', which is ansi escape code for clearing console screen
//  function then clears the buffer, prints new-line, & function ends, returns to caller
//   
void clearConsoleScreen(){

    //  std::string clearScreen{ "\033[2J"};
    std::cout << "\033[2J" << std::endl;

}
