#include <iostream>

//  definition for called function printBorderLine()
//  function is void, returns no value
//  [ function prints a border-line that is 25 "- " long, then prints a new-line, & clears the buffer, returns to caller ]
//  - when called, function creates integer variable 'count' and inritializes it to 25
//  - function enters do while statement
//  - do statement prints "- " and subtracts one from 'count'
//  - while statement loops do statement while 'count' is greater than 0
//  - after exit from do while statement, function prints new-line & clears the buffers
//  - function ends, returns to caller
//  
void printBorderLine(){
    
    for ( int x = 0; x < 25; x++ ){
        std::cout << "- ";
    }

    /*
    //  int count = 25;

    do {
        std::cout << "- ";
        count--;
    } while ( count > 0 );
    */
   
    std::cout << std::endl;

}
