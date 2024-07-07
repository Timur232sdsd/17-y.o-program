#include <iostream>
#include <fstream>
#include <vector>

int findMaxPairSum(const std::string& fileName) {
    std::ifstream f(fileName);
    int n, k; f >> n >> k; int maxSum = 0;
    std::vector<int> num(n);
    for (int i = 0; i < n; ++i) {f >> num[i];}
    for (int i = 0; i < n; ++i) {
        for (int j = i + k; j < n; ++j) {
            if ((num[i] % 47 == 0 || num[j] % 47 == 0) && (num[i] + num[j]) % 2023 == 0) {
                maxSum = std::max(maxSum, num[i] + num[j]);
            }
        }
    }
    return maxSum;
}
int main() {
    int rA = findMaxPairSum("27-149a.txt");
    int rB = findMaxPairSum("27-149b.txt");
    std::cout << rA << " " << std::endl;
    std::cout << rB << " " << std::endl;
    return 0;
}
