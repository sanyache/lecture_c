#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n;
    cin>>n;
    queue<int> q;
    for(int i=0; i<n; i++){
        int val;
        cin>>val;
        q.push(val);
    }
    int k;
    cin>>k;
    int cnt = 0;
    while (! q.empty())
    {
        int curr = q.front() - 1;
        q.pop();
        if (k == 0 and curr == 0){
            cnt ++;
            break;
        }
        if (curr != 0){
            q.push(curr);
        }
        cnt ++;
        k --;
        if (k == -1){
            k = q.size() -1;
        }    
    }
    cout<<cnt<<'\n';
    return 0;
}
// стоїть черга за квитками, купивши за 1хв один квиток, переходить в кінець черги. 
// якщо купив всі - то вибуває з черги. Коли скупиться k - член черги.
// tickets = [2,3,2], k = 2. output: 6
// tickets = [5,1,1,1], k = 0 output: 8