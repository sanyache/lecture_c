#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    string s;
    cin>>s;
    unordered_map <char, int>map_s;
    for(auto ch: s){
        if(map_s.find(ch) != map_s.end()){
            map_s[ch] += 1;
        } else {
            map_s[ch] = 1;
        }
    }
    for(auto [key, val] : map_s){
        cout<<key<<' '<<val<<'\n';
    }

    return 0;
}
