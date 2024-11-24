#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector <int>> adj, int start){
    static vector<bool> visited (adj.size(), false);

    visited[start] = true;
    cout<<start<<' ';

    for(auto vertex: adj[start]){
        if(!visited[vertex]){
            visited[vertex] = true;
            dfs(adj, vertex);
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
    // call the function dfs with start vertex 0
    dfs(adj, 0);
    return 0;
}
