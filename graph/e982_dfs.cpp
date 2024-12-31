#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<int>> &adj, int start, vector<bool> &visited){
    visited[start] = true;
    for(auto vertex: adj[start]){
        if(!visited[vertex]){
            dfs(adj, vertex, visited);
        }
    }

}

int main(){

    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<bool> visited(n+1, false);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj, 1, visited);
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}