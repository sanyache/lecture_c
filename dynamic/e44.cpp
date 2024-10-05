#include <iostream>
#include <vector>
#include <algorithm>

int minOnes(int n) {
    // Вектор для зберігання мінімальної кількості одиниць для кожного числа від 0 до n
    std::vector<int> dp(n + 1, n + 1);

    // Для числа 1 потрібна одна одиниця
    dp[1] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (i + j <= n) {
                dp[i + j] = std::min(dp[i + j], dp[i] + dp[j]);
            }
            if (i * j <= n) {
                dp[i * j] = std::min(dp[i * j], dp[i] + dp[j]);
            }
        }

    }

    return dp[n];
}

int main() {
    int n;
    std::cin >> n;

    int result = minOnes(n);
    std::cout<<result;
    return 0;
}
