#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    int r[n], p[n];
    vector<vector<int>> vec(n, vector<int>(n));
    bool active[n];
    int min1, kmin;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> vec[i][j];
        }
    }

    cin >> a >> b;

    for (int i = 0; i < n; i++) {
        active[i] = true;
        r[i] = vec[a][i];
        p[i] = 0;
    }

    active[a] = false;
    p[a] = -1;

    for (int i = 0; i < n; ++i) {
        min1 = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if (active[j] && r[j] < min1) {
                min1 = r[j];
                kmin = j;
            }
        }

        active[kmin] = false;

        for (int j = 0; j < n; ++j) {
            if (vec[kmin][j] && active[j]) {
                if (r[kmin] + vec[kmin][j] < r[j]) {
                    r[j] = r[kmin] + vec[kmin][j];
                    p[j] = kmin;
                }
            }
        }
    }

    cout << r[b] << endl;

    return 0;
}