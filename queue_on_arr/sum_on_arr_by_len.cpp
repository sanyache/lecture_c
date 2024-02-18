#include<iostream>
// знайти найбільшу суму пари елементів, що знаходяться на відстані не меньше 5 елементів
using namespace std;

int main(){

    int A[] = {1, 3, 4, 7, 8, 9, 2, 3, 6, 1};
    int n = sizeof(A)/sizeof(A[0]);
    int max_sum = -1;
    for(int i=0; i<n-5; i++){
        for(int j=i+5; j<n; j++){
            int sum_pair = A[i] + A[j];
            if(sum_pair > max_sum) max_sum = sum_pair;
        }
    }
    cout<<max_sum;
    return 0;
}
