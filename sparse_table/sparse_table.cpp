#include<iostream>
using namespace std;

const int MAXN = 100000, LOG = 17;
int st[LOG + 1][MAXN];   // st[k][i] = max на [i, i + 2^k - 1]
int lg[MAXN + 1];         // lg[x] = найбільше k, що 2^k <= x   
void build(const vector<int>& a) {
    int n = a.size();
    lg[1] = 0;
    for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

    for (int i = 0; i < n; i++) st[0][i] = a[i];          // довжина 1
    for (int k = 1; (1 << k) <= n; k++)                   // довжина 2^k
        for (int i = 0; i + (1 << k) <= n; i++)            // блок не виходить за край
            st[k][i] = max(st[k - 1][i],                       // ліва половинка
                           st[k - 1][i + (1 << (k - 1))]);     // права половинка
}

int query(int L, int R) {                             // L і R включно
    int k = lg[R - L + 1];
    return max(st[k][L], st[k][R - (1 << k) + 1]);       // два блоки, можуть перекриватись
}




int main(){

     
    return 0;
}
