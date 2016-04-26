#include "bruteforce.h"
#include "utility.h"


void changeslow(int amount, std::vector<int> values) {
    std::vector<int> coins;

    int length = int(values.size());        // Number of coin denominations
    int tempValue = 0;                      // Temp value holder
    int lowestSum = amount;                 // Used to store lowest sum thus far
    int coinSum = 0;
    int *t = new int[length];               // Array used to store temp histogram of coin count thus far

    int i, j, k;                            // Variable are good!



    std::cout << "\nLength:\t" << length;
    std::cout << "\nAmount:\t" << amount << std::endl;
    std::cout << "Values:\t";
    for (int a = 0; a < length; a++) {
        std::cout << values.at(a) << " ";
    }

    // Begin i at the end of the array (start with most valuable coin)
    // Use (length - 1) because indexes :)
    for (i = length-1; i > 0; i--) {
        // Set temp coin count array to 0s
        for (int a = 0; a < length; a++) {
            t[a] = 0;
        }

        t[i] = amount/values[i];

        j = i - 1;
        while (t[i] > 0) {
            tempValue = 0;
            for (k = 0; k < length; k++) {
                std::cout << "tempvalue = t[k]* values[k]" << std::endl;
                tempValue += (t[k] * values[k]);
            }
            std::cout << "out of temp value shit and temp value = " << tempValue << std::endl;
            if (tempValue == amount) {
                std::cout << "tempValue = amount" << std::endl;
                for (k = 0; k < length; k++) {
                    coinSum += t[k];
                }
                if (coinSum < lowestSum) {
                    lowestSum = coinSum;
                    for (k = 0; k < length; k++) {
                        coins.push_back(t[k]);
                    }
                }

                t[i] = t[i] - 1;
                j = i - 1;

                for (k = 0; k < length; k++) {
                    t[k] = 0;
                }
            }

            else if (tempValue < amount) {
                std::cout << "tempvalue < amount" << std::endl;
                t[j] = t[j] + 1;
            }
            else if (tempValue > amount) {
                std::cout << "tempvalue > amount" << std::endl;
                t[j] = t[j] - 1;
                j = j - 1;
                t[j] = t[j] + 1;
            }
        }
    }








    for (int a = 0; a < length; a++) {
        std::cout << "Value: " << values.at(a) << "\tCoin count: " << coins.at(a) << std::endl;
    }


    std::cout << "\n";
    // return myChange;
}