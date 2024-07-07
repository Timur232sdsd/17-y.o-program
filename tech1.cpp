#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    long long arr[] = {a, b, c};
    sort(arr, arr + 3);
    a = arr[0];
    b = arr[1];
    c = arr[2];
    int z = 0;
    if (b - a == c - b) {
        z = 1;
    }
    if (double(b) / double(a) == double(c) / double(b) && (double(c) / double(b)) > 1) {
        z = 2;
    }
    if (double(b) / double(a) == double(c) / double(b) && (double(c) / double(b)) > 1 && b - a == c - b) {
        z = 3;
    }
    if (z == 0) {
        cout << "No";
    }
    if (z == 1) {
        cout << "A " << a << " " << b << " " << c << "\n";
    }
    if (z == 2) {
        cout << "G " << a << " " << b << " " << c << "\n";
    }
    if (z == 3) {
        cout << "B " << a << " " << b << " " << c << "\n";
    }
    return 0;
}
