#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::ifstream file("17-304.txt");
    std::vector<int> sequence;
    int number;
    while (file >> number) {
        sequence.push_back(number);
    }

    int max_element = *std::max_element(sequence.begin(), sequence.end());
    int pairs_count = 0;
    int sum_of_pairs = 0;

    for (size_t i = 0; i < sequence.size() - 1; i++) {
        std::string hex1 = std::to_string(sequence[i], 16);  // Преобразуем число в шестнадцатеричную запись
        std::string hex2 = std::to_string(sequence[i+1], 16);
        if (hex1.find("aa") != std::string::npos && hex2.find("aa") != std::string::npos 
            && (sequence[i] + sequence[i+1] < max_element) && (max_element % 246 == 0)) {
            pairs_count++;
            sum_of_pairs += sequence[i] + sequence[i+1];
        }
    }

    std::cout << pairs_count << std::endl;
    std::cout << sum_of_pairs << std::endl;

    return 0;
}
