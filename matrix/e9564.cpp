//Рядки з максимальною сумою

#include<iostream>

using namespace std;

int main(){
    int N, M;
    cin>>N>>M;
    int A[N];
    int max_sum = -100*M;
    for(int i=0; i<N; i++){
        int sum_row = 0;
        for(int j=0; j<M; j++){
            int el;
            cin>>el;
            sum_row += el;
        }
        A[i] = sum_row;
        if(sum_row > max_sum) max_sum = sum_row;
    }
    for(int i=0; i<N; i++){
        if(A[i] == max_sum) cout<<i+1<<' ';
    }
    return 0;
}
