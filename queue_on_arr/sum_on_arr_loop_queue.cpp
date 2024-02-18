#include<iostream>

using namespace std;


int main(){
    int n=10;
    int len_q = 5;
    int Q[len_q];
    int q_end = 0;
    int max_pop = -1;
    int max_sum = 0;
    for(int i=0; i<len_q; i++){
        cin>>Q[i];
    }
    for(int i=len_q; i<n; i++){
        int current;
        cin>>current;
        if(Q[q_end] > max_pop){
            max_pop = Q[q_end];
        }
        if(max_pop + current > max_sum) max_sum = max_pop + current;
        Q[q_end] = current;
        q_end = (++q_end)%len_q;

    }
    cout<<max_sum;
    return 0;
}
