#include "utility.h"

int countLines(std::ifstream& fin, std::string file) {
    // Clear EOF flag and move cursor to the first character in the file
    fin.clear();
    fin.seekg(0, std::ios::beg);

    // Variable to store the number of lines
    int count = -1;

    // Ensure file is open
    if (!fin.is_open()) {
        std::cout << "\nThe text file " << file << " could not be opened. Try again.";
        exit(1);
    }

    // Count lines using STL
    // Source: http://stackoverflow.com/questions/3072795/how-to-count-lines-of-a-file-in-c
    if (fin.is_open()) {
        count = std::count(std::istreambuf_iterator<char>(fin), std::istreambuf_iterator<char>(), '\n');
    }

    // Clear EOF flag and move cursor to the first character in the file
    fin.clear();
    fin.seekg(0, std::ios::beg);

    // Debugging output
    std::cout << "\nCount of lines is: " << count << "!!!\n";
    return count;
}