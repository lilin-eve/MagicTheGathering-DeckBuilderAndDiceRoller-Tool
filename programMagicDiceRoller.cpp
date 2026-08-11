#include <iostream>
#include <tuple>   //  Required header for std::tuple
#include <vector>   //  Required header for std::vector
#include <string>   //  Required header for std::string
#include <cctype>   //  Required header for std::isdigit
//  #include <utility>  //  Required header for std::pair
#include <random>   //  Required header for random library, modern c++


int countD20 = 0;                                                                               //  definition for global int variable 'countD20'           //  value defined by user input
int countD12 = 0;                                                                               //  definition for global int variable 'countD12'           //  value defined by user input
int countD10 = 0;                                                                               //  definition for global int variable 'countD10'           //  value defined by user input
int countD8 = 0;                                                                                //  definition for global int variable 'countD8'            //  value defined by user input
int countD6 = 0;                                                                                //  definition for global int variable 'countD6'            //  value defined by user input
int countD4 = 0;                                                                                //  definition for global int variable 'countD4'            //  value defined by user input

std::vector<int> userDiceRoster{ countD20, countD12, countD10, countD8, countD6, countD4 };     //  definition for global int vector 'userDiceRoster'       //  values contained are global int variables 'countD*' in descending order
std::vector<int> userDiceRange{ 20, 12, 10, 8, 6, 4 };                                          //  definition for global int vector 'userDiceRange'        //  values contained are max output for each dice variant in descending order
std::vector<std::string> userDiceName{ "d20", "d12", "d10", "d8", "d6", "d4" };                 //  definition for global string vector 'userDiceName'      //  values contained are names for dice in descending order


//  declaration for called function clearConsoleScreen()
//  function is void, returns no value
//  
void clearConsoleScreen();

//  declaration for called function printBorderLine()
//  function is void, returns no value
//  
void printBorderLine();

//  definition for called function getDiceRolls()
//  function is void, returns no value
//  function receives 1 vector containing int values from caller function, locally named 'userDiceInclude'
//  
void getDiceRolls( std::vector<int> userDiceInclude ){
    
    std::random_device rd;
    std::mt19937 randomNumberEngine(rd());

    std::vector<int> collectDiceResults{};

    for ( std::size_t i = 0; i < userDiceRoster.size(); i++ ){
        if ( userDiceInclude[i] == 1 && userDiceRoster[i] > 0 ){
            for ( int x = 0; x < userDiceRoster[i]; x++ ){
                std::uniform_int_distribution<> range( 1, userDiceRange[i] );
                int rollUserDice = range(randomNumberEngine);
                collectDiceResults.push_back( rollUserDice );
                std::cout << "[" << userDiceName[i] << "] '" << x + 1 << "' rolls: " << rollUserDice << std::endl;
            }
            printBorderLine();
        }
    }

    std::cout << "The results of your rolls are listed below: \n";
    for ( std::size_t i = 0; i < collectDiceResults.size(); i++ ){
        std::cout << "| " << collectDiceResults[i] << " ";
    }

    std::cout << "|" << std::endl;

}

//  definition for called function countDiceTotal()
//  function returns int value to caller function
//  function returns the sum of all int elements in vector 'userDiceRoster'
//
int countDiceTotal(){

    int total{userDiceRoster[0] + userDiceRoster[1] + userDiceRoster[2] + userDiceRoster[3] + userDiceRoster[4] + userDiceRoster[5]};

    return total;

}

//  definition for called function rollUserDice()
//  function is void, returns no value
//  - at start, function creates int variable 'countDiceTotal', & intializes it as the sum of 'countD20', 'countD12', 'countD10', 'countD8', 'countD6', & 'countD4'
//  - if 'countDiceTotal' is greater than 0, function calls printBorderLine(), after return, function creates vector type int 'collectDiceResults', & refers to vector function getDiceRolls() for its value, function also passes 'countD20', 'countD12', countD10', 'countD8', 'countD6', & 'countD4' to called function getDiceRolls()... 
//  -   ... function prints "The results of your rolls are: " & enters for statement
//  -   ... for statement creates unsigned long_int variable 'i' & intializes it as 0, for statement loops while 'i' is less than the total number of individual elements in vector 'collectDiceResults', at end of each loop increase 'i' by 1( 'i' must be type 'std::size_t' instead of type 'int' when used with 'vector'.size() )
//  -   ... for statement prints 'collectDiceResults[i]' followed by " ", where 'i' is the 'i'-th value in vector 'collectDiceResults'
//  -   ... after exit from for statement, function prints new-line, clears the buffer, & returns to caller
//  - else, function calls printBorderLine(), after return, function prints error message, & returns to caller
//  
void rollUserDice( std::string userDiceInput ){

    clearConsoleScreen();
    printBorderLine();
   
    //  you should reformat progarm to include vector 'userDice' that globally stores all die 'count's 

    //  std::vector<std::string> userDiceName{ "d20", "d12", "d10", "d8", "d6", "d4" };

    //  std::vector<int> userDiceRoster{ countD20, countD12, countD10, countD8, countD6, countD4 };

    //  std::vector<int> userDiceRange{ 20, 12, 10, 8, 6, 4 };

    //  int countDiceTotal{ userDiceRoster[0] + userDiceRoster[1] + userDiceRoster[2] + userDiceRoster[3] + userDiceRoster[4] + userDiceRoster[5] };

    if ( countDiceTotal() > 0 ){
        if ( userDiceInput == "all" ){
            std::vector<int> userDiceInclude{ 1, 1, 1, 1, 1, 1 };
            getDiceRolls( userDiceInclude );
        }
        else if ( userDiceInput == "d20" ){
            std::vector<int> userDiceInclude{ 1, 0, 0, 0, 0, 0 };
            getDiceRolls( userDiceInclude );
        }
        else if ( userDiceInput == "d12" ){
            std::vector<int> userDiceInclude{ 0, 1, 0, 0, 0, 0 };
            getDiceRolls( userDiceInclude );
        }
        else if ( userDiceInput == "d10" ){
            std::vector<int> userDiceInclude{ 0, 0, 1, 0, 0, 0 };
            getDiceRolls( userDiceInclude );
        }
        else if ( userDiceInput == "d8" ){
            std::vector<int> userDiceInclude{ 0, 0, 0, 1, 0, 0 };
            getDiceRolls( userDiceInclude );
        }
        else if ( userDiceInput == "d6" ){
            std::vector<int> userDiceInclude{ 0, 0, 0, 0, 1, 0 };
            getDiceRolls( userDiceInclude );
        }
        else if ( userDiceInput == "d4" ){
            std::vector<int> userDiceInclude{ 0, 0, 0, 0, 0, 1 };
            getDiceRolls( userDiceInclude );
        }
        else if ( userDiceInput != "all" && userDiceInput != "d20" && userDiceInput != "d12" && userDiceInput != "d10" && userDiceInput != "d8" && userDiceInput != "d6" ){
            std::cout << "Invalid command parameters!\n";
            std::cout << "If you are unfamiliar with the commands, type command 'help'\n";
        }
    }
    else {
        std::cout << "Invalid operation!\n";
        std::cout << "No dice in roster.\n";
    }
}

//  definition for called function checkUserDiceCount()
//  function is tuple that returns a bool & two int values
//  
std::tuple<bool, int> checkUserDiceCount(){
    
    //  int countDiceTotal{ userDiceRoster[0] + userDiceRoster[1] + userDiceRoster[2] + userDiceRoster[3] + userDiceRoster[4] + userDiceRoster[5] };
    //  int countDiceTotal{ countTotalDiceSum() };
    int illegalAmount{ countDiceTotal() - 100 };
    bool checkUserDiceCountGateway = false;

    if ( countDiceTotal() > 100 ){
        std::cout << "Warning!\n";
        std::cout << "Total dice count too high(Max: 100)\n";
        std::cout << "User input for command 'add' greater than legal limit by '" << illegalAmount << "'\n";
    }
    else {
        checkUserDiceCountGateway = true;
    }

    return { checkUserDiceCountGateway, illegalAmount};

}

//  definition for called funcition notifyAddUserDice()
//  function is void, returns no value
//  
void notifyAddUserDice( int userAmount, std::string userDieName, int countDieSingle ){

    std::cout << "[ '" << userAmount << "' " << userDieName << " added to dice roll. ]\n";
    std::cout << "Total dice count is: " << countDiceTotal() << "\n";
    std::cout << userDieName << " count is: " << countDieSingle << "\n";

}

//  definition for called function notifyWarningAddUserDice()
//  function is void, returns no value
//  
void warningAddUserDice( int newAmount ){

    printBorderLine();
    std::cout << "Adding '" << newAmount << "' dice to roster instead . . . \n";

}

//  definition for called function multiplierAddUserDice()
//  function is void, returns no value
//  function receives string value from caller function, locally named 'userDiceInput'
//  
void multiplierAddUserDice( std::string userDiceInput ){
    std::string userAmountConversion{ userDiceInput.back() };
    int userAmount = std::stoi( userAmountConversion );
    if ( userDiceInput.starts_with( "d20_" ) ){
        userDiceRoster[0] += userAmount;
        auto [ checkDiceCount, illegalAmount ]{ checkUserDiceCount() };
        if ( checkDiceCount == true ){
            notifyAddUserDice( userAmount, userDiceName[0], userDiceRoster[0] );
        }
        else {
            userDiceRoster[0] -= illegalAmount;
            int newAmount{ userAmount - illegalAmount };
            warningAddUserDice( newAmount );
            if ( newAmount > 0 ){
                printBorderLine();
                notifyAddUserDice( newAmount, userDiceName[0], userDiceRoster[0] );
            }
        }
    }
    else if ( userDiceInput.starts_with( "d12_" ) ){
        userDiceRoster[1] += userAmount;
        auto [ checkDiceCount, illegalAmount ]{ checkUserDiceCount() };
        if ( checkDiceCount == true ){
            notifyAddUserDice( userAmount, userDiceName[1], userDiceRoster[1] );
        } 
        else {
            userDiceRoster[1] -= illegalAmount;
            int newAmount{ userAmount - illegalAmount };
            warningAddUserDice( newAmount );
            if ( newAmount > 0 ){
                printBorderLine();
                notifyAddUserDice( newAmount, userDiceName[1], userDiceRoster[1] );
            }
        }
    }
    else if ( userDiceInput.starts_with( "d10_" ) ){
        userDiceRoster[2] += userAmount;
        auto [ checkDiceCount, illegalAmount ]{ checkUserDiceCount() };
        if ( checkDiceCount == true ){
            notifyAddUserDice( userAmount, userDiceName[2], userDiceRoster[2] );
        }
        else {
            userDiceRoster[2] -= illegalAmount;
            int newAmount{ userAmount - illegalAmount };
            warningAddUserDice( newAmount );
            if ( newAmount > 0 ){
                printBorderLine();
                notifyAddUserDice( newAmount, userDiceName[2], userDiceRoster[2] );
            }
        }
    }
    else if ( userDiceInput.starts_with( "d8_" ) ){
        userDiceRoster[3] += userAmount;
        auto [ checkDiceCount, illegalAmount ]{ checkUserDiceCount() };
        if ( checkDiceCount == true ){
            notifyAddUserDice( userAmount, userDiceName[3], userDiceRoster[3] );
        }
        else {
            userDiceRoster[3] -= illegalAmount;
            int newAmount{ userAmount - illegalAmount };
            warningAddUserDice( newAmount );
            if ( newAmount > 0 ){
                printBorderLine();
                notifyAddUserDice( newAmount, userDiceName[3], userDiceRoster[3] );
            }
        }
    }
    else if ( userDiceInput.starts_with( "d6_" ) ){
        userDiceRoster[4] += userAmount;
        auto [ checkDiceCount, illegalAmount ]{ checkUserDiceCount() };
        if ( checkDiceCount == true ){
            notifyAddUserDice( userAmount, userDiceName[4], userDiceRoster[4] );
        }
        else {
            userDiceRoster[4] -= illegalAmount;
            int newAmount{ userAmount - illegalAmount };
            warningAddUserDice( newAmount );
            if ( newAmount > 0 ){
                printBorderLine();
                notifyAddUserDice( newAmount, userDiceName[4], userDiceRoster[4] );
            }
        }
    }
    else if ( userDiceInput.starts_with( "d4_" ) ){
        userDiceRoster[5] += userAmount;
        auto [ checkDiceCount, illegalAmount ]{ checkUserDiceCount() };
        if ( checkDiceCount == true ){
            notifyAddUserDice( userAmount, userDiceName[5], userDiceRoster[5] );
        }
        else {
            userDiceRoster[5] -= illegalAmount;
            int newAmount{ userAmount - illegalAmount };
            warningAddUserDice( newAmount );
            if ( newAmount > 0 ){
                printBorderLine();
                notifyAddUserDice( newAmount, userDiceName[5], userDiceRoster[5] );
            }
        }
    }
}

//  definition for called function userDiceInput()
//  function is void, returns no value
//  function receives string value from caller, string value locally named 'userDiceInput'
//  -   at start, if 'userDiceInput' is "d20", function calls printBorderLine(), after return, function adds 1 to 'countD20' & creates int 'countDiceTotal' with the value of the sum of 'countD20', 'countD12', 'countD10', 'countD8', 'countD6', & 'countD4'... 
//  -   ... function enters if statement, if statement passes 'countDiceTotal' to bool function 'userDiceCountCompare'
//  -   ... if 'userDiceCountCompare' returns true, then function prints "[ d20 added to dice roll. ]", prints new-line, prints "Total dice count is: 'countDiceTotal' ", prints new-line, prints "d20 count is: 'countD20' ", & function ends, returns to caller
//  -   ... else('countDiceCountCompare' returns false), function removes 1 from 'countD20', & function ends, returns to caller
//  -   else if 'userDiceInput' is "d12", function calls printBorderLine(), after return, function adds 1 to 'countD12' & creates int 'countDiceTotal' with the value of the sum of 'countD20', 'countD12', 'countD10', 'countD8', 'countD6', & 'countD4'...
//  -   ... function enters if statement, if statement passes 'countDiceTotal' to bool function 'userDiceCountCompare'
//  -   ... if 'userDiceCountCompare' returns true, then function prints "[ d12 added to dice roll. ]", prints new-line, prints "Total dice count is: 'countDiceTotal' ", prints new-line, prints "d12 count is: 'countD12' ", & function ends, returns to caller
//  -   else if 'userDiceInput' is "d10", 
//  
void addUserDice( std::string userDiceInput ){
    clearConsoleScreen();
    printBorderLine();
    if ( userDiceInput == "d20" ){
        userDiceRoster[0]++;
        auto [ checkDiceCount, illegalAmount ]{ checkUserDiceCount() };
        if ( checkDiceCount == true ){
            notifyAddUserDice( 1, userDiceInput, userDiceRoster[0] );
        }
        else {
            userDiceRoster[0] -= illegalAmount;
        }
    }
    else if ( userDiceInput.starts_with( "d20_" ) && std::isdigit( userDiceInput.back() ) ){
        multiplierAddUserDice( userDiceInput );
    }
    else if ( userDiceInput == "d12" ){
        userDiceRoster[1]++;
        auto [ checkDiceCount, illegalAmount ]{ checkUserDiceCount() };
        if ( checkDiceCount == true ){
            notifyAddUserDice( 1, userDiceInput, userDiceRoster[1] );
        }
        else {
            userDiceRoster[1] -= illegalAmount;
        }
    }
    else if ( userDiceInput.starts_with( "d12_" ) && std::isdigit( userDiceInput.back() ) ){
        multiplierAddUserDice( userDiceInput );
    }
    else if ( userDiceInput == "d10" ){
        userDiceRoster[2]++;
        auto [ checkDiceCount, illegalAmount ]{ checkUserDiceCount() };
        if ( checkDiceCount == true ){
            notifyAddUserDice( 1, userDiceInput, userDiceRoster[2] );
        }
        else {
            userDiceRoster[2] -= illegalAmount;
        }
    }
    else if ( userDiceInput.starts_with( "d10_" ) && std::isdigit( userDiceInput.back() ) ){
        multiplierAddUserDice( userDiceInput );
    }
    else if ( userDiceInput == "d8" ){
        userDiceRoster[3]++;
        auto [ checkDiceCount, illegalAmount ]{ checkUserDiceCount() };
        if ( checkDiceCount == true ){
            notifyAddUserDice( 1, userDiceInput, userDiceRoster[3] );
        }
        else {
            userDiceRoster[3] -= illegalAmount;
        }
    }
    else if ( userDiceInput.starts_with( "d8_" ) && std::isdigit( userDiceInput.back() ) ){
        multiplierAddUserDice( userDiceInput );
    }
    else if ( userDiceInput == "d6" ){
        userDiceRoster[4]++;
        auto [ checkDiceCount, illegalAmount ]{ checkUserDiceCount() };
        if ( checkDiceCount == true){
            notifyAddUserDice( 1, userDiceInput, userDiceRoster[4] );
        }
        else {
            userDiceRoster[4] -= illegalAmount;
        }
    }
    else if ( userDiceInput.starts_with( "d6_" ) && std::isdigit( userDiceInput.back() ) ){
        multiplierAddUserDice( userDiceInput );
    }
    else if ( userDiceInput == "d4" ){
        userDiceRoster[5]++;
        auto [ checkDiceCount, illegalAmount ]{ checkUserDiceCount() };
        if ( checkDiceCount == true ){
            notifyAddUserDice( 1, userDiceInput, userDiceRoster[5] );
        }
        else {
            userDiceRoster[5] -= illegalAmount;
        }
    }
    else if ( userDiceInput.starts_with( "d4_" ) && std::isdigit( userDiceInput.back() ) ){
        multiplierAddUserDice( userDiceInput );
    }
    else if ( !userDiceInput.starts_with( "d20" ) && !userDiceInput.starts_with( "d12" ) && !userDiceInput.starts_with( "d10" ) && !userDiceInput.starts_with( "d8" ) && !userDiceInput.starts_with( "d6" ) && !userDiceInput.starts_with( "d4" ) && !std::isdigit( userDiceInput.back() ) ){
        std::cout << "Invalid command parameters!\n";
        std::cout << "If you are unfamiliar with the commands, type command 'help'\n";
    }
}

//  definition for called function checkUserDieCountNegative()
//  function is bool, returns true or false value to caller function
//  function receives string value & int value from caller function, locally named 'userDieName' & 'countDieSingle', respectively
//  
std::tuple<bool, int> checkUserDieCountNegative( std::string userDieName, int countDieSingle ){

    int illegalAmount{};
    bool checkUserDieCountNegative = false;

    if ( countDieSingle < 0 ){
        for ( int x = countDieSingle; x < 0; x++){
            illegalAmount++;
        }
        std::cout << "Warning!\n";
        std::cout << userDieName << " count less than 0.\n";
        std::cout << "User input for command 'subtract' greater than legal limit by '" << illegalAmount << "'\n";
    }
    else {
        checkUserDieCountNegative = true;
    }

    return { checkUserDieCountNegative, illegalAmount };

}

//  definition for called function notifySubtractUserDice()
//  function is void, returns no value
//  
void notifySubtractUserDice( int userAmount, std::string userDieName, int countDieSingle ){

    std::cout << "[ '" << userAmount << "' " << userDieName << " removed from dice roll. ]\n";
    std::cout << "Total dice count is: " << countDiceTotal() << "\n";
    std::cout << userDieName << " count is: " << countDieSingle << "\n";

}

//  definition for called function errorSubtractUserDice()
//  function is void, returns no value
//  function receives string value from caller function, locally named 'userDiceInput'
//  
void errorSubtractUserDice( std::string userDieName ){

    std::cout << "Invalid operation!\n";
    std::cout << userDieName << " count already 0.\n";

}

//  definition for called function warningSubtractUserDice()
//  function is void, returns no value
//  
void warningSubtractUserDice( int newAmount ){

    printBorderLine();
    std::cout << "Subtracting '" << newAmount << "' dice from roster instead . . . \n";

}

//  definition for called function multiplierSubtractUserDice()
//  function is void, returns no value
//  function receives string value from caller function, locally named 'userDiceInput'
//  
void multiplierSubtractUserDice( std::string userDiceInput ){
    std::string userAmountConversion{ userDiceInput.back() };
    int userAmount{ std::stoi( userAmountConversion ) };
    if ( userDiceInput.starts_with( "d20_" ) ){
        userDiceRoster[0] -= userAmount;
        auto [ checkDieNegative, illegalAmount ]{ checkUserDieCountNegative( userDiceName[0], userDiceRoster[0] ) };
        if ( checkDieNegative == true ){
            notifySubtractUserDice( userAmount, userDiceName[0], userDiceRoster[0] );
        }
        else {
            userDiceRoster[0] += illegalAmount;
            int newAmount{ userAmount - illegalAmount };
            warningSubtractUserDice( newAmount );
            if ( newAmount > 0 ){
                printBorderLine();
                notifySubtractUserDice( newAmount, userDiceName[0], userDiceRoster[0] );
            }
        }
    }
    else if ( userDiceInput.starts_with( "d12_" ) ){
        userDiceRoster[1] -= userAmount;
        auto [ checkDieNegative, illegalAmount ]{ checkUserDieCountNegative( userDiceName[1], userDiceRoster[1] ) };
        if ( checkDieNegative == true ){
            notifySubtractUserDice( userAmount, userDiceName[1], userDiceRoster[1] );
        }
        else {
            userDiceRoster[1] += illegalAmount;
            int newAmount{ userAmount - illegalAmount };
            warningSubtractUserDice( newAmount );
            if ( newAmount > 0 ){
                printBorderLine();
                notifySubtractUserDice( newAmount, userDiceName[1], userDiceRoster[1] );
            }
        }
    }
    else if ( userDiceInput.starts_with( "d10_" ) ){
        userDiceRoster[2] -= userAmount;
        auto [ checkDieNegative, illegalAmount ]{ checkUserDieCountNegative( userDiceName[2], userDiceRoster[2] ) };
        if ( checkDieNegative == true ){
            notifySubtractUserDice( userAmount, userDiceName[2], userDiceRoster[2] );
        }
        else {
            userDiceRoster[2] += illegalAmount;
            int newAmount{ userAmount - illegalAmount };
            warningSubtractUserDice( newAmount );
            if ( newAmount > 0 ){
                printBorderLine();
                notifySubtractUserDice( newAmount, userDiceName[2], userDiceRoster[2] );
            }
        }
    }
    else if ( userDiceInput.starts_with( "d8_" ) ){
        userDiceRoster[3] -= userAmount;
        auto [ checkDieNegative, illegalAmount ]{ checkUserDieCountNegative( userDiceName[3], userDiceRoster[3] ) };
        if ( checkDieNegative == true ){
            notifySubtractUserDice( userAmount, userDiceName[3], userDiceRoster[3] );
        }
        else {
            userDiceRoster[3] += illegalAmount;
            int newAmount{ userAmount - illegalAmount };
            warningSubtractUserDice( newAmount );
            if ( newAmount > 0 ){
                printBorderLine();
                notifySubtractUserDice( newAmount, userDiceName[3], userDiceRoster[3] );
            }
        }
    }
    else if ( userDiceInput.starts_with( "d6_" ) ){
        userDiceRoster[4] -= userAmount;
        auto [ checkDieNegative, illegalAmount ]{ checkUserDieCountNegative( userDiceName[4], userDiceRoster[4] ) };
        if ( checkDieNegative == true ){
            notifySubtractUserDice( userAmount, userDiceName[4], userDiceRoster[4] );
        }
        else {
            userDiceRoster[4] += illegalAmount;
            int newAmount{ userAmount - illegalAmount };
            warningSubtractUserDice( newAmount );
            if ( newAmount > 0 ){
                printBorderLine();
                notifySubtractUserDice( newAmount, userDiceName[4], userDiceRoster[4] );
            }
        }
    }
    else if ( userDiceInput.starts_with( "d4_" ) ){
        userDiceRoster[5] -= userAmount;
        auto [ checkDieNegative, illegalAmount ]{ checkUserDieCountNegative( userDiceName[5], userDiceRoster[5] ) };
        if ( checkDieNegative == true ){
            notifySubtractUserDice( userAmount, userDiceName[5], userDiceRoster[5] );
        }
        else {
            userDiceRoster[5] += illegalAmount;
            int newAmount{ userAmount - illegalAmount };
            warningSubtractUserDice( newAmount );
            if ( newAmount > 0 ){
                printBorderLine();
                notifySubtractUserDice( newAmount, userDiceName[5], userDiceRoster[5] );
            }
        }
    }
}

//  definition for called function subtractUserDice()
//  function is void, returns no value
//  
void subtractUserDice( std::string userDiceInput ){
    clearConsoleScreen();
    printBorderLine();
    if ( userDiceInput == "d20" && userDiceRoster[0] > 0 ){
        userDiceRoster[0]--;
        notifySubtractUserDice( 1, userDiceName[0], userDiceRoster[0] );
    }
    else if ( userDiceInput.starts_with( "d20_" ) && std::isdigit( userDiceInput.back() ) && userDiceRoster[0] > 0 ){
        multiplierSubtractUserDice( userDiceInput );
    }
    else if ( userDiceInput.starts_with( "d20" ) ){
        errorSubtractUserDice( userDiceName[0] );
    }
    else if ( userDiceInput == "d12" && userDiceRoster[1] > 0 ){
        userDiceRoster[1]--;
        notifySubtractUserDice( 1, userDiceName[1], userDiceRoster[1] );
    }
    else if ( userDiceInput.starts_with( "d12_" ) && std::isdigit( userDiceInput.back() ) && userDiceRoster[1] > 0 ){
        multiplierSubtractUserDice( userDiceInput );
    }
    else if ( userDiceInput.starts_with( "d12" ) ){
        errorSubtractUserDice( userDiceName[1] );
    }
    else if ( userDiceInput == "d10" && userDiceRoster[2] > 0 ){
        userDiceRoster[2]--;
        notifySubtractUserDice( 1, userDiceName[2], userDiceRoster[2] );
    }
    else if ( userDiceInput.starts_with( "d10_" ) && isdigit( userDiceInput.back() ) && userDiceRoster[2] > 0 ){
        multiplierSubtractUserDice( userDiceInput );
    }
    else if ( userDiceInput.starts_with( "d10" ) ){
        errorSubtractUserDice( userDiceName[2] );
    }
    else if ( userDiceInput == "d8" && userDiceRoster[3] > 0 ){
        userDiceRoster[3]--;
        notifySubtractUserDice( 1, userDiceName[3], userDiceRoster[3] );
    }
    else if ( userDiceInput.starts_with( "d8_" ) && std::isdigit( userDiceInput.back() ) && userDiceRoster[3] > 0 ){
        multiplierSubtractUserDice( userDiceInput );
    }
    else if ( userDiceInput.starts_with( "d8" ) ){
        errorSubtractUserDice( userDiceName[3] );
    }
    else if ( userDiceInput == "d6" && userDiceRoster[4] > 0){
        userDiceRoster[4]--;
        notifySubtractUserDice( 1, userDiceName[4], userDiceRoster[4] );
    }
    else if ( userDiceInput.starts_with( "d6_" ) && std::isdigit( userDiceInput.back() ) && userDiceRoster[4] > 0 ){
        multiplierSubtractUserDice( userDiceInput );
    }
    else if ( userDiceInput.starts_with( "d6" ) ){
        errorSubtractUserDice( userDiceName[4] );
    }
    else if ( userDiceInput == "d4" && userDiceRoster[5] > 0 ){
        userDiceRoster[5]--;
        notifySubtractUserDice( 1, userDiceName[5], userDiceRoster[5] );
    }
    else if ( userDiceInput.starts_with( "d4_" ) && std::isdigit( userDiceInput.back() ) && userDiceRoster[5] > 0 ){
        multiplierSubtractUserDice( userDiceInput );
    }
    else if ( userDiceInput.starts_with( "d4" ) ){
        errorSubtractUserDice( userDiceName[5] );
    }
    else if ( !userDiceInput.starts_with( "d20" ) && !userDiceInput.starts_with( "d12" ) && !userDiceInput.starts_with( "d10" ) && !userDiceInput.starts_with( "d8" ) && !userDiceInput.starts_with( "d6" ) && !userDiceInput.starts_with( "d4" ) && !std::isdigit( userDiceInput.back() ) ){
        std::cout << "Invalid command parameters!\n";
        std::cout << "If you are unfamiliar with the commands, type command 'help'\n";
    }
}

//  definition for called function clearUserDice()
//  function is void, returns no value
//  function receives string value from caller function, locally named 'userDiceInput'
//  
void clearUserDice( std::string userDiceInput ){
    clearConsoleScreen();
    if ( userDiceInput == "all" ){
        for ( std::size_t i = 0; i < userDiceRoster.size(); i++ ){
            while ( userDiceRoster[i] > 0 ){
                userDiceRoster[i]--;
            }
        }
    }
    else if ( userDiceInput == "d20" ){
        while ( userDiceRoster[0] > 0 ){
            userDiceRoster[0]--;
        }
    }
    else if ( userDiceInput == "d12" ){
        while ( userDiceRoster[1] > 0 ){
            userDiceRoster[1]--;
        }
    }
    else if ( userDiceInput == "d10" ){
        while ( userDiceRoster[2] > 0 ){
            userDiceRoster[2]--;
        }
    }
    else if ( userDiceInput == "d8" ){
        while ( userDiceRoster[3] > 0 ){
            userDiceRoster[3]--;
        }
    }
    else if ( userDiceInput == "d6" ){
        while ( userDiceRoster[4] > 0 ){
            userDiceRoster[4]--;
        }
    }
    else if ( userDiceInput == "d4" ){
        while ( userDiceRoster[5] > 0 ){
            userDiceRoster[5]--;
        }
    }
    else if ( userDiceInput != "all" && userDiceInput != "d20" && userDiceInput != "d12" && userDiceInput != "d10" && userDiceInput != "d8" && userDiceInput != "d6" && userDiceInput != "d4" ){
        printBorderLine();
        std::cout << "Invalid command parameters!\n";
        std::cout << "If you are unfamiliar with the commands, type command 'help'\n";
    }

}

//  definition for called function programMagicDiceRoller()
//  function is void, returns no value
//  - at start, function creates bool variable 'programTermination' and intializes it as false
//  - function creates string variables 'userDiceCommand' & 'userDiceInput' & list-initializes them as 0
//  - function enters while statement(!programTermination), statement loops while 'programTermination' is false
//  - function enters do while statement
//  - do statement calls printBorderLine(), after return, prints "Enter command for Magic: The Gathering dice roller: ", & prompts user for input into 'userDiceCommand'
//  - if 'userDiceCommand' is not "add", "subtract", "print", "roll", "help", or "quit", statement prints error message, if statement exits, do statement ends
//  - while statement loops do statement while user input into 'userDiceCommand' is not "add", "subtract", "print", "roll", "help", or "quit"
//  - after exit from do while statement, if 'userDiceCommand' is "add", function prompts user for input into 'userDiceInput', & passes 'userDiceInput' to called void function addUserDice(), after return, while(!programTermination) loops
//  - else if 'userDiceCommand' is "subtract", function prompts user for input into 'userDiceInput', & passes 'userDiceInput' to called void function subtractUserDice(), after return, while(!programTermination) loops
//  - else if 'userDiceCommand' is "print", function prompts user for input into 'userDiceInput', & passes 'userDiceInput' to called void function printUserDice(), after return, while(!programTermination) loops
//  - else if 'userDiceCommand' is "roll", function calls void function rollUserDice(), after return, while(!programTermination) loops
//  - else if 'userDiceCommand' is "help", function calls printBorderLine() & prints help manual, while(!programTermination) loops
//  - else if 'userDiceCommand' is "quit", function prints "Exiting program . . . . . ", prints new-line, clears the buffer, & sets 'programTermination' to true, while(!programTermination) exits & function ends, returns to caller
//  
void programMagicDiceRoller(){

    clearConsoleScreen();

    bool programTermination = false;

    std::string userDiceCommand{};
    std::string userDiceInput{};

    while (!programTermination){
        do {
            printBorderLine();
            std::cout << "Enter command for Magic: The Gathering dice roller: ";
            std::cin >> userDiceCommand;
            if ( userDiceCommand != "add" && userDiceCommand != "subtract" && userDiceCommand != "print" && userDiceCommand != "roll" && userDiceCommand != "clear" && userDiceCommand != "help" && userDiceCommand != "quit" ){
                clearConsoleScreen();
                printBorderLine();
                std::cout << "Invalid command!\n";
                std::cout << "If you are unfamiliar with the commands, type command 'help'.\n";
            }
        } while ( userDiceCommand != "add" && userDiceCommand != "subtract" && userDiceCommand != "print" && userDiceCommand != "roll" && userDiceCommand != "clear" && userDiceCommand != "help" && userDiceCommand != "quit" );

        if ( userDiceCommand == "add" ){
            std::cin >> userDiceInput;
            addUserDice( userDiceInput );
        }
        else if ( userDiceCommand == "subtract" ){
            std::cin >> userDiceInput;
            subtractUserDice( userDiceInput );
        } 
        else if ( userDiceCommand == "print" ){
            std::cin >> userDiceInput;
            clearConsoleScreen();
            printBorderLine();
            if ( userDiceInput == "all" ){
                std::cout << "Total dice count is: " << countDiceTotal() << "\n";
                for ( std::size_t i = 0; i < userDiceRoster.size(); i++ ){
                    std::cout << userDiceName[i] << " count is: " << userDiceRoster[i] << "\n";
                }
            }
            else if ( userDiceInput == "total" ){
                std::cout << "Total dice count is: " << countDiceTotal() << "\n";
            }
            else if ( userDiceInput == "d20" ){
                std::cout << "d20 count is: " << userDiceRoster[0] << "\n";
            }
            else if ( userDiceInput == "d12" ){
                std::cout << "d12 count is: " << userDiceRoster[1] << "\n";
            }
            else if ( userDiceInput == "d10" ){
                std::cout << "d10 count is: " << userDiceRoster[2] << "\n";
            }
            else if ( userDiceInput == "d8" ){
                std::cout << "d8 count is: " << userDiceRoster[3] << "\n";
            }
            else if ( userDiceInput == "d6" ){
                std::cout << "d6 count is: " << userDiceRoster[4] << "\n";
                }
            else if ( userDiceInput == "d4" ){
                std::cout << "d4 count is: " << userDiceRoster[5] << "\n";
            }
            else if ( userDiceInput != "all" && userDiceInput != "total" && userDiceInput != "d20" && userDiceInput != "d12" && userDiceInput != "d10" && userDiceInput != "d8" && userDiceInput != "d6" && userDiceInput != "d4" ){
                std::cout << "Invalid command parameters!\n";
                std::cout << "If you are unfamiliar with the commands, type command 'help'.\n";
            }
        }
        else if ( userDiceCommand == "roll" ){
            std::cin >> userDiceInput;
            rollUserDice( userDiceInput );
        }
        else if ( userDiceCommand == "clear" ){
            std::cin >> userDiceInput;
            clearUserDice( userDiceInput );
        }
        else if ( userDiceCommand == "help" ){
            clearConsoleScreen();
            printBorderLine();
            std::cout << "This is a program for rolling various types of dice used in games like 'MTG' & 'D&D', including 'd20', 'd12', 'd10', 'd8', 'd6', & 'd4', respectively.\n";
            std::cout << "Program takes up to 100 dice for rolling at a time.\n";
            printBorderLine();
            std::cout << "Available commands include: \n";
            std::cout << "      ~ type 'add' or 'subtract' followed by die type(e.g. 'add d20', 'subtract d8') to add/subtract that die type to/from dice roster.\n";
            std::cout << "      ~ ...    append '_x' after die type, where 'x' is the number(1-9) of dice you want to add/subtract to/from roster(e.g. 'add d12_7', 'subtract d6_3' ).\n";
            std::cout << "      ~ type 'print' followed by 'all', 'total', or die type. 'print all' prints list of all dice totals, 'print total' prints only the cumulative total of all dice, \n";
            std::cout << "      ~ ...    & providing die type(e.g. 'print d20', 'print d4') prints the total for that type.\n";
            std::cout << "      ~ type 'roll' followed by 'all' or die type to roll selected dice in roster(e.g. 'roll all', 'roll d6' ). If no dice are in roster, produces error message.\n";
            std::cout << "      ~ type 'clear' followed by 'all' or die type(e.g. 'clear all', 'clear d10' ). 'clear' sets specified dice types to 0.\n";
            std::cout << "      ~ type 'quit' to exit dice roller & return to main menu. On 'quit', program will remove all dice from roster.\n";
        }
        else if ( userDiceCommand == "quit" ){
            clearUserDice( "all" );
            printBorderLine();
            std::cout << "Exiting dice roller . . . . . " << std::endl;
            programTermination = true;
        }

    }

}
