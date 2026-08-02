#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;
using ll = long long;
#define int ll

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin>>n>>m>>k;
    int a[n][m];
    priority_queue<pair<int, int>> pq[1001];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
            pq[i].push({-a[i][j], -j}); 
        }       
    }  
    for(int j=0; j<m-1 && k>0; j++){
        vector<array<int, 3>> delta;
        for(int i=0; i<n; i++){
            auto [val, ind_j] = pq[i].top();
            if (-ind_j <= j){
                pq[i].pop();
                i --;
                continue;
            }
            ind_j = -ind_j;
            if(a[i][ind_j] < a[i][j]){
                delta.push_back({a[i][j] - a[i][ind_j], ind_j, i});
            }
        }
        sort(delta.begin(), delta.end());
        reverse(delta.begin(), delta.end());
        for(auto [val, ind_j, i]: delta){
            if(k>0){
                k--;
                pq[i].pop();
                swap(a[i][j], a[i][ind_j]);
                pq[i].push({-a[i][ind_j], -ind_j});
            }
        }
    } 
    for(int j=0; j<m; j++){
        int s = 0;
        for(int i=0; i<n; i++){
            s += a[i][j];
        }
        cout<<s<<' ';
    }
    return 0;
}