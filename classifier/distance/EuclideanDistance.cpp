#include "EuclideanDistance.h"

double EuclideanDistance::distance(const Classified& v1, const Classified& v2) const {
    return (v1 - v2).len();
}