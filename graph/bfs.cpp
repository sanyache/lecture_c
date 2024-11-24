#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void bfs(vector<vector <int>> &adj, int start){
    queue <int> q;
    vector <bool> visited (adj.size(), false);
    q.push(start);
    visited[start] = true;

    // Iterate over the queue
    while (!q.empty()){
        // Print vertex and delete from gead of queue
        int current = q.front();
        cout<<q.front()<<' ';
        q.pop();
        // Iterate over the vector in vector[current]
        for(auto vertex: adj[current]){
            if (!visited[vertex]){
                // mark the vertex as a visited and add to the queue
                visited[vertex] = true;
                q.push(vertex);
            }
        }
    }
}
// Function to add an edge to the graph
void add_adj(vector<vector <int>> &adj, int first, int second){
    adj[first].push_back(second);
    adj[second].push_back(first);
}
int main(){

    // Number of vertices in the graph
    int V = 7;
    // Adjacency list representation of the graph
    vector<vector <int>> adj(V);

     // Add edges to the graph
    add_adj(adj, 0, 1);
    add_adj(adj, 0, 2);
    add_adj(adj, 1, 3);
    add_adj(adj, 1, 4);
    add_adj(adj, 1, 5);
    add_adj(adj, 5, 2);
    add_adj(adj, 6, 2);
    // call the function bfs with start vertex 0
    bfs(adj, 0);
    return 0;
}
