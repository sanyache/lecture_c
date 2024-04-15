// найбільший в кожному стовпці

#include<iostream>

using namespace std;
int main(){
    int N, M;
    cin>>N>>M;
    int A[N][M];
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin>>A[i][j];
     for(int j=0; j<M; j++){
        int max_el = -100;
        for(int i=0; i<N; i++){
            if (A[i][j] > max_el) swap(max_el, A[i][j]);
        }
        cout<<max_el<<' ';
     }
     return 0;
 }
