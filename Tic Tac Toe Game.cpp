#include <iostream>
using namespace std;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'}; // The game board with initial values

int checkwin(); // Function prototype
void board();   // Function prototype

int main()
{
    int player = 1, i, choice;

    char mark;
    
    do
    {
        board(); // Display the game board
        player = (player % 2) ? 1 : 2; // Alternates between players 1 and 2

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O'; // Assign 'X' or 'O' based on current player

        // Check if the selected choice is valid and update the square
        if (choice >= 1 && choice <= 9 && square[choice] == char(choice + 48))
            square[choice] = mark;
        else
        {
            cout << "Invalid move ";

            player--; // Retry the same player's turn
            cin.ignore();
            cin.get();
        }
        
        i = checkwin(); // Check if there's a winner or a draw
        
        player++; // Move to the next player's turn
    } while (i == -1);
    
    board(); // Display the final game board
    
    if (i == 1)
        cout << "==>\aPlayer " << --player << " WINS!! ";
    else
        cout << "==>\aGame draw";

    cin.ignore();
    cin.get();
    return 0;
}

int checkwin()
{
    // Check for winning conditions
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                    && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1; // Game continues
}

void board()
{
    // Display the game board
    cout << "\n\n\t***********Tic Tac Toe*************\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}


