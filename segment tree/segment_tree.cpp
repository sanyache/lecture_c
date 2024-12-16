#include<bits/stdc++.h>
using namespace std;

void resize(vector<int> &arr){
    int len = pow(2, ceil(log2(arr.size())));
    arr.resize(len, 0);
}

class Tree{
    public:
        
        int n;
        vector<int64_t>seg_t;
        Tree(vector<int> &arr){
            n = arr.size();
            seg_t.resize(2*n);
            build(arr, 0, 0, n);
        }
        
        int64_t sum(int l, int r){
            return _sum(l, r, 0, 0, n);
        }
        void update(int ind, int val){
            _update(ind, val, 0, 0, n);
        }
        void print_tree(){
            for(auto el: seg_t){
                cout<<el<<' ';
            }
        }
    private:
        void build(vector<int> &arr, int node, int left, int right){
            if (left == right - 1){
                seg_t[node] = arr[left];
            } else {
                int mid = (left + right)/2;
                build(arr, node*2 + 1, left, mid);
                build(arr, node*2 + 2, mid, right);
                seg_t[node] = seg_t[node*2+1] + seg_t[node*2+2];
            }
        }
        void _update(int ind, int val, int node, int left, int right){
            if( left == right - 1){
                seg_t[node] = val;
                return;
            }
            int mid = (left+right)/2;
            if(ind < mid){
                _update(ind, val, 2*node+1, left, mid);
            } else {
                _update(ind, val, 2*node+2, mid, right);
            }
            seg_t[node] = seg_t[2*node+1] + seg_t[2*node+2];
        }
        int64_t  _sum(int left,int  right,int node, int l_seg,int  r_seg){
            if(right <= l_seg || left >= r_seg){
                return 0;
            }
            if (l_seg >= left && r_seg <= right){
                return seg_t[node];
            }
            int mid = (l_seg + r_seg)/2;
            return _sum(left, right, 2*node+1, l_seg, mid) + _sum(left, right, 2*node+2, mid, r_seg);
        } 
};
int main(){
    int n;
    cin>>n;
    vector<int>numbers(n);
    for(int i=0; i<n; i++){
        cin>>numbers[i];
    }
    resize(numbers);
    Tree tree(numbers);
    //tree.update(4, 1);
    cout<<tree.sum(1, 6);
    tree.print_tree();
    return 0;
}