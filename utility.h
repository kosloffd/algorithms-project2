#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>


int countLines(std::ifstream& fin, std::string str);

std::vector<int> getValues(std::ifstream &fin, std::string file);

int getAmount(std::ifstream& fin, std::string file);

#endif
