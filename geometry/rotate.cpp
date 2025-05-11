#include <iostream>

using namespace std;

// Структура для представлення точки
struct Point {
    double x;
    double y;
};

// Функція визначає положення точки C відносно вектора AB
// Повертає: -1 → зліва, 1 → справа, 0 → на лінії
int rotate(const Point& A, const Point& B, const Point& C) {
    // Обчислення векторного добутку AB × AC
    double cross = (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);

    if (cross > 0) return -1;   // точка зліва
    if (cross < 0) return 1;    // точка справа
    return 0;                   // точка лежить на прямій AB
}

int main() {
    Point A, B, C;

    // Ввід координат
    cout << "Введіть координати точки A (x y): ";
    cin >> A.x >> A.y;
    cout << "Введіть координати точки B (x y): ";
    cin >> B.x >> B.y;
    cout << "Введіть координати точки C (x y): ";
    cin >> C.x >> C.y;

    // Визначення положення
    int result = rotate(A, B, C);

    // Вивід результату
    if (result == -1)
        cout << "Точка C знаходиться зліва від вектора AB." << endl;
    else if (result == 1)
        cout << "Точка C знаходиться справа від вектора AB." << endl;
    else
        cout << "Точка C лежить на лінії AB." << endl;

    return 0;
}
