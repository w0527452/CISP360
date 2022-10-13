// Mark Chouinard | W0527452 | 10/12/22
// M06 Lab | 2 Player Tic Tac Toe game

#include<iostream>

using namespace std;
// Init board & other vars
char board[3][3] = {{'*', '*', '*'},
                    {'*', '*', '*'},
                    {'*', '*', '*'}};
char turn = 'X';
int row, column;
bool draw = false;

// Function signatures
int validateNum(int);

bool playing();

/**
 * Show the board
 *
 * There must be a better way to lay this out
 */
void displayBoard() {

    cout << "\n";
    cout << "     TIC   TAC   TOE" << endl;
    cout << "\n";
    cout << "\t  0  |  1  |  2  \n";
    cout << "\t-----|-----|-----\n";
    cout << "0\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "   \n";
    cout << "\t_____|_____|_____\n";
    cout << "1\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "   \n";
    cout << "\t_____|_____|_____\n";
    cout << "2\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "   \n";
}

/**
 * Player chooses a square
 */
void playerMove() {
    if (turn == 'X')
        cout << "\n\tPlayer 1: ";
    if (turn == 'O')
        cout << "\n\tPlayer 2: ";

    cout << "Select a square to place an " << turn << ": " << endl;

    cout << "Which row? ";
    // Make sure we get a valid choice
    row = validateNum(row);
    cout << "Which column? ";
    // Make sure we get a valid choice
    column = validateNum(column);

    if (turn == 'X' && board[row][column] == '*') {
        board[row][column] = 'X';
        turn = 'O';
    } else if (turn == 'O' && board[row][column] == '*') {
        board[row][column] = 'O';
        turn = 'X';
    } else {
        cout << "\t\tChoose an empty square.\n\n";
        playerMove();
    }
    // Display board with updated array elements
    displayBoard();

    playing();
}

/**
 * Get valid user input
 *
 * @param int num
 * @return int
 */
int validateNum(int num) {

    int low = 0, high = 2;
    while (!(cin >> num) || (num < low || num > high)) {
        cout << "Error. Enter a number from " << low << " to " << high << ": ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return num;
}

/**
 * Check if game should continue
 *
 * @return bool
 */
bool playing() {
//    cout << "TURN: " << turn << endl;

    // Check winner horizontally and vertically
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] != '*' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) ||
            (board[0][i] != '*' && board[0][i] == board[1][i] && board[0][i] == board[2][i])) {
            // Somebody won, stop playing
            return false;
        }

    }
    // Check winner diagonally
    if ((board[0][0] != '*' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
        (board[0][2] != '*' && board[0][2] == board[1][1] && board[0][0] == board[2][0])) {
        // Somebody won, stop playing
        return false;
    }

    // Continue playing if we still have squares to be played since nobody has won yet
    for (auto &i: board) {
        for (int j = 0; j < 3; j++) {
            if (i[j] == '*')
                return true;
        }
    }

    // Nobody won, no empty squares
    draw = true;
    // Nothing more to play
    return false;
}

/**
 * Display Winner
 */
void displayResults() {
    if (turn == 'X' && !draw) {
        cout << "\nPlayer 2 wins\n";
    } else if (turn == 'O' && !draw) {
        cout << "\nPlayer 1 wins\n";
    } else {
        cout << "\nDraw\n";
    }
}

int main() {
    // Display board
    displayBoard();
    // Start the game
    while (playing()) {
        playerMove();
    }
    // Display results
    displayResults();

    return 0;

}
