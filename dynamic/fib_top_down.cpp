#include<iostream>

using namespace std;

const int maxN = 51;

uint64_t fib_dynamic(int i){
    static uint64_t knownF[maxN];
    cout<<"i="<<i<<'\t';
    if(knownF[i] != 0) return knownF[i];
    int t = i;

    if(i<=0) return 0;
    if(i>1) return knownF[i] = fib_dynamic(i-1) + fib_dynamic(i-2);

}

int main(){

    int n;
    cin>>n;
    for(int i=0; i<=4; i++){
        cout<<i<<'\t'<<fib_dynamic(i)<<'\n';
    }
    return 0;
}
