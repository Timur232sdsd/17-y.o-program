
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int f(const std::vector<int>& hA, const std::vector<int>& hB) {
    int minD = INT_MAX;
    int pA = 0, pB = 0;

    while (pA < hA.size() && pB < hB.size()) {
        int diff = abs(hA[pA] - hB[pB]);
        minD = std::min(minD, diff);
        if (hA[pA] < hB[pB]) {
            pA++;
        } else {
            pB++;
        }
    }

    return minD;
}

int main() {
    std::ifstream fileA("27-181b.txt");
    int N;
    fileA >> N;
    std::vector<int> hA(N); std::vector<int> hB(N);
    for (int i = 0; i < N; ++i) {
        fileA >> hA[i];
    }
    for (int i = 0; i < N; ++i) {
        fileA >> hB[i];
    }
    int minD = f(hA, hB);
    std::cout  << minD << std::endl;

    return 0;
}
