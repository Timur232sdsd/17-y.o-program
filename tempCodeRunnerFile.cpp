#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    int N;
    ifstream fin("26-j8.txt");
    fin >> N;
    vector<int> prices(N);

    for (int i = 0; i < N; ++i) {
        fin >> prices[i];
    }
    sort(prices.begin(), prices.end());
