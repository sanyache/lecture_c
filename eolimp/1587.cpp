#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int main(){
    int n;
    cin>>n;
    vector<pair<int, int>> data(n);
    for(int i=0; i<n; i++){
        int h,m,pr;
        cin>>h>>m>>pr;
        data[i] = {h*60+m, pr};
    }
    queue<int> q;
    int end_time = 0;
    int q_time = 0;
    for(int i=0; i<n; i++){
        if(data[i].first > end_time){
            data[i].first += 20;
            end_time = data[i].first;
            q = {};
            q.push(i);
            q_time = end_time;
        } else {
            while(!q.empty() && data[i].first >= q_time){
                q.pop();
                int ind = q.front();
                q_time = data[ind].first;
            }
            if(data[i].second >= q.size()){
                end_time += 20;
                data[i].first = end_time;
                q.push(i);
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<(data[i].first/60)%24<<' '<<data[i].first%60<<'\n';
    }
    return 0;
}
