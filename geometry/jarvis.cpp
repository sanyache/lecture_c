#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

// Векторний добуток AB × AC
double cross(const Point& A, const Point& B, const Point& C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

// Пошук найменшої випуклої оболонки
vector<Point> convexHull(const vector<Point>& points) {
    int n = points.size();
    if (n < 3) return {};  // Мінімум 3 точки

    vector<Point> hull;
    int leftmost = 0;

    // Знайдемо найлівішу точку
    for (int i = 1; i < n; ++i) {
        if (points[i].x < points[leftmost].x ||
           (points[i].x == points[leftmost].x && points[i].y < points[leftmost].y)) {
            leftmost = i;
        }
    }

    int p = leftmost;
    do {
        hull.push_back(points[p]);
        int q = (p + 1) % n;

        for (int r = 0; r < n; ++r) {
            if (cross(points[p], points[q], points[r]) < 0) {
                q = r;  // points[r] лівіше від points[q]
            }
        }

        p = q;
    } while (p != leftmost);  // Поки не повернемось до початку

    return hull;
}

int main() {
    int n;
    cout << "Кількість точок: ";
    cin >> n;

    vector<Point> points(n);
    cout << "Введіть координати " << n << " точок (x y):\n";
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> hull = convexHull(points);

    cout << "Випукла оболонка (у порядку обходу):\n";
    for (const Point& p : hull) {
        cout << "(" << p.x << ", " << p.y << ")\n";
    }

    return 0;
}
//Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
//{3, 0}, {0, 0}, {3, 3}};
// Output (0, 3),(0, 0),(3, 0),(3, 3)