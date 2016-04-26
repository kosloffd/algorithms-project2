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

using std::ofstream;
using std::ifstream;

void printMenu();

int main(int argc, char *argv[]) {

    int debug = 1;                  // Used to print debugging information
    int amount = -1;                // Stores amount of money to be made from coins
    string str = "";                // Stores lines from txt argument
    string file = "";               // Name of file for record keeping

    // Used to print argument count and their values
    if (debug == 1) {
        cout << "\nThere are " << argc << " arguments.\n";
        for (int i = 0; i < argc; ++i) {
            cout << "\t" << i << "--> " << argv[i] << "\n";
        }
    }

    // Store argv[1], the file name as a string
    file = argv[1];

    // Set up tools to read and write from txt files
    ifstream fin;
    ofstream fout;
    fin.open(argv[1]);


    // Confirm successful opening of the .txt file
    if (!fin.is_open()) {
        cout << "\nThe text file " << file << " could not be opened. Try again.";
        exit(1);
    }

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



    switch(choice) {
        case 1:
            cout << "\nExecuting brute force algorithm." << endl;
            break;

        case 2:
            cout << "\nExecuting greedy algorithm." << endl;
            break;

        case 3:
            cout << "\nExecuting dynamic programming algorithm." << endl;
            break;

        case 0:
            cout << "\nExiting program. Good bye!" << endl;
            exit(0);

        default:
            cout << "You have entered an invalid menu choice. Please try again." << endl;
            exit(1);
    }


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
