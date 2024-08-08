#include<iostream>
#include<vector>

using namespace std;

int main(){
    int rang, n;
    cin>>rang>>n;
    vector<vector<long long> > graph;
    int maxRowWidth = rang * 2 - 1;
    int minRowWidth = maxRowWidth - (rang - 1);
    for(int i=0; i<rang; i++){
        vector<long long> row(minRowWidth+i, 1);
        graph.push_back(row);
    }
    for(int i=1; i<rang; i++){
        vector<long long> row(maxRowWidth-i, 1);
        graph.push_back(row);
    }
    for (int i = 1; i < rang; i++){
        int column = graph[i].size();       
        for (int j = 1; j < column-1; j++){
            graph[i][j] = graph[i][j-1] + graph[i-1][j-1] + graph[i-1][j];
        }
        graph[i][column-1] = graph[i][column-2] + graph[i-1][column-2];
    }
    for (int i = rang; i < maxRowWidth; i++){
        int column = graph[i].size(); 
        graph[i][0] = graph[i-1][0] + graph[i-1][1];      
        for (int j = 1; j < column; j++){
            graph[i][j] = graph[i][j-1] + graph[i-1][j] + graph[i-1][j+1];
        }
    }
    int cell = 0;
    for (int i = 0; i < graph.size(); i++){      
        for (int j = 0; j < graph[i].size(); j++){
            if(++cell == n){
                cout<<graph[i][j];
                break;
            } 
    }
}
    return 0;
}