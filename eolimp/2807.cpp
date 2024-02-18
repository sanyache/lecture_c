#include<iostream>

using namespace std;

int main(){
    int A[52] {0};
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        char letter;
        cin >> letter;
        int pos = (islower(letter)) ? letter - 'a' : letter - 'A' + 26;
        if(A[pos] == 0) A[pos] = 1;
        else A[pos] = 0;

    }
    if(n%2 == 0){
        cout<<"Ok";
        return 0;
    }
    for(int i=0; i<52; i++){
        if(A[i] == 1){
            char lost_letter = i < 26 ? i + 97: i + 39;
            cout<<sizeof(lost_letter)<<' ';
            cout<<lost_letter;
            break;
        }
    }
    return 0;
}
