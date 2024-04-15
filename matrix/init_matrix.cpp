#include<iostream>

using namespace std;

int main(){
    int B[] = {1,2,3,4};
    cout<<*B<<'\n';
    int N, M;
    cin>>N>>M;
    int A[N][M];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            A[i][j] = (i*M+j);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<<A[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<**(A)<<**(A+1)<<endl;
    int C[2][4] = {{0,1,2,3},{4,5,6,7}};
    for(int i=0; i<2; i++){
        for(int j=0; j<4; j++)
            cout<<C[i][j]<<' ';
        cout<<'\n';
    }
    int D[2][3] = {1,2,3,4,5,6};
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++)
            cout<<D[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}
