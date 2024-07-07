#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool DFS(vector<vector<int>>& graph, int start, int end, vector<int>& path, vector<bool>& visited) {
    visited[start] = true;
    path.push_back(start);

    if (start == end) {
        return true; 
    }

    for (int n = 0; n < graph.size(); ++n) {
        if (graph[start][n] == 1 && !visited[n]) {
            if (DFS(graph, n, end, path, visited)) {
                return true; 
            }
        }
    }
    path.pop_back();
    return false;
}
int main() {
    int n; cin >> n; vector<vector<int>> graph(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }
    int start, end;
    cin >> start >> end;
    vector<int> path;
    vector<bool> visited(n, false);

    if (DFS(graph, start, end, path, visited)) {
        cout << "Путь из вершины " << start << " в вершину " << end << ": ";
        for (int vertex : path) {
            cout << vertex << " ";
        }
        cout << endl;
    } else {
        cout << "Путь из вершины " << start << " в вершину " << end << " не найден." << endl;
    }

    return 0;
}