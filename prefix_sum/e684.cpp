#include<iostream>
#include<vector>
#include<utility>

using namespace std;

struct Coord{
    int r1, c1, r2, c2;
};

int main(){
    int n, m, k;
    cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int>(m));
    vector<vector<int>> prefix_sum(n+1, vector<int>(m+1, 0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            prefix_sum[i][j] = prefix_sum[i-1][j] + prefix_sum[i][j-1] + matrix[i-1][j-1] - prefix_sum[i-1][j-1];
        }
    }
    vector<Coord> queries;
    cin>>k;
    for(int i=0; i<k; i++){
        Coord coord;
        cin>>coord.r1>>coord.c1>>coord.r2>>coord.c2;
        queries.push_back(coord);
    }

    for(auto coord: queries){
        int r1 = coord.r1;
        int c1 = coord.c1;
        int r2 = coord.r2;
        int c2 = coord.c2;
        int s = prefix_sum[r2][c2] - prefix_sum[r2][c1-1] - prefix_sum[r1-1][c2] + prefix_sum[r1-1][c1-1];
        cout<<s<<'\n';
    }
    return 0;
}