   // NUMBER GUESSING GAME IN C++ 

#include <iostream> //  input/output stream library, which allows to perform input and output operations in C++.

#include <cstdlib> //   'cstdlib' provides general utilities including memory allocation and conversions

#include <ctime>   //   'ctime' provides functions for working with time and date

#include<stdlib.h> //   'stdlib.h' is an older C-style header that includes declarations used in this program

using namespace std; //  This line allows to use standard C++ symbols and classes without needing to prefix them with "std::"

int main(){          // Entry point of the program

    srand((unsigned int) time (NULL));  // This sets the seed for the random number generator, uses the current time that ensure that you get different random numbers each time you run the program
    
    int number = (rand()%100)+1;  // This line generates a random number between 1 and 100 and stores it in the variable number.  
    
    int guess = 0; // This initializes a variable guess to store the user's guessed number. It's initialized to 0 initially.
    
    do{             // This begins a do-while loop
    
        cout<< "Enter Guess(1-100):";  // This line prints a prompt, asking the user to input their guess.
        cin>>guess;
        if(guess>number)
        cout<<"Guess lower!"<<endl;
        else if (guess< number)
        cout<<"Guess higher!"<<endl;
        else
        cout<<"YOU WON!" <<endl;
        
    } while (guess!=number); // This line closes the do-while loop. The loop will continue as long as the user's guess is not equal to the generated number.
    
    cin.get();
    cout<<"EXIT";  // This line prints "EXIT" to the console.
    
    getchar();   // This line signifies the end of the main function and returns an exit status of 0 to indicate successful program execution to the operating system.6060
    return 0;
    }
