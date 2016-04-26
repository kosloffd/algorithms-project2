#include "utility.h"

int countLines(std::ifstream& fin, std::string file) {
    // Clear EOF flag and move cursor to the first character in the file
    fin.clear();
    fin.seekg(0, std::ios::beg);

    // Variable to store the number of lines
    int lineCount = -1;

    // Ensure file is open
    if (!fin.is_open()) {
        std::cout << "\nThe text file " << file << " could not be opened. Try again.";
        exit(1);
    }

    // Count lines using STL
    // Source:
    // http://stackoverflow.com/questions/3072795/how-to-count-lines-of-a-file-in-c
    if (fin.is_open()) {
        lineCount = std::count(std::istreambuf_iterator<char>(fin), std::istreambuf_iterator<char>(), '\n');
    }

    // Clear EOF flag and move cursor to the first character in the file
    fin.clear();
    fin.seekg(0, std::ios::beg);

    return lineCount;
}

std::vector<int> getValues(std::ifstream &fin, std::string file) {
    std::vector<int> arrValues;
    std::string str;
    int temp;

    getline(fin, str);

    // Here we read a line from the file in the format
    // [x, x, x, x, x, x]
    // Where x is any positive integer. First we remove any spaces
    // and brackets. Now we have a comma delimited string as
    // x,x,x,x,x,x
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    str.erase(std::remove(str.begin(), str.end(), '['), str.end());
    str.erase(std::remove(str.begin(), str.end(), ']'), str.end());
    std::cout << str << std::endl;

    // Load the string str into a string stream
    std::stringstream ss(str);

    int i;

    // String stream will pull each int out, and we make it
    // ignore any commas it finds
    while (ss >> i) {
        arrValues.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }

    return arrValues;
}