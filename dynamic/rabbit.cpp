#include<iostream>

using namespace std;

int main(){
    int n, k;
    cout<<"Enter the max step= ";
    cin>>k;
    cout<<"Enter the number of steps in stair= ";
    cin>>n;
    int stair[n+1]={0};
    stair[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=min(i, k); j++){
            stair[i] += stair[i-j]; 
        }
        cout<<i<<"  "<<stair[i]<<'\n';
    }
    for(int i=0; i<=n; i++) cout<<stair[i]<<' ';
    return 0;
}
// 3 10 - 274