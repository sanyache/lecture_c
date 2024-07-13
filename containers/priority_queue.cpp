#include<iostream>
#include<vector>
#include<queue>

using namespace std;

template<typename T>
void print_pq( T& pq){
    for(; !pq.empty(); pq.pop()){
        cout<<pq.top()<<' ';
    }
}

int main(){

    const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};
    priority_queue<int> max_priority_queue;
    for(auto el : data){
        max_priority_queue.push(el);
    }
    print_pq(max_priority_queue);
    priority_queue<int, std::vector<int>, std::greater<int>>
                  min_priority_queue(data.begin(), data.end());
    // for(auto el : data){
    //     min_priority_queue.push(el);
    // }
    print_pq(min_priority_queue);
    return 0;
}