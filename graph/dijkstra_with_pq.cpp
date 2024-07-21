#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define INF 0x3f3f3f3f


typedef pair<int, int> intPair;

void addEdge(vector<intPair> adj[], int u, int v, int wt){

    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void shortest_path(vector<intPair> adj[], int n, int start){
    priority_queue<intPair>pq;
    vector<int> dist (n, INF);
    dist[start] = 0;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        intPair min_dist = pq.top();
        int vertex = min_dist.second;
        //cout<<vertex<<' ';
        pq.pop();
        for(auto adjacent: adj[vertex]){
            int wt = adjacent.second;
            if(dist[adjacent.first] > dist[vertex] + wt){
                dist[adjacent.first] = dist[vertex] + wt;
                pq.push(make_pair(-1*dist[adjacent.first], adjacent.first));
            }            
        }
    }
    for(int i=0; i<n; i++){
        cout<<i<<' '<<dist[i]<<'\n';
    }    
}

int main(){

    int n = 9;
    vector<intPair> adj[n];

    // making above shown graph
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    shortest_path(adj, n, 0);
    return 0;
}
// 0 0
// 1 4
// 2 12
// 3 19
// 4 21
// 5 11
// 6 9
// 7 8
// 8 14