#include<iostream>

using namespace std;

int main(){

    int N,M;
    cin>>N>>M;
    int A[N][M];
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin>>A[i][j];
    for(int j=0; j<M; j++){
        int s=0;
        for(int i=0; i<N; i++)
            s += A[i][j];
        cout<<s<<'\t';
    }
    return 0;
}
