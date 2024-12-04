#include<bits/stdc++.h>
using namespace std;

void resize(vector<int> &arr){
    int len = pow(2, ceil(log2(arr.size())));
    arr.resize(len, 0);
}


class Tree{
    public:
        
        int n;
        vector<uint32_t>seg_t;
        Tree(vector<int> &arr){
            n = arr.size();
            seg_t.resize(2*n);
            build(arr, 0, 0, n);
        }
        
        uint32_t sum(int l, int r){
            return _sum(l, r, 0, 0, n);
        }
        void update(int ind, int val){
            _update(ind, val, 0, 0, n);
        }
        int get_ind(int val){
            return _get_ind(val, 0, 0, n);
        }
    private:
        void build(vector<int> &arr, int node, int left, int right){
            if (left == right - 1){
                seg_t[node] = arr[left];
            } else {
                int mid = (left + right) >> 1;
                int leftNode = (node << 1) + 1;
                int rightNode = leftNode + 1;
                build(arr, leftNode, left, mid);
                build(arr, rightNode, mid, right);
                seg_t[node] = seg_t[leftNode] + seg_t[rightNode];
            }
        }
        void _update(int ind, int val, int node, int left, int right){
            if( left == right - 1){
                seg_t[node] = val;
                return;
            }
            int mid = (left+right) >> 1;
            int leftNode = (node << 1) + 1;
            int rightNode = leftNode + 1;
            if(ind < mid){
                _update(ind, val, leftNode, left, mid);
            } else {
                _update(ind, val, rightNode, mid, right);
            }
            seg_t[node] = seg_t[leftNode] + seg_t[rightNode];
        }
        uint32_t  _sum(int left,int  right,int node, int l_seg,int  r_seg){
            if(right <= l_seg || left >= r_seg){
                return 0;
            }
            if (l_seg >= left && r_seg <= right){
                return seg_t[node];
            }
            int mid = (l_seg + r_seg) >> 1;
            int leftNode = (node << 1) + 1;
            int rightNode = leftNode + 1;
            return _sum(left, right, leftNode, l_seg, mid) + _sum(left, right, rightNode, mid, r_seg);
        }
        int _get_ind(int val, int node, int l_seg, int r_seg){
            if (l_seg == r_seg-1){
                return l_seg;
            }
            int mid = (l_seg + r_seg) >> 1;
            int leftNode = (node << 1) + 1;
            int rightNode = leftNode + 1;
            if (seg_t[leftNode] >= val){
                return _get_ind(val, leftNode, l_seg, mid);
            } else {
                return _get_ind(val - seg_t[leftNode], rightNode, mid, r_seg);
            }
        }
};
int main(){
    int n;
    cin>>n;
    vector<int>numbers(n, 1);
    resize(numbers);
    Tree tree(numbers);
    vector<int>move1(n/2);
    vector<int>move2(n/2);
    vector<int>choice1(n/2);
    vector<int>choice2(n/2);
    for(int i=0; i < n/2; i++){
        cin>>move1[i];
    }
    for(int i=0; i < n/2; i++){
        cin>>move2[i];
    }
    for(int i=0; i<n/2; i++){
        int ind = tree.get_ind(move1[i]);
        choice1[i] = ind+1;
        tree.update(ind, 0);
        ind = tree.get_ind(move2[i]);
        choice2[i] = ind+1;
        tree.update(ind, 0);
    }
    for(auto el: choice1){
        cout<<el<<' ';
    }
    cout<<'\n';
    for(auto el: choice2){
        cout<<el<<' ';
    }
    return 0;
}