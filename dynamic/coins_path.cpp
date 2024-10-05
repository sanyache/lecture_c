#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int coins[] = {1, 3, 4};
    int n;
    cin>>n;
    int value[n+1];
    int first_coin[n+1];
    value[0] = 0;
    for(int i=1; i<=n; i++){
        value[i] = i;
        for(auto c: coins){
            if(i-c >= 0 and value[i-c]+1 < value[i]){
                value[i] = value[i-c]+1;
                first_coin[i] = c;
            }
        }
    }
    cout<<value[n]<<'\n';
    while(n>0){
        cout<<first_coin[n]<<' '<<'\n';
        n -= first_coin[n];
    }
    return 0;
}
