#include<bits/stdc++.h>
using namespace std;

void resize(vector<int64_t> &arr){
    int64_t len = pow(2, ceil(log2(arr.size())));
    arr.resize(len, 0);
}

class Tree{
    public:
        
        int64_t n;
        vector<int64_t>seg_t;
        Tree(vector<int64_t> &arr){
            n = arr.size();
            seg_t.resize(2*n);
            build(arr, 0, 0, n);
        }
        
        int64_t sum(int64_t l, int64_t r){
            return _sum(l, r, 0, 0, n);
        }
        void update(int64_t ind){
            _update(ind, 0, 0, n);
        }
        void print64_t_tree(){
            for(auto el: seg_t){
                cout<<el<<' ';
            }
            cout<<'\n';
        }
    private:
        void build(vector<int64_t> &arr, int64_t node, int64_t left, int64_t right){
            if (left == right - 1){
                seg_t[node] = arr[left];
            } else {
                int64_t mid = (left + right)/2;
                build(arr, node*2 + 1, left, mid);
                build(arr, node*2 + 2, mid, right);
                seg_t[node] = seg_t[node*2+1] + seg_t[node*2+2];
            }
        }
        void _update(int64_t ind, int64_t node, int64_t left, int64_t right){
            if( left == right - 1){
                seg_t[node] = seg_t[node] ? 0 : 1;
                return;
            }
            int64_t mid = (left+right)/2;
            if(ind < mid){
                _update(ind, 2*node+1, left, mid);
            } else {
                _update(ind, 2*node+2, mid, right);
            }
            seg_t[node] = seg_t[2*node+1] + seg_t[2*node+2];
        }
        int64_t  _sum(int64_t left,int64_t  right,int64_t node, int64_t l_seg,int64_t  r_seg){
            if(right <= l_seg || left >= r_seg){
                return 0;
            }
            if (l_seg >= left && r_seg <= right){
                return seg_t[node];
            }
            int64_t mid = (l_seg + r_seg)/2;
            return _sum(left, right, 2*node+1, l_seg, mid) + _sum(left, right, 2*node+2, mid, r_seg);
        } 
};
int main(){
    int64_t n, m, oper, l, r;
    cin>>n>>m;
    vector<int64_t>numbers(n, 0);
    vector<int64_t>rez;
    resize(numbers);
    Tree tree(numbers);
    for(int64_t i=0; i<m; i++){
        cin>>oper>>l>>r;
        l--;
        r--;
        if(oper == 0){
            for(int64_t j=l; j<=r; j++){
                tree.update(j);
            }
        } else {
            rez.push_back(tree.sum(l, r+1));
        }
    }   
    for(auto el: rez){
        cout<<el<<'\n';
    }
    return 0;
}