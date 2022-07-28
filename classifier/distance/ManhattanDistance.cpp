#include "ManhattanDistance .h"

double ManhattanDistance::distance(const Classified& v1, const Classified& v2) const {
    Classified diff = v1 - v2;
    return abs(diff.x()) + abs(diff.y()) + abs(diff.z()) + abs(diff.w());
}