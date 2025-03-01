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

int kmp(string &s, string &tmp){
    vector<int>p = pi(tmp);
    int n = size(s);
    int m = size(tmp);
    int i = 0;
    int j = 0;
    while(i<n){
        if(s[i] == tmp[j]){
            i++;
            j++;
            if(j == m){
                return i-m;
            }
        } else {
            if(j == 0){
                i ++;
            } else {
                j = p[j-1];
            }
        }
    }
    return -1;
}

int main(){
    string s, tmp;
    cin>>s;
    cin>>tmp;
    cout<<kmp(s, tmp);
    return 0;   
}