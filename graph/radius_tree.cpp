#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Функція BFS, яка тепер повертає повний масив відстаней від стартової вершини
vector<int> get_distances(int start_node, int num_nodes, const vector<vector<int>>& adj) {
    vector<int> dist(num_nodes + 1, -1);
    queue<int> q;

    q.push(start_node);
    dist[start_node] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int neighbor : adj[curr]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[curr] + 1;
                q.push(neighbor);
            }
        }
    }
    return dist;
}

// Функція для пошуку індексу найвіддаленішої вершини на основі масиву відстаней
int get_furthest_node(const vector<int>& dist, int num_nodes) {
    int furthest_node = 1;
    int max_dist = -1;
    for (int i = 1; i <= num_nodes; ++i) {
        if (dist[i] > max_dist) {
            max_dist = dist[i];
            furthest_node = i;
        }
    }
    return furthest_node;
}

int main() {
    // Приклад дерева (6 вершин, нумерація від 1 до 6)
    // Ребра: (1-2), (2-3), (2-4), (4-5), (5-6)
    int n = 6; 
    vector<vector<int>> adj(n + 1);

    adj[1].push_back(2); adj[2].push_back(1);
    adj[2].push_back(3); adj[3].push_back(2);
    adj[2].push_back(4); adj[4].push_back(2);
    adj[4].push_back(5); adj[5].push_back(4);
    adj[5].push_back(6); adj[6].push_back(5);

    // КРОК 1: Перший BFS з випадкової вершини (наприклад, 1), щоб знайти перший кінець діаметра (D1)
    vector<int> dist_from_random = get_distances(1, n, adj);
    int d1 = get_furthest_node(dist_from_random, n);

    // КРОК 2: Другий BFS з вершини D1, щоб знайти другий кінець діаметра (D2) та відстані від D1
    vector<int> dist_from_d1 = get_distances(d1, n, adj);
    int d2 = get_furthest_node(dist_from_d1, n);
    int diameter = dist_from_d1[d2]; // Діаметр — це відстань між D1 та D2

    // КРОК 3: Третій BFS з вершини D2, щоб отримати відстані від другого кінця діаметра
    vector<int> dist_from_d2 = get_distances(d2, n, adj);

    // КРОК 4: Обчислюємо ексцентриситети всіх вершин та знаходимо радіус
    vector<int> eccentricity(n + 1);
    int radius = 1e9; // Ініціалізуємо великим числом

    for (int i = 1; i <= n; ++i) {
        // Ексцентриситет — це максимум із відстаней до двох кінців діаметра
        eccentricity[i] = max(dist_from_d1[i], dist_from_d2[i]);
        radius = min(radius, eccentricity[i]);
    }

    // КРОК 5: Знаходимо всі вершини, у яких ексцентриситет дорівнює радіусу (це і є центри)
    vector<int> centers;
    for (int i = 1; i <= n; ++i) {
        if (eccentricity[i] == radius) {
            centers.push_back(i);
        }
    }

    // Виведення результатів
    cout << "Діаметр дерева: " << diameter << " (між вершинами " << d1 << " та " << d2 << ")" << endl;
    cout << "Радіус дерева: " << radius << endl;
    cout << "Центр(и) дерева: ";
    for (int c : centers) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
