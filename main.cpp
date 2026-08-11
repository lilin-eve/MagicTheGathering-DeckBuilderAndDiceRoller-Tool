#include <iostream>

//  declaration for called function clearConsoleScreen()
//  function is void, returns no value
//  when called, function clears console screen output, prints new-line, & clears the buffer, returns to caller
//  
void clearConsoleScreen();

//  declaration for called function printBorderLine()
//  function is void, returns no value
//  when called, function prints a border-line, prints new-line, & clears the buffer, returns to caller
//  
void printBorderLine();

//  declaration for called function searchMagicCard();
//  function is void, returns no value
//  
void searchMagicCard();

//  definition for called function programMagicDiceRoller()
//  function is void, returns no value
//  
void programMagicDiceRoller();

//  definition for called function mainMenu()
//  function is type string, returns string value to caller
//  - when called, function creates local bool variable 'mainMenuGateway' & initializes it as false
//  - function creates string variable 'mainMenuInput' & initializes it as 0
//  - function enters while statement, statement loops while 'mainMenuGateway' is false
//  - function prints menu options and prompts user for input into 'mainMenuInput'
//  - if user inputs "s", "S", "r", "R", "q", or "Q", then 'mainMenuGateway' is set to true, function exits while loop, function ends & returns 'mainMenuInput' to caller
//  - else if user inputs any input not stated above, then function calls printBorderLine(), prints "Invalid input!\n", prints "Try again.\n", calls printBorderLine(), while statement loops
//  
std::string menuMain(){

    bool menuMainGateway = false;
    
    std::string menuMainInput{};

    while (!menuMainGateway){
        printBorderLine();
        std::cout << "This is a program that provides useful tools for the card game 'Magic: The Gathering'.\n";
        std::cout << "Would you like to (S)earch a Magic: The Gathering card, (R)oll a die, or (Q)uit: ";
        std::cin >> menuMainInput;
        if ( menuMainInput == "s" || menuMainInput == "S" || menuMainInput == "r" || menuMainInput == "R" || menuMainInput == "q" || menuMainInput == "Q" ){
            menuMainGateway = true;
        }
        else {
            clearConsoleScreen();
            printBorderLine();
            std::cout << "Invalid input!\n";
            std::cout << "Try again.\n";
        }
    }

    return menuMainInput;

}

//  definition for caller function main()
//  this is a program that provides useful tools for the card game 'Magic: The Gathering'
//  at start, main() enters while loop statement
//  statement loops main() while global bool variable 'programTermination' is false( 'programTermination' is false by default )
//  main() calls function printBorderLine()
//  after return from printBorderLine(), main() prints program definition
//  main() then creates string 'mainMenuInput', & refers to function mainMenu() for its value
//  after return from mainMenu(), if 'mainMenuInput' is "y" or "Y", then * insert path here *
//  else if 'mainMenuInput' is "n" or "N", then * insert path here * 
//  else if 'mainMenuInput' is "q" or "Q", then main() prints "Exiting program . . . . . ", prints new-line, clears the buffer, & sets 'programTermination' to true
//  while statement exits, main() returns 0
//  
int main(){

    bool programTermination = false;

    while (!programTermination){

        std::string menuMainInput{ menuMain() };

        if ( menuMainInput == "s" || menuMainInput == "S" ){
            searchMagicCard();
        }
        else if ( menuMainInput == "r" || menuMainInput == "R" ){
            programMagicDiceRoller();
        }
        else if ( menuMainInput == "q" || menuMainInput == "Q" ){
            std::cout << "Exiting program . . . . . " << std::endl;
            programTermination = true;
        } 

    }

    return 0;

}
