#include <iostream>
#include <cmath>

using namespace std;

// Структура для зберігання координат точки
struct Point {
    double x;
    double y;
};

// Функція для обчислення довжини вектора між двома точками
double vectorLength(const Point& a, const Point& b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    Point A, B;

    // Ввід координат точок
    cout << "Введіть координати точки A (x y): ";
    cin >> A.x >> A.y;

    cout << "Введіть координати точки B (x y): ";
    cin >> B.x >> B.y;

    // Обчислення довжини вектора
    double length = vectorLength(A, B);

    // Вивід результату
    cout << "Довжина вектора AB: " << length << endl;

    return 0;
}
// 1 1, 4 5 - 5