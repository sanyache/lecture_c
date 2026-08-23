#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Edge
{
    int weight;
    int from;
    int to;
};

struct CompEdge{
    bool operator()(const Edge &a, const Edge &b) const{
        return a.weight > b.weight;
    }
};

vector<Edge> primaMST(int V, vector<vector<pair<int, int>>> &adj){
    priority_queue<Edge, vector<Edge>, CompEdge> pq;
    vector<Edge> mst;
    vector<int> used(V, false);
    pq.push({0, -1, 0});
    while (!pq.empty() || mst.size()< V-1)
    {
        Edge curr = pq.top();
        pq.pop();
        int v = curr.to;
        if(used[v]) continue;
        used[v] = true;
        if(curr.from != -1){
            mst.push_back(curr);
        }
        for(const auto& neighbor: adj[v]){
            if(!used[neighbor.first]){
                pq.push({neighbor.second, v, neighbor.first});
            }
        }
    }
    return mst;
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
    vector<Edge> mst = primaMST(V, adj);
    int weight = 0;
    for(const auto &edge: mst){
        weight += edge.weight;
        cout<<edge.from<<"->"<<edge.to<<"-"<<edge.weight<<'\n';
    }
    cout<<weight;
    return 0;
}