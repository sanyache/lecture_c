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

    int n, s, k;
    cin>>n>>s>>k;
    vector<vector<int>> adj(n+1);
    vector<bool> visited(n+1, false);
    for(int i=0; i<k; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj, s, visited);
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cnt += 1;
            dfs(adj, i, visited);
        }
    }
    cout<<cnt<<endl;
    return 0;
}