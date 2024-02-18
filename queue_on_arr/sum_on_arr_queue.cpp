#include<iostream>

using namespace std;

void print_arr(int A[], int n){
    for(int i=0; i<n; i++){

        cout<<A[i]<<' ';
    }
    cout<<'\n';
}

int push_queue(int Q[], int len_q, int push_el){
    int pop = Q[0];
    for(int i=0; i<len_q-1; i++){
        Q[i] = Q[i+1];
    }
    Q[len_q-1] = push_el;
    return pop;
}

int main(){
    int A[] = {1, 3, 4, 7, 8, 9, 2, 3, 6, 1};
    int len_q = 5;
    int Q[len_q];
    int n = sizeof(A)/sizeof(A[0]);
    int max_pop = -1;
    int max_sum = 0;
    for(int i=0; i<len_q; i++) Q[i] = A[i];
    for(int i=len_q; i<n; i++){
        int pop_queue = push_queue(Q, len_q, A[i]);
        print_arr(Q, len_q);
        if(pop_queue > max_pop){
            max_pop = pop_queue;
        }
        if(max_sum < max_pop + Q[len_q-1]){
                max_sum = max_pop + Q[len_q-1];
        }
    }
    cout<<max_sum;
    return 0;
}
