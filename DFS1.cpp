
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9; 

vector<vector<int>> graph;

void addEdge(int u, int v, int weight) {
    graph[u][v] = weight;
    graph[v][u] = weight; // Для неориентированного графа добавьте также обратное ребро
}

void dijkstra(int startVertex, int endVertex) {
    vector<int> dist(graph.size(), INF); // Массив для хранения расстояний от startVertex до каждой вершины
    vector<bool> visited(graph.size(), false); // Массив для отслеживания посещенных вершин
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Очередь с приоритетами для Dijkstra

    dist[startVertex] = 0;
    pq.push(make_pair(0, startVertex));

    while (!pq.empty()) {
        int currentVertex = pq.top().second;
        pq.pop();

        if (visited[currentVertex]) {
            continue;
        }

        visited[currentVertex] = true;

        for (int neighbor = 0; neighbor < graph.size(); neighbor++) {
            if (graph[currentVertex][neighbor] != INF) {
                int weight = graph[currentVertex][neighbor];
                if (dist[currentVertex] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[currentVertex] + weight;
                    pq.push(make_pair(dist[neighbor], neighbor));
                }
            }
        }
    }

    if (dist[endVertex] == INF) {
        cout << "There is no path from vertex " << startVertex << " to vertex " << endVertex << endl;
    } else {
        cout << "The shortest path from vertex " << startVertex << " to vertex " << endVertex << " is " << dist[endVertex] << endl;
    }
}

int main() {
    int n; 
    cin >> n;

    graph.resize(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int weight;
            cin >> weight;
            if (weight != -1) { 
                addEdge(i, j, weight);
            }
        }
    }

    int a, b; 
    cin >> a >> b;

    dijkstra(a, b);

    return 0;
}