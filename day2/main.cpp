#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cmath>
#include <sstream>

int main() {
    std::ifstream file("input.txt");
    std::string str;
    int safecount = 0;
    int counter = 1;
    while (std::getline(file, str)) {
        std::istringstream stream(str);
        std::string word;
        std::vector<int> row;
        while (stream >> word) {
            row.push_back(std::stoi(word));
        }
        int leftptr = 0;
        int rightptr = 1;
        bool safe = true;
        int difference = row.at(leftptr) - row.at(rightptr);
        bool decreasing = difference > 0;
        bool increasing = difference < 0;
        while (rightptr < row.size() && decreasing) {
            bool pairDiff = abs(row.at(leftptr) - row.at(rightptr)) >= 1 && abs(row.at(leftptr) - row.at(rightptr)) < 4;
            difference = row.at(leftptr) - row.at(rightptr);
            if (difference <= 0 || !pairDiff) {
                decreasing = false;
            }
            leftptr++;
            rightptr++;
        }
        leftptr = 0;
        rightptr = 1;
        while (rightptr < row.size() && increasing) {
            bool pairDiff = abs(row.at(leftptr) - row.at(rightptr)) >= 1 && abs(row.at(leftptr) - row.at(rightptr)) < 4;
            difference = row.at(leftptr) - row.at(rightptr);
            if (difference >= 0 || !pairDiff) {
                increasing = false;
            }
            leftptr++;
            rightptr++;
        }
        safe = increasing || decreasing;
        if (safe) {
            safecount++;
        }
    }
    std::cout << "TOTAL SAFECOUNT BELOW" << std::endl;
    std::cout << safecount << std::endl;
}