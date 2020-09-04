//
// Created by lwl on 2020/8/7.
//
#include "smart-pointer.h"

class Point {
public:
    Point(int xVal = 0, int yVal = 0) : x(xVal), y(yVal) {}

    int getX() const { return x; }

    int getY() const { return y; }

    void setX(int xVal) { x = xVal; }

    void setY(int yVal) { y = yVal; }

private:
    int x, y;

};

int main() {
    Point *p = new Point(20, 10);
    {
        smartPointer<Point> ptr1(p);
        {
            smartPointer<Point> ptr2(ptr1);
            {
                smartPointer<Point> ptr3(ptr1);
            }
        }
    }
    cout << p->getX() << endl;
    return 0;
}