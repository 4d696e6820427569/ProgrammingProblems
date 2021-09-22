/**
 * Implementation of Convex Hull (Graham Scan) in 2D space.
 * Minimum C++ version: C++98
 * Author: Minh Bui
 */

#include <cstdio>
#include <vector>
#include <algorithm>

struct Point
{
    Point(int _x, int _y) : x(_x), y(_y) {}
    float x;
    float y;
};

struct Vect2D
{
    Vect2D(float _x, float _y) : x(_x), y(_y), z(0.0f) {}
    Vect2D(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vect2D(const Point& p1, const Point& p2)
        : x(p2.x - p1.x)
        , y(p2.y - p1.y)
        , z(0.0f)
    {}

    Vect2D CrossProduct2D(const Vect2D& v)
    {
        return Vect2D(0.0f, 0.0f, x * v.y - v.x * y);
    }

    float x;
    float y;
    float z;
};


struct CoordinateCmp
{
    bool operator()(const Point& lhs, const Point& rhs) const
    {
        if (lhs.y == rhs.y)
            return lhs.x < rhs.x;
        else
            return lhs.y < rhs.y;
    }
} CoordinateCmp;

struct CrossProductCmp
{
    CrossProductCmp(Point& _p) : p(_p) {}
    bool operator()(const Point& lhs, const Point& rhs) const
    {
        return Vect2D(p, lhs).CrossProduct2D(Vect2D(p, rhs)).z; 
    }

    Point& p;
};

void PrintPoints(const std::vector<Point>& points)
{
    for (size_t i = 0; i < points.size(); i++) {
        printf("%f %f\n", points[i].x, points[i].y);
    }
}

std::vector<Point> ConvexHull(std::vector<Point>& points)
{
    std::vector<Point> convex_hull_set;

    // Sort the points base on y-coordinate, if there are ties
    // pick the minimum x-coordinate.
    std::sort(points.begin(), points.end(), CoordinateCmp);

    // Aside the first point, sort the remaining points base on its polar
    // angle relative to the first point.
    std::sort(points.begin() + 1, points.end(), CrossProductCmp(points[0]));

    PrintPoints(points);

    for (int i = 2; i < points.size(); i++) {
        printf("%f\n", Vect2D(points[0], points[i-1])
                .CrossProduct2D(Vect2D(points[0], points[i])).z);
    }
    return convex_hull_set;
}

int main()
{
    float x, y;
    std::vector<Point> points;
    while (scanf("%f %f", &x, &y) != EOF) {
       points.push_back(Point(x, y));
    }

    PrintPoints(ConvexHull(points));
    return 0;
}
