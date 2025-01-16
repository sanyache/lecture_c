#include<iostream>
#include<vector>

using namespace std;


bool dfs(vector<vector <int>> adj, int start, vector<int> &visited){
    visited[start] = 1;

    for(auto vertex: adj[start]){
        
        if(visited[vertex] == 0){
            if(dfs(adj, vertex, visited)){
                return true;
            }
        } else if(visited[vertex] == 1){
            return true;
        }

    }
    visited[start] = 2;
    return false;
}

// Function to add an edge to the graph
void add_adj(vector<vector <int>> &adj, int first, int second){
    adj[first].push_back(second);
}

int main(){

    // Number of vertices in the graph
    int V = 10;
    // Adjacency list representation of the graph
    vector<vector <int>> adj(V);
    vector<int> visited (adj.size(), 0);

     // Add edges to the graph
    add_adj(adj, 0, 6);
    add_adj(adj, 0, 3);
    add_adj(adj, 3, 1);
    add_adj(adj, 3, 5);
    add_adj(adj, 6, 5);
    add_adj(adj, 6, 2);
    add_adj(adj, 5, 8);
    add_adj(adj, 1, 7);
    add_adj(adj, 7, 4);
    add_adj(adj, 4, 9);
    add_adj(adj, 9, 2);
    add_adj(adj, 9, 5);
    add_adj(adj, 8, 4);
    // call the function dfs with start vertex 0
    for(int i=0; i<V; i++){
        if(visited[i] == 0){
            if( dfs(adj, i, visited)){
                cout<<"Cycle detected"<<endl;
                return 0;
            }          
        }
    }
    cout<<"No cycle detected"<<endl;
    return 0;
}
