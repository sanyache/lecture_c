#include<bits/stdc++.h>
using namespace std;

void resize(vector<uint32_t> &arr){
    uint32_t len = pow(2, ceil(log2(arr.size())));
    arr.resize(len, 0);
}

class Tree{
    public:
        
        uint32_t n;
        vector<uint32_t>seg_t, lazy;
        Tree(vector<uint32_t> &arr){
            n = arr.size();
            seg_t.resize(2*n, 0);
            lazy.resize(2*n, 0);
        }
        
        uint32_t sum(uint32_t l, uint32_t r){
            return _sum(l, r, 0, 0, n);
        }
        void update(uint32_t l, uint32_t r){
            _update(l, r, 0, 0, n);
        }
    private:
        
        void propagate(int left, int right, int node){
            if (lazy[node] != 0){
                seg_t[node] = (right-left) - seg_t[node];
                if (right - left > 1){
                    lazy[node*2+1] ^= 1;
                    lazy[node*2+2] ^= 1; 
                }
                lazy[node] = 0;
            }
        }
        void _update(uint32_t left, uint32_t right, uint32_t node, uint32_t l_seg, uint32_t r_seg){
            propagate(l_seg, r_seg, node);    
            if (right <= l_seg || left >= r_seg) {
            return;
        }
            if(left <= l_seg && r_seg <= right){
                lazy[node] ^= 1;
                propagate(l_seg, r_seg, node);
                return;
            }
            uint32_t mid = (l_seg+r_seg)/2;
            _update(left,right, 2*node+1, l_seg, mid);
            _update(left, right, 2*node+2, mid, r_seg);
            
            seg_t[node] = seg_t[node*2 +1] + seg_t[node*2 +2];
        }
        uint32_t  _sum(uint32_t left,uint32_t  right,uint32_t node, uint32_t l_seg,uint32_t  r_seg){
            propagate(l_seg, r_seg, node);
            if(right <= l_seg || left >= r_seg){
                return 0;
            }
            if (l_seg >= left && r_seg <= right){
                return seg_t[node];
            }
            uint32_t mid = (l_seg + r_seg)/2;
            return _sum(left, right, (node*2)+1, l_seg, mid) + _sum(left, right, (node*2)+2, mid, r_seg);
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
            tree.update(l, r + 1);
        } else {
            rez.push_back(tree.sum(l, r+1));
        }
    }   
    for(auto el: rez){
        cout<<el<<'\n';
    }
    return 0;
}