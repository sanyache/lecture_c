//сума підмасиву

#include<iostream>

using namespace std;

int main(){
    int N, M;
    cin>>N>>M;
    int A[N][M];
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin>>A[i][j];
    int c1,r1,c2,r2;
    cin>>c1>>r1>>c2>>r2;
    int S=0;
    for(int i=c1-1; i<c2; i++){
        for(int j=r1-1; j<r2; j++)
            S += A[i][j];
    }
    cout<<S;
    return 0;
}
