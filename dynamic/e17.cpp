#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long F, F_prev = 1;
    for(int i=1; i<=n; i++){
        F = F_prev*3;
        F_prev = 1<<i;
        cout<<"i="<<i<<' '<<F<<'\n';
    }
    cout<<F;
    return 0;
}
