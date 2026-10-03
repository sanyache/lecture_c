#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Структура для збереження результату BFS: {найвіддаленіша_вершина, відстань_до_неї}
struct BFSResult {
    int furthest_node;
    int distance;
};

// Функція BFS, яка повертає найвіддаленішу вершину від стартової та відстань до неї
BFSResult bfs(int start_node, int num_nodes, const vector<vector<int>>& adj) {
    vector<int> dist(num_nodes + 1, -1); // Масив відстаней (-1 означає, що вершина не відвідана)
    queue<int> q;

    q.push(start_node);
    dist[start_node] = 0;

    int furthest_node = start_node;
    int max_dist = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        // Оновлюємо найвіддаленішу вершину
        if (dist[curr] > max_dist) {
            max_dist = dist[curr];
            furthest_node = curr;
        }

        // Обходимо всіх сусідів поточного вузла
        for (int neighbor : adj[curr]) {
            if (dist[neighbor] == -1) { // Якщо сусід ще не відвіданий
                dist[neighbor] = dist[curr] + 1;
                q.push(neighbor);
            }
        }
    }

    return {furthest_node, max_dist};
}

int main() {
    // Приклад дерева (6 вершин, нумерація від 1 до 6)
    // Ребра: (1-2), (2-3), (2-4), (4-5), (5-6)
    int n = 6; 
    vector<vector<int>> adj(n + 1);

    // Додаємо ребра (граф неорієнтований)
    adj[1].push_back(2); adj[2].push_back(1);
    adj[2].push_back(3); adj[3].push_back(2);
    adj[2].push_back(4); adj[4].push_back(2);
    adj[4].push_back(5); adj[5].push_back(4);
    adj[5].push_back(6); adj[6].push_back(5);

    // КРОК 1: Запускаємо перший BFS з довільної вершини (наприклад, з 1)
    // Він знайде один із кінців діаметра.
    BFSResult first_bfs = bfs(1, n, adj);

    // КРОК 2: Запускаємо другий BFS із знайденої найвіддаленішої вершини
    // Він знайде другий кінець діаметра та точну відстань між ними.
    BFSResult second_bfs = bfs(first_bfs.furthest_node, n, adj);

    // Виведення результату
    cout << "Один кінець діаметра: " << first_bfs.furthest_node << endl;
    cout << "Другий кінець діаметра: " << second_bfs.furthest_node << endl;
    cout << "Діаметр дерева дорівнює: " << second_bfs.distance << endl;

    return 0;
}
