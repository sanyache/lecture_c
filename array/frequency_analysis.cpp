#include<iostream>

using namespace std;

int main(){
    int start =16;
    int stop = 80;
    int n = stop - start;
    int C[n+1];
    for(int i=0; i<=n; i++){
        C[i]=0;
    }
    int x;
    while(cin>>x){
        C[x-start]++;
    }
    for(int i=0; i<=n; i++){
        cout<<i+start<<' '<<C[i]<<endl;
    }
    return 0;
}
