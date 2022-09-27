/**
 * Mark Chouinard | W0527452 | CISP 360 | M05 LAB | 09/26/22
 *
 * Write a program that lets the user play the game of Rock, Paper, Scissors against the computer.
 */

#include <iostream>
#include <random>

using namespace std;

const int ROCK = 1, PAPER = 2, SCISSORS = 3;

/**
 * Output menu and let player make a choice
 *
 * @return int
 */
int getPlayerChoice() {
    int choice;
    cout << "Choose Rock, Paper or Scissors\n";
    cout << "1. Rock\n2. Paper\n3. Scissors:\n";
    cin >> choice;

    return choice;
}

/**
 * Translate int choice into string
 *
 * @param int choice
 * @return string
 */
string translateChoice(int choice) {
    string option;

    switch (choice) {
        case ROCK:
            option = "Rock";
            break;
        case PAPER:
            option = "Paper";
            break;
        default:
            option = "Scissors";
    }

    return option;
}

/**
 * Translate string choice into int
 *
 * @param string choice
 * @return int
 */
int translateChoice(string choice) {
    int option;

    if ("Rock" == choice) {
        option = ROCK;
    } else if ("Paper" == choice) {
        option = PAPER;
    } else {
        option = SCISSORS;
    }

    return option;
}

/**
 * Obtain player's choice
 *
 * @return string
 */
string playerChoose() {
    int choice = getPlayerChoice();
    while (choice < 1 || choice > 3) {
        cout << "Invalid choice. ";
        choice = getPlayerChoice();
    }

    string option = translateChoice(choice);

    // Output player choice
    cout << "Your choice is " << option << endl;

    return option;

}

/**
 * Get player result of game
 *
 * @param int player
 * @param int computer
 * @return string
 */
string getPlayerResult(int player, int computer) {

    const string WIN = "You Win", LOSE = "You Lose", TIE = "Tie.  Play again.";
    string result;


    switch (player) {
        case 1:
            if (SCISSORS == computer) {
                result = WIN;
            } else if (PAPER == computer) {
                result = LOSE;
            } else {
                result = TIE;
            }
            break;
        case 2:
            if (ROCK == computer) {
                result = WIN;
            } else if (SCISSORS == computer) {
                result = LOSE;
            } else {
                result = TIE;
            }
            break;
        default:
            if (PAPER == computer) {
                result = WIN;
            } else if (ROCK == computer) {
                result = LOSE;
            } else {
                result = TIE;
            };
    }
    return result;
}

int main() {
    // seed
    srand(time(0));
    // Get computer choice
    int computer = rand() % 3 + 1;
    // Get player choice
    string player = playerChoose();
    // Output computer choice
    cout << "Computer's choice is " << translateChoice(computer) << endl << endl;
    // Get result string
    string result = getPlayerResult(translateChoice(player), computer);
    // Output result string
    cout << result << endl;

    return 0;
}
