#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                dp[i][j] = 1;
                continue;
            }
            if (s[i] == s[j]) {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }

    int l = 0, r = n - 1;
    string p = "";

    while (l < r) {
        if (s[l] == s[r]) {
            p += s[l];
            l++;
            r--;
        } else if (dp[l][r - 1] > dp[l + 1][r]) {
            r--;
        } else {
            l++;
        }
    }

    string rev = p;
    reverse(rev.begin(), rev.end());

    if (l == r) {
        p += s[l];
        p += rev;
    } else {
        p += rev;
    }

    cout << p << endl;

    return 0;
}