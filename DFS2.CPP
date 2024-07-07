#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool DFS(vector<vector<int>>& graph, int start, int e, vector<int>& p, vector<bool>& v) {
    visited[start] = true;
    path.push_back(start);

    if (start == end) {
        return true; // Путь найден
    }

    for (int neighbor = 0; neighbor < graph.size(); ++neighbor) {
        if (graph[start][neighbor] == 1 && !v[neighbor]) {
            if (DFS(graph, neighbor, end, path, v)) {
                return true; // 
            }
        }
    }

    // Если не нашли путь, то откатываемся
    path.pop_back();
    return false;
}

int main() {
    int n;
    cout << "Введите количество вершин: ";
    cin >> n;

    // Инициализация матрицы смежности
    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Введите матрицу смежности (0 - нет связи, 1 - есть связь):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    int s, e;
    cout << "Введите начальную и конечную вершины (a и b): ";
    cin >> s >> e;

    vector<int> p;
    vector<bool> v(n, false);

    if (DFS(g, s, e, p, v)) {
        cout << "Путь из вершины " << s << " в вершину " << e << ": ";
        for (int vertex : path) {
            cout << vertex << " ";
        }
        cout << endl;
    } else {
        cout << "Путь из вершины " << s << " в вершину " << e << " не найден." << endl;
    }

    return 0;
}