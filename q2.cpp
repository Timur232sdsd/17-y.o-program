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
    vector<int> a = {6, 5, 3};

    quickSort(a, 0, a.size() - 1);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    return 0;
}
