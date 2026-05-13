#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

struct Point
{
    float x;
    float y;
};

float polygonArea(const vector<Point> &points){
    int n = points.size();
    float s = 0;
    for(int i=0; i<n-1; i++){
        s += points[i].x * points[i+1].y - points[i+1].x * points[i].y;
    }
    s += points[n-1].x * points[0].y - points[0].x * points[n-1].y;
    return fabs(s/2.0);
}

int main(){

    int n;
    cin>>n;
    vector<Point> points(n);
    for(int i=0; i<n; i++){
        cin>>points[i].x>>points[i].y;
    }
    cout<<polygonArea(points);
    return 0;
}
// (3,6) (3,10) (6.42, 12) (9.84, 10) (9.84, 6) (6.42, 4) - 41.04