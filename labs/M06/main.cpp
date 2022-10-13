#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void showboard();

const int ROW = 3;
const int COL = 3;
char Gboard[ROW][COL] = {{'*', '*', '*'},
                         {'*', '*', '*'},
                         {'*', '*', '*'}};

void init() {
    string Player1;
    string Player2;
    int ROW = 3;
    int COL = 3;
    char Turn = 'X';
    int num = 0;


    cout << "Let's play Tic-Tac-Toe!\nPlayer 1 enter your name: ";
    cin >> Player1;
    cout << endl;
    cout << Player1 << ", you are X's! You will also have the first turn.";
    cout << endl;
    cout << endl;


    cout << "Player 2, enter your name: ";
    cin >> Player2;
    cout << endl;
    cout << Player2 << ", you are O's!";
    cout << endl << endl;

    showboard();

    do {
        cout << "To choose a position enter in the row number \n[SPACE] then the column number: ";
        cin >> ROW;
        cin >> COL;
        if (Gboard[ROW][COL] == '*') {
            Gboard[ROW][COL] = Turn;
            if (Turn == 'X')
                Turn = 'O';
            else
                Turn = 'X';
        }
        cout << endl;
        showboard();

    } while (true);

    showboard();

}

void showboard() {
    cout << "     0   1   2";
    cout << endl << endl;
    cout << " 0  " << Gboard[0][0] << " | " << Gboard[0][1] << " | " << Gboard[0][2] << endl;
    cout << "   ___|___|___\n";
    cout << " 1  " << Gboard[1][0] << " | " << Gboard[1][1] << " | " << Gboard[1][2] << endl;
    cout << "   ___|___|___\n";
    cout << " 2  " << Gboard[2][0] << " | " << Gboard[2][1] << " | " << Gboard[2][2] << endl;
    cout << "      |" << "   |" << endl;
}

int main() {
    init();

    return 0;
}
