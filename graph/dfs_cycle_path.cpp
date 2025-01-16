#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void get_rout(vector<int> &loop_route) {
    cout<<loop_route[0]<<' ';
   for(int i=1; i<loop_route.size(); i++){
        if (loop_route[i] == loop_route[0]){
            cout<<loop_route[i]<<' ';
            break;
        }     
       cout<<loop_route[i]<<' ';
   }
}

int dfs(vector<vector <int>> adj, int start, vector<int> &visited, vector<int> &loop_route){
    visited[start] = 1;
    for(auto vertex: adj[start]){
        
        if(visited[vertex] == 0 && dfs(adj, vertex, visited, loop_route) != -1 || visited[vertex] == 1){
            loop_route.push_back(vertex);
            return vertex;
        }

    }
    visited[start] = 2;
    return -1;
    
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
    vector<int> loop_route;

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
            int v = dfs(adj, i, visited, loop_route);
            if(v != -1){
                cout<<"Cycle detected"<<endl;
                
                get_rout(loop_route);
                return 0;
            }
        }
    }
    cout<<"No cycle detected"<<endl;
    return 0;
}
