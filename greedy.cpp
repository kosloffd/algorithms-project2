#include "greedy.h"
#include "utility.h"

void changegreedy(int amount, std::vector<int> values) {
    std::vector<int> coins;
    int length = values.size();
    int i;
    int num;
    int *c = new int[length];               // Array used to store temp histogram of coin count thus far

    std::cout << "\nLength:\t" << length;
    std::cout << "\nAmount:\t" << amount << std::endl;
    std::cout << "Values:\t";

    for (int a = 0; a < length; a++) {
        std::cout << values.at(a) << " ";
    }

    std::cout << "\n";

    // Fill temp coin array with 0s
    for (int i = 0; i < length; i++) {
        c[i] = 0;
    }

    i = length - 1;

    while (i >= 0 && amount > 0) {
        num = floor(amount/values[i]);
        c[i] = num;
        amount = amount % values[i];
        i--;
    }

    for (int a = 0; a < length; a++) {
        coins.push_back(c[a]);
        std::cout << "Value: " << values.at(a) << "\tCoin count: " << coins.at(a) << std::endl;
    }
}
