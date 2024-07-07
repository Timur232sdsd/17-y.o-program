#include <iostream>
#include <vector>
#include <climits>

using namespace std;


int main() {
    int n, a, b; cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {for (int j = 0; j < n; ++j) {cin >> matrix[i][j]; if(matrix[i][j] == 0) matrix[i][j] = 9999;}}
    cin >> a >> b;
    for (int k = 0; k < n; ++k) {for (int i = 0; i < n; ++i) {for (int j = 0; j < n; ++j) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {matrix[i][j] = matrix[i][k] + matrix[k][j];}}}}
    if (matrix[a][b] == INT_MAX) {cout << "No way." << endl;} 
    else {cout << "Shorts way: " << matrix[a][b] << endl;}
    return 0;
}