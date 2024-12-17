#include<bits/stdc++.h>
using namespace std;

void resize(vector<uint32_t> &arr){
    uint32_t len = pow(2, ceil(log2(arr.size())));
    arr.resize(len, 0);
}

class Tree{
    public:
        
        uint32_t n;
        vector<uint32_t>seg_t;
        Tree(vector<uint32_t> &arr){
            n = arr.size();
            seg_t.resize(2*n);
            build(arr, 0, 0, n);
        }
        
        uint32_t sum(uint32_t l, uint32_t r){
            return _sum(l, r, 0, 0, n);
        }
        void update(uint32_t l, uint32_t r){
            _update(l, r, 0, 0, n);
        }
        void print_tree(){
            for(auto el: seg_t){
                cout<<el<<' ';
            }
            cout<<'\n';
        }
    private:
        void build(vector<uint32_t> &arr, uint32_t node, uint32_t left, uint32_t right){
            if (left == right - 1){
                seg_t[node] = arr[left];
            } else {
                uint32_t mid = (left + right)>>1;
                build(arr, (node<<1)+ 1, left, mid);
                build(arr, (node<<1) + 2, mid, right);
                seg_t[node] = seg_t[(node<<1)+1] + seg_t[(node<<1)+2];
            }
        }
        void _update(uint32_t left, uint32_t right, uint32_t node, uint32_t l_seg, uint32_t r_seg){
           if (right <= l_seg || left >= r_seg) {
            return;
        }
            if(l_seg == r_seg - 1){
                cout<<'l'<<l_seg<<" r"<<r_seg<<" node "<<node<<'\n';
                seg_t[node] ^= 1;
                return;
            }
            uint32_t mid = (l_seg+r_seg)/2;
            _update(left,right, 2*node+1, l_seg, mid);
            _update(left, right, 2*node+2, mid, r_seg);
            
            seg_t[node] = seg_t[node*2 +1] + seg_t[node*2 +2];
        }
        uint32_t  _sum(uint32_t left,uint32_t  right,uint32_t node, uint32_t l_seg,uint32_t  r_seg){
            if(right <= l_seg || left >= r_seg){
                return 0;
            }
            if (l_seg >= left && r_seg <= right){
                return seg_t[node];
            }
            uint32_t mid = (l_seg + r_seg)>>1;
            return _sum(left, right, (node<<1)+1, l_seg, mid) + _sum(left, right, (node<<1)+2, mid, r_seg);
        } 
};
int main(){
    uint32_t n, m, oper, l, r;
    cin>>n>>m;
    vector<uint32_t>numbers(n, 0);
    vector<uint32_t>rez;
    resize(numbers);
    Tree tree(numbers);
    for(uint32_t i=0; i<m; i++){
        cin>>oper>>l>>r;
        l--;
        r--;
        if(oper == 0){
            tree.update(l, r);
        } else {
            rez.push_back(tree.sum(l, r+1));
        }
        tree.print_tree();
    }   
    for(auto el: rez){
        cout<<el<<'\n';
    }
    return 0;
}