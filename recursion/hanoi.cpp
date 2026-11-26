#include <iostream>
using namespace std;
void hanoi(int n, int start, int from, int tmp) {
    if (n == 1) {
        cout <<n<<' '<< start << " -> " << from << endl;
        return;
    }
    hanoi(n - 1, start, tmp, from);   // n-1 дисків: start → tmp
    cout <<n<<' '<< start << " -> " << from << endl; // найбільший диск
    hanoi(n - 1, tmp, from, start);   // n-1 дисків: tmp → from
}
int main() {
    int n = 4;
    hanoi(n, 1, 3, 2);
    return 0;
}