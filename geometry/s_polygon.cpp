#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x;
    double y;
};

// Функція для обчислення площі многокутника
double polygonArea(const vector<Point>& points) {
    int n = points.size();
    double area = 0;

    for (int i = 0; i < n; ++i) {
        const Point& p1 = points[i];
        const Point& p2 = points[(i + 1) % n]; // наступна точка, з циклічністю
        area += (p1.x * p2.y - p1.y * p2.x);   // векторний добуток
    }

    return fabs(area) / 2.0; // модуль половини суми векторних добутків
}

int main() {
    int n;
    cout << "Введіть кількість вершин багатокутника: ";
    cin >> n;

    vector<Point> points(n);
    cout << "Введіть координати " << n << " точок (x y):\n";
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    double area = polygonArea(points);
    cout << "Площа багатокутника: " << area << endl;

    return 0;
}
// (3,6) (3,10) (6.42, 12) (9.84, 10) (9.84, 6) (6.42, 4) - 41.04