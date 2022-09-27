/**
 * Mark Chouinard | CISP 360 | Lab M04 | 09/19/22
 *
 * Create a text file with random numbers and save it to your drive.  Write a program that opens the file, reads all of the numbers from the file, and calculates the following:

    The number of numbers in the file
    The sum of all of the numbers in the file (a running total)
    The average of all the numbers in the file

 */

#include <iostream>
#include <fstream>

using namespace std;

/**
 * Write 50 random numbers between 1 and 1000 to file
 */
void writeRandom() {
    // Seed the "random" generator
    srand(time(NULL));
    // Declare random var
    int random;
    // Open file
    ofstream outFile("random.txt");
    if (outFile) {
        // write 50 random numbers (1-100) to file
        for (int n = 0; n < 50; n++) {
            random = rand() % 1000 + 1;
            cout << "Writng line " << n + 1 << ": " << random << endl;
            outFile << random << endl;
        }
        // Close file
        outFile.close();
    } else {
        cout << "Error opening file\n";
    }
}

/**
 * Read numbers from file, perform calculations and display results
 */
void readRandom() {
    int number, sum = 0;
    float avg, count = 0;
    // Open file
    ifstream inputFile("random.txt");
    if (inputFile) {
        // Read numbers, increment sum and count by their respective values
        while (inputFile >> number) {
            sum += number;
            count++;
        }
        // Calc average
        avg = sum / count;
        // Output results
        cout << "There were " << count << " numbers in the file\n";
        cout << "The numbers totaled " << sum;
        cout << " with an average of " << avg << endl;
    } else {
        cout << "Error opening file\n";
    }
}

int main() {
//    writeRandom();
    readRandom();

    return 0;
}
