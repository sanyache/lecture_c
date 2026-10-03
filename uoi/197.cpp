#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<ll> A(n, 0);

    // L[i] — найближча L справа від i
    vector<int> L(n, n);

    // R[i] — найближча R зліва від i
    vector<int> R(n, -1);

    int curr_l = n;

    for (int i = n - 1; i >= 0; i--) {
        L[i] = curr_l;

        if (s[i] == 'L') {
            curr_l = i;
        }
    }

    int curr_r = -1;

    for (int i = 0; i < n; i++) {
        R[i] = curr_r;

        if (s[i] == 'R') {
            curr_r = i;
        }
    }

    ll t;
    cin >> t;

    for (int i = 0; i < n; i++) {

        if (s[i] == 'R') {

            int j = L[i];

            // Немає L справа — робот весь час іде вправо
            if (j == n) {
                if ((ll)i + t < n) {
                    A[i + t]++;
                }
                continue;
            }

            // Відстань до першої L
            ll dist = j - i;

            // Робот ще не дійшов до циклу
            if (t < dist) {
                A[i + t]++;
            }
            else {
                // Робот уже в циклі j-1 <-> j
                if ((t - dist) % 2 == 0) {
                    A[j]++;
                }
                else {
                    A[j - 1]++;
                }
            }

        }
        else { // s[i] == 'L'

            int j = R[i];

            // Немає R зліва — робот весь час іде вліво
            if (j == -1) {
                if ((ll)i - t >= 0) {
                    A[i - t]++;
                }
                continue;
            }

            // Відстань до першої R
            ll dist = i - j;

            // Робот ще не дійшов до циклу
            if (t < dist) {
                A[i - t]++;
            }
            else {
                // Робот уже в циклі j <-> j+1
                if ((t - dist) % 2 == 0) {
                    A[j]++;
                }
                else {
                    A[j + 1]++;
                }
            }
        }
    }

    for (ll x : A) {
        cout << x << ' ';
    }

    return 0;
}