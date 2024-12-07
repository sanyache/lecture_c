#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int main(){

    int n, m, l, r;
    cin>>n;
    int numbers[n];
    for(int i=0; i<n; i++){
        cin>>numbers[i];
    }
    int prefix_sum[n+1] = {0};
    for(int i=1; i<n+1; i++){
        prefix_sum[i] = prefix_sum[i-1] + numbers[i-1];
    }
    cin>>m;
    pair<int, int> requests[m];
    for(int i=0; i<m; i++){
        cin>>l>>r;
        requests[i] = make_pair(l,r);
    }
    //-std=c++17
    for(auto [left, right]: requests){
        cout<<(prefix_sum[right] - prefix_sum[left - 1])<<'\n';
    }
    return 0;
}