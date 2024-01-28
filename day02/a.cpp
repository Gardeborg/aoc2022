#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <algorithm>

int main() {

    //std::unordered_map<std::string, int> score_table = { {"A X", 4}, {"A Y", 8}, {"A Z", 3}, {"B X", 1}, {"B Y", 5}, {"B Z", 9}, {"C X", 7}, {"C Y", 2}, {"C Z", 6} };
    std::unordered_map<std::string, int> score_table = { {"A X", 3}, {"A Y", 4}, {"A Z", 8}, {"B X", 1}, {"B Y", 5}, {"B Z", 9}, {"C X", 2}, {"C Y", 6}, {"C Z", 7} };
    std::ifstream input_file("input");
    std::string line;
    int score_sum = 0;
    while(std::getline(input_file, line)) {
            line.erase(std::remove_if( line.begin(),
                                       line.end(),
                                       [](auto ch)
                                       {
                                           return (ch == '\n' ||
                                                   ch == '\r'); 
                                       }),
                    line.end() );
            score_sum += score_table.at(line);
        }
    std::cout << score_sum;
}