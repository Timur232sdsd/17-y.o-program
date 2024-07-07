#include <iostream>
#include <fstream>
#include <vector>

int countm(const std::vector<int>& numbers) {
    int count = 0;
    for (int i = 0; i < numbers.size(); ++i) {
        int currentSum = 0;
        for (int j = i; j < numbers.size(); ++j) {
            currentSum += numbers[j];
            if (currentSum % 71 == 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    std::ifstream fileA("27-72a.txt");
    std::ifstream fileB("27-72b.txt");

    std::vector<int> numA, nB;
    int num;

    while (fileA >> num) {
        numA.push_back(num);
    }

    while (fileB >> num) {
        nB.push_back(num);
    }

    int countA = countm(numA);
    int countB = countm(nB);

    std::cout << countA << " " << countB << std::endl;

    return 0;
}
