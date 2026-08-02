#include<iostream>
#include<queue>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(size_t i=0; i<points.size(); i++){
        int x = points[i][0];
        int y = points[i][1];
        int dist = x*x + y*y;
        pq.push({dist, i});
    }
    vector<vector <int>> rez;
    for(int i=0; i<k; i++){
        rez.push_back(points[pq.top().second]);
        pq.pop();
    }
    return rez;
}

int main(){

    vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
    int k = 2;
    vector<vector <int>> rez = kClosest(points, k);
    for(auto row: rez){
        for(auto val: row){
            cout<<val<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
