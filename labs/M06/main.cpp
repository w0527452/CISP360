#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void showboard();

const int ROW = 3;
const int COL = 3;
bool empty = true, draw = false;
char board[ROW][COL] = {{'*', '*', '*'},
                         {'*', '*', '*'},
                         {'*', '*', '*'}};

void init() {
    string Player1;
    string Player2;
    int ROW = 3;
    int COL = 3;
    char Turn = 'X';
    int num = 0;



    cout << "Player 1 name: ";
    cin >> Player1;
    cout << endl;
    cout << Player1 << ", you are X and will go first.";
    cout << endl;
    cout << endl;


    cout << "Player 2 name: ";
    cin >> Player2;
    cout << endl;
    cout << Player2 << ", you are O";
    cout << endl << endl;

    showboard();

    do {
        if (!empty) {
            cout << "Choose an empty square" << endl;
        }
        cout << "To choose a square, enter in the row and column number separated by a space: ";
        cin >> ROW;
        cin >> COL;
        if (board[ROW][COL] == '*') {
            empty = true;
            board[ROW][COL] = Turn;
            if (Turn == 'X')
                Turn = 'O';
            else
                Turn = 'X';
        } else {
            empty = false;
        }
        cout << endl;
        showboard();

    } while (true);

    showboard();

}

void showboard() {
    cout << "     0   1   2";
    cout << endl << endl;
    cout << " 0  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "   ___|___|___\n";
    cout << " 1  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "   ___|___|___\n";
    cout << " 2  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    cout << "      |" << "   |" << endl;
}

bool gameover() {
    //checking the win for Simple Rows and Simple Column
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] ||
            board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;

    //checking the win for both diagonal

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] ||
        board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    //Checking the game is in continue mode or not
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    //Checking the if game already draw
    draw = true;
    return false;
}

int main() {
    init();

    return 0;
}
