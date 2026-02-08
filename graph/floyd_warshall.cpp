#include<iostream>
#include<vector>


using namespace std;

#define INF 0x3f3f3f3f

void floyd_warshall(vector<vector <int>> &dist){
    int V = dist.size();
    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(dist[i][k] == INF or dist[k][j] == INF){
                    continue;
                }
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void print_matrix(const vector<vector <int>> &matrix){
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix.size(); j++){
            cout<<matrix[i][j]<<' ';
        }
        cout<<'\n';
    }
}

int main(){
    vector<vector <int>> dist = {
        {0, 4, INF, 5, INF},
        {INF, 0, 1, INF, 6},
        {2, INF, 0, 3, INF},
        {INF, INF, 1, 0, 2},
        {1, INF, INF, 4, 0}
    };
    floyd_warshall(dist);
    print_matrix(dist);
    
}