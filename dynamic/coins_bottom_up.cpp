#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int coins[] = {1, 3, 4};
    int n;
    cin>>n;
    int value[n+1];
    value[0] = 0;
    for(int i=1; i<=n; i++){
        value[i] = i;
        for(auto c: coins){
            if(i-c >= 0){
                value[i] = min(value[i], value[i-c]+1);
            }    
        }
    }
    cout<<value[n];
    return 0;
}