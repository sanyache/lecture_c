#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void prima(vector<vector<pair<int, int>>> &adj, int V, vector<vector<int>> &rez){
    priority_queue<pair<int, int>> pq;
    vector<bool> used(V, false);
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto [w, v] = pq.top();
        pq.pop();
        if(used[v]) continue;      
        used[v] = true;
        rez.push_back({v, -w});
        for(auto [u, wg]: adj[v]){
            if(!used[u]){
                pq.push({-wg, u});

            }
        }
    }
    
} 

int main(){

    int n, V;
    cin>>V;
    cin>>n;
    vector<vector<pair<int, int>>> adj(V);
    for(int i=0; i<n; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<vector<int>> rez;
    prima(adj, V, rez);
    int weight = 0;
    for(auto g: rez){
        cout<<g[0]<<' ';
        weight += g[1];
    }
    cout<<weight;

    return 0;
}

// 9 14
// 0 7 8
// 7 6 1
// 6 5 2
// 5 4 10
// 4 3 9
// 3 2 7
// 2 1 8
// 1 0 4
// 7 1 11
// 7 8 7
// 6 8 6
// 8 2 2
// 5 2 4
// 5 3 14