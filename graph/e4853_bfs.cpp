#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void print_path(uint32_t start, uint32_t stop, uint32_t path[]){
    if(start == stop){
        cout<<start<<' ';
        return;
    }
    print_path(start, path[stop], path);
    cout<<stop<<' ';

}

int bfs(vector<vector <uint32_t>> &adj, uint32_t start, uint32_t stop, uint32_t path[]){
    queue <uint32_t> q;
    vector <bool> visited (adj.size(), false);
    q.push(start);
    visited[start] = true;
    int length = 0;
    int capacity = 1;
    // Iterate over the queue
    while (!q.empty()){
        // Print vertex and delete from head of queue
        uint32_t current = q.front();
        q.pop();
        if(current == stop){
            return length;
        }
        // Iterate over the vector in vector[current]
        for(auto vertex: adj[current]){
            if (!visited[vertex]){
                // mark the vertex as a visited and add to the queue
                visited[vertex] = true;
                q.push(vertex);
                path[vertex] = current;
            }
        }
        capacity--;
        if(capacity == 0){
            length++;
            capacity = q.size();
        }
    }
    return -1;
}

int main(){

    int n,m;
    cin>>n>>m;
    int start, stop;
    cin>>start>>stop;
    vector<vector<uint32_t>> adj(n+1);
    uint32_t path[n+1];
    for(uint32_t i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int length = bfs(adj, start, stop, path);
    if(length == -1){
        cout<<-1;
    } else {
        cout<<length<<'\n';
        print_path(start, stop, path);
    }

    return 0;
}