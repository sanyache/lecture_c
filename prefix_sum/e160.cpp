#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

int main(){
    int64_t n;
    cin>>n;
    int64_t A[n];
    string s;
    cin>>s;
    for(int64_t i=0; i<n; i++){
        A[i] = (s[i] == 'b') ? 1 : -1;
    }
    int64_t prefix = 0;
    int64_t counter = 0;
    unordered_map<int64_t, int64_t>sum_map;
    sum_map[0] = 1;
    for(int64_t  i=1; i<n+1; i++){
        prefix += A[i-1];
        if (sum_map.find(prefix) != sum_map.end()) {
            counter += sum_map[prefix];
            sum_map[prefix] += 1;
        } else {
            sum_map[prefix] = 1;
        }
    } 
    cout<<counter;           
    return 0;
}