#include<iostream>
#include<vector>

using namespace std;

#define mod 1000000007;

int64_t comb(int n, int k){
    vector <int64_t> dp(k+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = min(i, k); j > 0; j--){
            dp[j] = (dp[j] + dp[j-1]) % mod;
        }
    }
    return dp[k];
}

int64_t catalan(int n){
    if(n == 0 || n == 1) return 1;
    vector <int64_t> cat(n+1, 0);
    cat[0] = 1;
    cat[1] = 1;
    for(int i = 2; i <= n; i++){
        cat[i] = 0;
        for(int j = 0; j < i; j++){
            cat[i] = (cat[i] + cat[j] * cat[i-j-1]) % mod;
        }
    }
    return cat[n];
}



int main(){
    int n;
    cin >> n;
    vector <int64_t> ans;
    for(int i=0; i<n; i++){
        int k;
        cin >> k;
        int K[k];
        int sum = 0;
        for(int j=0; j<k; j++){
            cin >> K[j];
            sum += K[j];
        }
        int64_t res = catalan(sum);
        for(int i=0; i<k; i++){
            res = (res * comb(sum, K[i])) % mod;
            sum -= K[i];
        }
        ans.push_back(res);
    }
    for(int i=0; i<n; i++){
        cout << ans[i] << endl;
    }
    return 0;
}