#include<iostream>
#include<vector>

typedef long long ll;

using namespace std;

int rabin_karp(const string &s, const string &temp){
    const int p=31;
    vector<ll>pow(s.size());
    pow[0] = 1;
    for(int i=1; i<s.size(); i++){
        pow[i] = pow[i-1]*p;
    }
    ll hash_temp = 0;
    for(int i=0; i<temp.size(); i++){
        hash_temp += (temp[i] - 'a' + 1)*pow[i];
    }
    vector<ll>hash_s(s.size());
    for(int i=0; i<s.size(); i++){
        hash_s[i] = (s[i] - 'a' + 1)*pow[i];
        if (i) hash_s[i] += hash_s[i-1];
    }
    for(int i=0; i+temp.size()-1 < s.size(); i++){
        ll cur_h = hash_s[i+temp.size()-1];
        if (i){
            cur_h -= hash_s[i-1];
        }    
        if(cur_h == hash_temp*pow[i])
            return i;
    }
    return -1;
}

int main(){
    string s, temp;
    cout<<"Enter the string: ";
    cin>>s;
    cout<<"Enter the template: ";
    cin>>temp;
    cout<<rabin_karp(s, temp);
    return 0;
}