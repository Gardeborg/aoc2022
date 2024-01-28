#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    std::ifstream input_file("input");
    std::string line;
    std::vector<int> calories_per_elf;
    int calorie_sum = 0;
    int calories;
    while(std::getline(input_file, line)) {
        std::cout << "Line: " << line << "\t " << line.size() << "\n";
        if(line.size() == 1) {
            std::cout << "Calorie_sum: " << calorie_sum;
            calories_per_elf.push_back(calorie_sum);
            calorie_sum = 0;
            continue;
            //std::cout << "Empty line found \n";
        }
    
        std::stringstream ssline(line);
        ssline >> calories;
        calorie_sum  += calories;
        //std::cout << calorie_sum << "\n";
    }
    
    // A
    auto max_calories = std::max_element(calories_per_elf.begin(), calories_per_elf.end());
    if(max_calories != calories_per_elf.end())
        std::cout << *max_calories << "\n";
    else
        std::cout << 0 << "\n";

    // B
    std::sort(calories_per_elf.begin(), calories_per_elf.end(), std::greater<int>());
    std::cout << calories_per_elf.at(0) + calories_per_elf.at(1) + calories_per_elf.at(2);
}