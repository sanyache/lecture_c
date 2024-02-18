#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int A[10];
    for(int i=1; i<10; i++) A[i] = 0;
    for(int i=0; i<n; i++){
        int color;
        cin>>color;
        A[color] ++;
    }
    int max_color=0;
    for(int i=1; i<10; i++){
        if(A[i] > max_color) max_color = A[i];

    }
    cout<<n-max_color;
    return 0;
}
