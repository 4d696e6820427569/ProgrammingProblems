/**
 * Implementation of Closest Points agorithm in 2D space.
 * Minimum C++ version: C++98.
 * Author: Minh Bui
 */

#include <cstdio>
#include <vector>
#include <algorithm>

struct Point
{
    Point(int _x, int _y)
        : x(_x), y(_y)
    {}

    bool operator<(const Point& p) const
    {
        if (this->x == p.x) return this->y < p.y;
        return this->x < p.x;
    }
    
    float x;
    float y;
};

void PrintPoints(const std::vector<Point>& points)
{
    for (size_t i = 0; i < points.size(); i++) {
        printf("%d %d\n", (int) points[i].x, (int) points[i].y);
    }
}

std::vector<Point> ClosestPoints(std::vector<Point>& points)
{
    std::vector<Point> result;
    std::sort(std::begin(points), std::end(points));
    return result;
}

int main()
{
    float x, y;
    std::vector<Point> points;
    while (scanf("%f %f", &x, &y) != EOF) {
        points.push_back(Point(x, y));
    }

    PrintPoints(ClosestPoints(points));
    return 0;
}
