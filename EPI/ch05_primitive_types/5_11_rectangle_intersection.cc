/**
 * EPI Chapter 05 Primitive Types
 *
 * Rectangle Intersection
 *
 * Write a program which tests if 2 rectangles have a nonempty intersection.
 * If the intersection is nonempty, return the rectangle formed by their
 * intersection.
 *
 * Hint: Think of the X and Y dimensions independently.
 */

struct Point
{
    float x;
    float y;
};

struct Rect
{
    Point top_left;
    Point bottom_right;
};

Rect* get_intersection(const Rect& r1, const Rect& r2)
{
    Rect* intersection = nullptr;
    // Check for x dimension.
    //
    bool x_intersect = (r1.top_left.x <= r2.top_left.x && r2.top_left.x <= r1.bottom_right.x) ||
                        (r1.top_left.x <= r2.bottom_right.x && r2.bottom_right.x <= r1.bottom_right.x);

    // Check for y dimension.
    //
    bool y_intersect = (r1.top_left.y <= r2.top_left.y && r2.top_left.y <= r1.bottom_right.x) ||
                        (r1.top_left.y <= r2.bottom_right.y && r2.bottom_right.y <= r1.bottom_right.y);

    if (x_intersect && y_intersect) {
        intersection = new Rect();
        
        if (r1.top_left.x <= r2.top_left.x && r2.top_left.x <= r1.bottom_right.x) {
            intersection->top_left.x = r2.top_left.x;
        } else {
            intersection->bottom_right.x = r2.bottom_right.x;
        }

        if (r1.top_left.y <= r2.top_left.y && r2.top_left.y <= r1.bottom_right.x) {
            intersection->top_left.y = r2.top_left.y;
        } else {
            intersection->bottom_right.y = r2.bottom_right.y;
        }
    }
    return intersection;

}

int main()
{
    return 0;
}
