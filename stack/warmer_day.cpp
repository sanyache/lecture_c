#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int main(){
    int n;
    cin>>n;
    int temps[n];
    for(int i=0; i<n; i++){
        cin>>temps[i];
    }
    vector<int> rez(n, 0);
    vector<pair<int, int>> stack;
    for(int i=n-1; i>=0; --i){
        while (!stack.empty() && temps[i] > stack[stack.size()-1].first)
        {
            stack.pop_back();
        }
        if(!stack.empty()){
            rez[i] = stack[stack.size()-1].second - i; 
        }
        stack.push_back({temps[i], i});
        
    }
    for(int day: rez){
        cout<<day<<' ';
    }
}