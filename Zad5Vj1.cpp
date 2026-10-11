#include <iostream>
#include <cmath>

struct Point {
    double x, y;
};

void move_bypointer(Point* p, double dx, double dy) {
    p->x += dx;
    p->y += dy;
}

double distpointer(const Point *a, const Point *b) {
    return std::sqrt((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
}

void move_by(Point& p, double dx, double dy) {
    p.x += dx;
    p.y += dy;
}

double dist(const Point& a, const Point& b) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}



int main() {
    Point i = {1, 2};
    Point j = {3, 4};
    distpointer(&i, &j);
    move_bypointer(&i, 1, 1);
    dist(i, j);
    move_by(i, 1, 1);
    // Funkcije s pointerom zahtijevaju referencu u pozivu, funkcije s referencom zahtijevaju vrijednost u pozivu.
    Point nula = {0, 0};
    Point a[5] = {{1, 2}, {-1, 1}, {3, 5}, {4, 9}, {0.5, 0.5}};
    int najmanje = 0;
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
        if (abs(dist(a[i], nula)) < abs(dist(a[najmanje], nula))) {
            najmanje = i;
        }
    }
    std::cout << "Najbliza tocka ishodistu je: " << a[najmanje].x << ", " << a[najmanje].y << std::endl;
    return 0;
}