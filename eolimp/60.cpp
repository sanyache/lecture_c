#include<iostream>
#include<vector>
#include<iomanip>


using namespace std;

struct Point{

    int x;
    int y;
};

int main(){

    vector<Point>Polygon;
    float S=0*1.0;
    int n;
    cin>>n;
    Polygon.reserve(n);
    for(size_t i=0; i<n; i++){
        Point point;
        cin>>point.x>>point.y;
        Polygon.push_back(point);
    }
    for(size_t i=0; i<n-1; i++){

        S += Polygon[i].x*Polygon[i+1].y - Polygon[i+1].x*Polygon[i].y;
    }
    S += Polygon[n-1].x*Polygon[0].y - Polygon[0].x*Polygon[n-1].y;
    S = (S>0)?S/2.0:(-S)/2.0;
    cout<<setprecision(3)<<fixed<<S;
    return 0;
}
