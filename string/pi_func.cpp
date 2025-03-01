#include<iostream>
#include<vector>

using namespace std;

vector<int> pi(const string &s){
    int n = s.size();
    vector<int> p(n, 0);
    int j=0;
    int i=1;
    while(i<n){
        if(s[i] == s[j]){
            p[i] = j + 1;
            j ++;
            i ++;
        } else {
            if(j == 0){
                i ++;
            } else {
                j = p[j-1];
            }
        }
    }
    return p;
}

int main(){
    string s;
    cin>>s;
    for(auto el: pi(s)){
        cout<<el<<' ';
    }
    return 0;
}