//
// Created by zouguowei on 2019/7/21.
//

#include <iostream>
#include <queue>
#include <set>

class Point
{
public:

    Point(int x, int y) {
        mX = x;
        mY = y;
        mDirection = RIGHT;
    }

    enum {
        RIGHT,
        DOWN,
        LEFT,
        UP,
    };

    int getDirection() {
        return mDirection;
    }

    int setToNextDiretion() {
        mDirection++;
    }

    int getX() {
        return mX;
    }

    int getY() {
        return mY;
    }

private:
    int mDirection;
    int mX;
    int mY;
};

std::shared_ptr<Point> GetNeighborPoint(Point* point)
{
    std::shared_ptr<Point> neighborPoint = nullptr;
    int x = point->getX();
    int y = point->getY();
    switch (point->getDirection()) {
        case Point::RIGHT:
            neighborPoint = std::make_shared<Point>(point->getX() + 1, point->getY());
            break;
        case Point::DOWN:
            break;
        case Point::LEFT:
            break;
        case Point::UP:
            break;
    }

    return neighborPoint;
}

int main(int argc, char *argv[])
{
    auto startPoint = std::make_shared<Point>(1, 1);
    std::queue<std::shared_ptr<Point>> queue;
    queue.push(startPoint);
    std::set<std::pair<int, int>> visitedPoint;

    while (!queue.empty()) {

        auto currentPoint = queue.back();
        for (int i = currentPoint->getDirection(); i <= Point::UP; i++) {

            auto neighborPoint = GetNeighborPoint(currentPoint.get());


        }

    }

    return 0;
}