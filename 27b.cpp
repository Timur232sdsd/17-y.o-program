

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int main() {
    long long N, K;

    ifstream fin("27-169bb.txt");

    fin >> N >> K;

    vector<long long> r(N);
    for (long long i = 0; i < N; ++i) {
        fin >> r[i];
    }

    sort(r.begin(), r.end());

    long long c = 0, z = 0;
    long long left = 0, right = N - 1;

    while (left < right) {
        long long sum = r[left] + r[right];
        if (sum >= K) {
            c += (right - left);
            --right;
        } 
        else {
            ++left;
        }
    }

    cout << c;

    return 0;
}