#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;
int main() {
    ifstream fin("26-j8.txt");
    int n, cnt = 0, max_price = 0, sum = 0;
    fin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > max_price) max_price = a[i];
    }
    sort(a, a + n);
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > 100 && cnt % 2 == 1) {
            sum += a[i] * 0.9;
        } else {
            sum += a[i];
        }
        cnt++;
    }
    if (max_price > 100 && cnt % 2 == 1) {
        max_price *= 0.9;
    }
    cout << sum << " " << max_price << endl;
    return 0;
}