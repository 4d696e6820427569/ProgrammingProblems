/**
 * Implementation of Closest Points agorithm in 2D space.
 * Minimum C++ version: C++98.
 * Author: Minh Bui
 */

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <cassert>

struct Point
{
    Point(float _x, float _y)
        : x(_x), y(_y)
    {}
    Point() = default;
    Point(const Point& p)
        : x(p.x), y(p.y)
    {}
    Point& operator=(const Point& p) = default;
    ~Point() = default;

    bool operator<(const Point& p) const
    {
        if (this->x == p.x) return this->y < p.y;
        return this->x < p.x;
    }

    bool operator==(const Point& p) const
    {
        return this->x == p.x && this->y == p.y;
    }
    
    float x;
    float y;
};

float EuclideanDistance(const Point& p1, const Point& p2)
{
    return sqrtf( 
                (p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y)
            );
}

void PrintPoints(const std::vector<Point>& points)
{
    for (size_t i = 0; i < points.size(); i++) {
        printf("%d %d\n", (int) points[i].x, (int) points[i].y);
    }
}

void ClosestPoints(std::vector<Point>& points, std::vector<Point>& result)
{
    std::sort(std::begin(points), std::end(points));
}

void ClosestPointsBF(std::vector<Point>& points, std::vector<Point>& result)
{
    float min_d = std::numeric_limits<float>::max();
    Point p1, p2;
    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = i + 1; j < points.size(); j++) {
            float cur_dist = EuclideanDistance(points[i], points[j]);
            if (cur_dist < min_d) {
                min_d = cur_dist;
                p1 = points[i];
                p2 = points[j];
            }
        }
    }

    result.emplace_back(p1);
    result.emplace_back(p2);
}

int main()
{
    float x, y;
    std::vector<Point> points;
    while (scanf("%f %f", &x, &y) != EOF) {
        points.push_back(Point(x, y));
    }
    
    std::vector<Point> closestPointsBF_result;
    std::vector<Point> closestPointsDiv_result;

    ClosestPoints(points, closestPointsDiv_result);
    ClosestPointsBF(points, closestPointsBF_result);

    assert((closestPointsBF_result == closestPointsDiv_result) || [&]() {
        std::reverse(std::begin(closestPointsBF_result), std::end(closestPointsBF_result));
        return closestPointsBF_result == closestPointsDiv_result;
    }());

    PrintPoints(closestPointsDiv_result);
    return 0;
}
