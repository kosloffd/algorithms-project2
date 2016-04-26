#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "bruteforce.h"
#include "utility.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

using std::vector;

using std::ofstream;
using std::ifstream;

void printMenu();

int main(int argc, char *argv[]) {

    int debug = 1;                  // Used to print debugging information
    int amount = -1;                // Stores amount of money to be made from coins
    int lineCount = -1;             // Number of lines used for looping algorithms
    string str = "";                // Stores lines from txt argument
    string filenameIn = "";         // Name of file for record keeping
    string filenameOut = "";        //

    vector<int> values;             // Vector to store coin denominations

    // Used to print argument count and their getValues
    if (debug == 1) {
        cout << "\nThere are " << argc << " arguments:\n";
        for (int i = 0; i < argc; ++i) {
            cout << "\t" << i << " --> " << argv[i] << "\n";
        }
    }
    // Store argv[1], the file name, as a string and create the name
    // for the output file, filenameIn + "change.txt"
    filenameIn = argv[1];
    filenameOut = argv[1];
    filenameOut.erase(filenameOut.end()-4, filenameOut.end());     // Erase .txt
    filenameOut += "change.txt";

    // Open the file input stream with argv[1], from the CLI
    ifstream fin;
    fin.open(argv[1]);

    // Open the output file and append the suffix "change.txt"
    ofstream fout;
    fout.open(filenameOut);

    // Confirm successful opening of the .txt file for input
    if (!fin.is_open()) {
        cout << "\nThe text file " << filenameIn << " could not be opened. Try again.";
        exit(1);
    }

    // Confirm successful opening of the .txt file for output
    if (!fout.is_open()) {
        cout << "\nThe text file " << filenameIn + ".txt" << " could not be opened. Try again.";
        exit(1);
    }

    // File is open, print some information to the screen
    if (fin.is_open()) {
        cout << "\nOpening " << argv[1] << "...";
        // get first line from argv[1] and store in str
        getline(fin, str);
        cout << "\nCalculating minimum coins to make amount " << amount << " from\n"
                "denominations of " << str << ".\n";
    }

    printMenu();
    int choice = -1;
    cin >> choice;

    // Get line count for files that contain multiple denominations/amounts
    lineCount = countLines(fin, filenameIn);

    switch(choice) {
        case 1:
            cout << "\nExecuting brute force algorithm." << endl;
            values = getValues(fin, filenameIn);
            break;

        case 2:
            cout << "\nExecuting greedy algorithm." << endl;
            break;

        case 3:
            cout << "\nExecuting dynamic programming algorithm." << endl;
            break;

        case 0:
            cout << "\nExiting program. Good bye!" << endl;
            fin.close();
            fout.close();
            exit(0);

        default:
            cout << "You have entered an invalid menu choice. Please try again." << endl;
            fin.close();
            fout.close();
            exit(1);
    }


    fin.close();
    fout.close();
    return 0;
}

void printMenu() {
    cout << "\nPlease select which algorithm to execute (using a number):\n"
            "\t1. Brute Force\n"
            // "\t2. Divide and Conquer\n"
            "\t2. Greedy\n"
            "\t3. Dynamic Programming\n"
            "\t0. Exit\n"
            "Choice: ";
}
