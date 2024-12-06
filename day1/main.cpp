#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <cmath>

int main() {
    std::ifstream file("input.txt");
    std::string str;
    std::priority_queue<int, std::vector<int>, std::greater<int>> leftHeap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> rightHeap;
    std::vector<int> leftarr;
    std::vector<int> rightarr;
    int distance = 0;
    int simscore = 0;
    while (std::getline(file, str)) {
        std::string left = str.substr(0, str.find(' '));
        std::string right = str.substr(str.find(' ') + 1);
        leftHeap.push(std::stoi(left));
        rightHeap.push(std::stoi(right));
        leftarr.push_back(std::stoi(left));
        rightarr.push_back(std::stoi(right));
    }
    while (!leftHeap.empty() && !rightHeap.empty()) {
        distance += std::abs(leftHeap.top() - rightHeap.top());
        leftHeap.pop();
        rightHeap.pop();
    }
    std::cout << distance << std::endl;
    std::cout << "---------------------------------" << std::endl;
    for (int i = 0; i < leftarr.size(); i++) {
        int current = leftarr[i];
        int occurences = 0;
        for (int j = 0; j < rightarr.size(); j++) {
            if (current == rightarr[j]) {
                occurences += 1;
            }
        }
        simscore += occurences * current;
    }
    std::cout << simscore << std::endl;
    return 0;
}
