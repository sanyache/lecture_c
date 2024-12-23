#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int path [10000];

void print_path(int start, int stop){
    if(start == stop){
        cout<<start<<'\n';
        return;
    }
    print_path(start, path[stop]);
    cout<<stop<<'\n';

}

int add_one(int x){
    if(x/1000 != 9) return x + 1000;
    return x;
}

int minus_one(int x){
    if(x%10 != 1) return x - 1;
    return x;
}

int shift_left(int x){
    
    return (x%1000)*10 + x/1000;
}

int shift_right(int x){
    return (x%10)*1000 + x/10;
}

void bfs(int start, int stop){
    vector<bool> visited(10000, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        auto current = q.front();
        q.pop();
        int moves[4] = {add_one(current), minus_one(current), shift_left(current), shift_right(current)};
        for(int i=0; i<4; i++){
            if (moves[i] == stop)
            {
                path[moves[i]] = current;
                return;
            }
            if(!visited[moves[i]]){
                visited[moves[i]] = true;
                q.push(moves[i]);
                path[moves[i]] = current;

            }
            
        }
    }
    
     
}


int main(){
    int start, stop;
    cin>>start>>stop;
    bfs(start, stop);
    print_path(start, stop);
    return 0;
}