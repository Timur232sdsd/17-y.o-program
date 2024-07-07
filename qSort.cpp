#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>& a, int left, int right) {
    if (left >= right) return;

    int pivot = a[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (a[i] < pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    quickSort(a, left, j);
    quickSort(a, i, right);
}

int main() {
    int z, len;
    cin >> len;
    vector<int> a;
    while (len--) {
        cin >> z;
        a.push_back(z);
    }
    quickSort(a, 0, len - 1); 

    quickSort(a, 0, a.size() - 1);
    for(auto i: a) {
        cout << i << " ";
    }
    return 0;
}