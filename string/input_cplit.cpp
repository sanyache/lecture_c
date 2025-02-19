#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

void input_vector(vector<int> &A){
    string s;
    getline(cin, s);
    stringstream ss(s);
    int x;
    while (ss >> x)
    {
        A.push_back(x);
    }   

}

void print_vector(vector<int> &A){
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> A;
    input_vector(A);
    print_vector(A);
    return 0;
}