#include<iostream>
#include<vector>

typedef long long ll;

constexpr ll MD = 1e9 + 7;

using namespace std;

int rabin_karp(const string &s, const string &temp){
    const ll p=31;
    vector<ll>pow(s.size());
    pow[0] = 1;
    for(int i=1; i<s.size(); i++){
        pow[i] = (pow[i-1]*p) % MD;
    }
    ll hash_temp = 0;
    for(int i=0; i<temp.size(); i++){
        hash_temp = (((temp[i] - 'a' + 1ll)*pow[i]) % MD + hash_temp) % MD;
    }
    vector<ll>hash_s(s.size());
    for(int i=0; i<s.size(); i++){
        hash_s[i] = ((s[i] - 'a' + 1ll)*pow[i]) % MD;
        if (i) hash_s[i] = (hash_s[i] + hash_s[i-1]) % MD;
    }
    for(int i=0; i+temp.size()-1 < s.size(); i++){
        ll cur_h = hash_s[i+temp.size()-1];
        if (i){
            cur_h -= hash_s[i-1];
            if (cur_h < 0)  {
            	cur_h += MD;
            }
        }    
        if(cur_h == (hash_temp*pow[i]) % MD)
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