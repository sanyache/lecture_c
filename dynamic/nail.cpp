#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int n;
    cin>>n;
    int nail[n+1];
    for(int i=1; i<=n; i++) cin>>nail[i];
    int dist [n+1];
    sort(nail+1, nail+n+1);
    dist[1] = 10001; dist[2] = nail[2] - nail[1];
    for(int i=3; i<=n; i++){
        dist[i] = min(dist[i-2], dist[i-1]) + nail[i] - nail[i-1];
        cout<<dist[i]<<' ';
    }
    cout<<dist[n];
    return 0;
}
// Дано кординати цвяхів на прямій. Будь які 2 можна з'єднати ниткою. З'єднати пари ниткою так, щоб кожен
// до кожен цвях був підвізаний ниткою, а довжини всіх ниточок була мінімальною.  2 <= N <= 100.
// Значення координат не перевищують 10000.
// 6
// 3 4 12 6 14 13
// ans 5
